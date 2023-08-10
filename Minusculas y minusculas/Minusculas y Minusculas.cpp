#include <iostream>
#include <conio.h>
#include <stdio.h>

//declaracion de prototipos


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

int main(int argc, char** argv) {

	
	
	return 0;
}
