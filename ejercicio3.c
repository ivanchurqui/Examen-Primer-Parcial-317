#include <stdio.h>

void suma(float a, float b, float *r) {
    *r = a + b;
}

void resta(float a, float b, float *r) {
    *r = a - b;
}

void multiplicacion(float a, float b, float *r) {
    *r = a * b;
}

void division(float a, float b, float *r) {
    if (b != 0) {
        *r = a / b;
    } else {
        printf("Error: División por cero\n");
        *r = 0; // Retorna 0
    }
}

void main() {
    float n1, n2, r;

    printf("\tEJERCICIO 3 Calculadora Con Punteros\n");
    printf("\t------------------------------------\n\n");
    printf("Ingrese el primer número : ");
    scanf("%f", &n1);
    printf("Ingrese el segundo número: ");
    scanf("%f", &n2);

    suma(n1, n2, &r);
    printf("Suma          : %.0f + %.0f = %.0f\n", n1, n2, r);
    //printf("Suma: %.2f\n", r);

    resta(n1, n2, &r);
    printf("Resta         : %.0f - %.0f = %.0f\n", n1, n2, r);
    //printf("Resta: %.2f\n", r);

    multiplicacion(n1, n2, &r);
    printf("Multiplicación: %.0f * %.0f = %.0f\n", n1, n2, r);
    //printf("Multiplicación: %.2f\n", r);

    division(n1, n2, &r);
    printf("División      : %.0f / %.0f = %.2f\n", n1, n2, r);
    //printf("División: %.2f\n", r);

}

