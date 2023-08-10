#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//declaracion de prototipos

void Mayus(char cad[]);
void Minus(char cad[]);
void Minus_Mayus(char cad[], int tam);
void imprimirYGuardar(char *cadena, FILE *archivo) ;

//declaracion de funciones

//Funcion para transformar una cadena a Mayusculas

void Mayus(char cad[]){
	int i=0;
	while(cad[i]='\0'){	
		
		if(cad[i]>='a' && cad[i]<='z'){
			cad[i]=cad[i] - ('a'-'A');	
		}
		i++;
	}		
}

//Funcion para transformar una cadena a Minusculas

void Minus(char cad[]){
	int i=0;
	while(cad[i]='\0'){	
		
		if(cad[i]>='A' && cad[i]<='Z'){
			cad[i]=cad[i] + ('a'-'A');	
		}
		i++;
	}		
}
//Funcion para transformar una cadena a Minusculas y Mayusculas

void Minus_Mayus(char cad[], int tam){
	int i=0;
	for(int j=0; j<tam; j++){
		
		if(j%2==0){
			
            cad[i] = cad[i] - ('a' - 'A');
			
		}
		i++;
	}
	
}

//Funcion para imprimir en el archivo

void imprimirYGuardar(char *cadena, FILE *archivo) {
    fprintf(archivo, "La cadena ingresada es: %s\n", cadena);
    Mayus(cadena);
    fprintf(archivo, "La cadena ingresada en mayusculas es: %s\n", cadena);
    Minus(cadena);
    fprintf(archivo, "La cadena ingresada en minusculas es: %s\n", cadena);
    Minus_Mayus(cadena, strlen(cadena)); 
    fprintf(archivo, "La cadena alternada en mayusculas y minusculas es: %s\n", cadena);
    fprintf(archivo, "\n");
}

int main(int argc, char** argv) {
   char cadena[50];
    printf("Ingrese una cadena: ");
    fgets(cadena, 50, stdin);

    FILE *archivo = fopen("cadenas.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    imprimirYGuardar(cadena, archivo);

    fclose(archivo);
    printf("La cadena se ha guardado en el archivo.\n");

    return 0;
}
