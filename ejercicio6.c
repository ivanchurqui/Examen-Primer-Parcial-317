#include <stdio.h>

#define MAXIMO 50//93 termino maximo que soporta long

void calculoFibonacci(long long *f, int n) {
    if (n >= 1) f[0] = 0; 
    if (n >= 2) f[1] = 1; 
    
    for (int i = 2; i < n; i++)
        f[i] = f[i - 1] + f[i - 2]; 
}

void main() {
    int n;
    long long fibo[MAXIMO]; // Vector de términos Fibonacci

    printf("\tEJERCICIO 6 Algoritmo De Fibonacci\n");
    printf("\t----------------------------------\n\n");
    printf("Ingrese número de términos de la serie de Fibonacci (entre 1 a %d): ", MAXIMO);
    scanf("%d", &n);

    if (n > MAXIMO || n < 1) {
        printf("Por favor, ingrese un número entre 1 y %d.\n", MAXIMO);
    }
    else {
    	calculoFibonacci(fibo, n);

    	printf("Los primeros %d términos de la serie de Fibonacci son:\n\n", n);
    	for (int i = 0; i < n; i++)
        	printf("Termino[%d] = %lld\n", (i + 1), fibo[i]);
    	
    }
    

}
