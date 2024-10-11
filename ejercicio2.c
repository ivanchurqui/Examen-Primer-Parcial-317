#include <stdio.h>

float suma(float a, float b) {
    return a + b;
}

float resta(float a, float b) {
    return a - b;
}

float multiplicacion(float a, float b) {
    return a * b;
}

float division(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: División por cero\n");
        return 0;//Retorna 0
    }
}

void main() {
    float n1, n2;
    printf("\tEJERCICIO 2 Calculadora Sin Punteros\n");
    printf("\t------------------------------------\n\n");
    printf("Ingrese el primer número : ");
    scanf("%f", &n1);
    printf("Ingrese el segundo número: ");
    scanf("%f", &n2);

    printf("Suma          : %.0f + %.0f = %.0f\n", n1, n2, suma(n1, n2));
    printf("Resta         : %.0f - %.0f = %.0f\n", n1, n2, resta(n1, n2));
    printf("Multiplicación: %.0f * %.0f = %.0f\n", n1, n2, multiplicacion(n1, n2));
    printf("División      : %.0f / %.0f = %.2f\n", n1, n2, division(n1, n2));
}

