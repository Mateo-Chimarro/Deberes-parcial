#include <iostream>
#include <stdio.h>

int division(int dividendo, int divisor) {
    if (dividendo < divisor) {
        return 0; // Caso base: el dividendo es menor que el divisor
    } else {
        return 1 + division(dividendo - divisor, divisor); // Resta recursiva y suma contador
    }
}

int main() {
    int dividendo, divisor;

    printf("Ingrese el dividendo: ");
    scanf("%d", &dividendo);

    printf("Ingrese el divisor: ");
    scanf("%d", &divisor);

    if (divisor == 0) {
        printf("Error: No se puede dividir por cero.\n");
    } else {
        int result = division(dividendo, divisor);
        printf("Resultado: %d\n", result);
    }

    return 0;
}

