#include <iostream>

float calcularPotencia(int a, int b){
    if (b == 0) {
        return 1; // Cualquier número elevado a la potencia 0 es 1
    } else if (b < 0) {
        return 1 / calcularPotencia(a, -b); // Manejo de exponentes negativos
    } else {
        return a * calcularPotencia(a, b - 1); // Caso general de recursividad
    }
}

int main(int argc, char** argv) {
int a,b,c;
printf("Ingrese la base:");
scanf("%d",&a);
printf("Ingrese el exponente:");
scanf("%d",&b);
calcularPotencia(a,b);
printf("El %d elevado a %d es: %f",a,b,calcularPotencia(a,b));
	return 0;
}
