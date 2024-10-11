#include <stdio.h>

void piRecursivo(double *res, int n, int i, double pi) {
    if (i >= n) {
        *res = pi * 4.0; // Multiplicar por 4 para obtener pi
        return;
    }
    pi += (i % 2 == 0 ? 1.0 : -1.0) / (2.0 * i + 1.0);
    piRecursivo(res, n, i + 1, pi);
}

void main() {
    double pi;
    int n; 
    
    printf("\tEJERCICIO 4 Calculo de PI Recursivo\n");
    printf("\t-----------------------------------\n\n");
    printf("Ingrese numero (Recomendado n>999): ");
    scanf("%d", &n);
    
    piRecursivo(&pi, n, 0, 0.0);
    printf("Valor de PI aproximado (Recursivo): %.15f\n", pi);
}
