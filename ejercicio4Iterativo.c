#include <stdio.h>

void piIterativo(double *res, int n) {
    double pi = 0.0;
    for (int i = 0; i < n; i++) 
        pi += (i % 2 == 0 ? 1.0 : -1.0) / (2.0 * i + 1.0);
    
    *res = pi * 4.0; // Multiplicar por 4 para obtener pi
}

void main() {
    double pi;
    int n; 
    
    printf("\tEJERCICIO 4 Calculo de PI Iterativo\n");
    printf("\t-----------------------------------\n\n");
    printf("Ingrese numero (Recomendado n>999): ");
    scanf("%d", &n);
    
    piIterativo(&pi, n);
    printf("Valor de PI aproximado (iterativo): %.15f\n", pi);
}
