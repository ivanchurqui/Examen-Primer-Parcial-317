#include <stdio.h>
#include <omp.h>

void fibonacci(int n) {
    int fib[n];  // Array para almacenar los números de Fibonacci

    // Inicializar los primeros dos números de Fibonacci
    if (n > 0) fib[0] = 0;  // Primer termino
    if (n > 1) fib[1] = 1;  // Segundo termino

    // Calcular la serie de Fibonacci en paralelo
    #pragma omp parallel shared(fib) 
    {
        // Solo un hilo se encarga de la inicialización de los primeros dos elementos
        #pragma omp single
        {
            for (int i = 2; i < n; i++) 
                // Calcular el siguiente número de Fibonacci
                fib[i] = fib[i - 1] + fib[i - 2];
          
        }

        // Esperar a que el cálculo esté completo
        #pragma omp barrier

        // Desplegar los resultados (solo un hilo lo hace)
        #pragma omp single
        {
            printf("Serie de Fibonacci hasta el término %d:\n", n);
            for (int i = 0; i < n; i++) 
                printf("Termino[%d] = %d\n", (i + 1), fib[i]);
            
            printf("\n");
        }
    }
}

int main() {
    int n;

    printf("\tEJERCICIO 12 OPENMP Fibonacci\n");
    printf("\t-----------------------------\n\n");

    // Definir el número de términos de la serie Fibonacci
    printf("Ingrese el número de términos de Fibonacci: ");
    scanf("%d", &n);

    // Asegurarse de que n sea al menos 1 para evitar errores
    if (n < 1) {
        printf("El número de términos debe ser al menos 1.\n");
        return 1;
    }

    // Calcular y desplegar la serie de Fibonacci
    fibonacci(n);

    return 0;
}
