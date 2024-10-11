#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4 // Tamaño de las matrices

/*Procedimiento multipicar matrices*/
void multiplicarMatrices(double A[N][N], double B[N][N], double C[N][N], int ran, int tam) {

    int filaPro = N / tam; // Filas que procesará cada proceso
    double filaVec[N];     // Fila temporal para cada proceso

    // Cada proceso recibe su parte de la matriz A
    MPI_Scatter(A, filaPro * N, MPI_DOUBLE, filaVec, filaPro * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Cada proceso calcula su parte de la matriz C
    for (int i = 0; i < filaPro; i++)
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
                C[i][j] += filaVec[i * N + k] * B[k][j];
        }

    // Recolecta las filas calculadas en el proceso maestro
    MPI_Gather(C, filaPro * N, MPI_DOUBLE, C, filaPro * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    
}

/*Procedimiento imprimir matriz*/
void imprimirMatriz(double M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.0f ", M[i][j]);
        }
        printf("\n");
    }
}

void main(int argc, char *argv[]) {
    int ran, tam, i, j;
    double A[N][N], B[N][N], C[N][N];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &ran);
    MPI_Comm_size(MPI_COMM_WORLD, &tam);

    if (tam > N) {
        if (ran == 0)
            printf("El número de procesos no puede ser mayor que el tamaño de la matriz.\n");
        
    }
    else {
        // Inicialización de matrices solo en el proceso 0
        if (ran == 0) {
            // Matriz A
            for (i = 0; i < N; i++)
                for (j = 0; j < N; j++) 
                    A[i][j] = i + j; // Ejemplo de inicialización
            
            // Matriz B
            for (i = 0; i < N; i++) 
                for (j = 0; j < N; j++) 
                    B[i][j] = i - j; // Ejemplo de inicialización
         
            printf("\tEJERCICIO 14 Multiplicacion de Matrices\n");
            printf("\t---------------------------------------\n\n");        
            printf("Resultado de la matriz A:\n");
            imprimirMatriz(A);  
        
            printf("Resultado de la matriz B:\n");
            imprimirMatriz(B);     
           
        }

        // Broadcast de la matriz B a todos los procesos
        MPI_Bcast(B, N * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        // Multiplicación de matrices
        multiplicarMatrices(A, B, C, ran, tam);

        // Imprimir resultado solo en el proceso 0
        if (ran == 0) {
            printf("Resultado de la multiplicación de la Matriz C:\n");
            imprimirMatriz(C);
        }
    }
    

    MPI_Finalize();
    
}
