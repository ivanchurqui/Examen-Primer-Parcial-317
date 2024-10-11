#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define TAM 10 // Cambié el tamaño para facilitar la impresión

// Función para imprimir un vector
void imprimirVec(int *vec, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vec[i]);
    
    printf("\n");
}

void main(int argc, char *argv[]) {
    int ran, tam, i;
    int *vec1, *vec2, suma = 0, sumaTotal = 0;

    // Inicializar MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &ran);
    MPI_Comm_size(MPI_COMM_WORLD, &tam);

    // Asignar memoria para los vectores
    vec1 = (int *)malloc(TAM * sizeof(int));
    vec2 = (int *)malloc(TAM * sizeof(int));

    // Inicializar los vectores solo en el proceso maestro
    if (ran == 0) {
        for (i = 0; i < TAM; i++) {
            vec1[i] = i + 1; // Inicializar vector1 con valores de 1 a 1
            vec2[i] = (i + 1) * 3; // Inicializar vector2 con valores de 3 a 3
        }
    }

    // Distribuir los vectores a todos los procesos
    MPI_Bcast(vec1, TAM, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(vec2, TAM, MPI_INT, 0, MPI_COMM_WORLD);

    // Calcular la suma de los elementos asignados a este proceso
    for (i = ran; i < TAM; i += tam) {
        suma += vec1[i] + vec2[i];
    }

    // Reducir resultados locales a la suma global
    MPI_Reduce(&suma, &sumaTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Imprimir resultados en el proceso maestro
    if (ran == 0) {
    printf("\tEJERCICIO 11 Suma De Vectores\n");
    printf("\t-----------------------------\n\n");
        printf("Vector 1:\n");
        imprimirVec(vec1, TAM);
        printf("Vector 2:\n");
        imprimirVec(vec2, TAM);
        printf("\nLa suma de los vectores es: %d\n", sumaTotal);
    }

    // Liberar memoria
    free(vec1);
    free(vec2);

    // Finalizar MPI
    MPI_Finalize();
    
}
