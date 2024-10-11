#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_VECTOR 10
#define TAM_CADENA 20

void main(int argc, char *argv[]) {

    //printf("\tEJERCICIO 13 MPI Procesadores\n");
    //printf("\t-----------------------------\n\n");
    int rango, tamanio, i;
    char vec[TAM_VECTOR][TAM_CADENA]; // Vector de cadenas
    char cad[TAM_CADENA]; // Cadena recibida

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rango);
    MPI_Comm_size(MPI_COMM_WORLD, &tamanio);

    if (tamanio != 3) {
        if (rango == 0) 
            fprintf(stderr, "Este programa requiere 3 procesos.\n");
        //MPI_Finalize();//r1;
    }
    else {
        /*rango = 0: Inicializa el vector y lo distribuye
	rango = 1: Recibe las cadenas en posiciones pares
	rango = 2: Recibe las cadenas en posiciones impares*/
    	// Proceso 0 inicializa el vector
	if (rango == 0) {
	    for (i = 0; i < TAM_VECTOR; i++) 
		sprintf(vec[i], "Cadena %d", i);
	}

	// El proceso 0 distribuye las cadenas
	for (i = 0; i < TAM_VECTOR; i++) {
	    if (rango == 0) {
		// Enviar a los procesos 1 y 2 según la paridad
		if (i % 2 == 0)
		    MPI_Send(vec[i], TAM_CADENA, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
		else
		    MPI_Send(vec[i], TAM_CADENA, MPI_CHAR, 2, 0, MPI_COMM_WORLD);
	    }
	}
        
	// Procesos 1 y 2 reciben las cadenas
	if (rango == 1 || rango == 2) {
	    for (i = 0; i < TAM_VECTOR/ 2; i++) {
		MPI_Recv(cad, TAM_CADENA, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Proceso %d recibe: %s\n", rango, cad);
	    }
	}
    }
    

    MPI_Finalize();
    
}
