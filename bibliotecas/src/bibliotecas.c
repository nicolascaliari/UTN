/*
 ============================================================================
 Name        : bibliotecas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void) {
	int numero;
	int resultado;



	resultado = pedirDatosNumericos(&numero, "Ingrese un numero", "esta todo mal", 5, 40,2);
	if(resultado == 0){
		printf("%d", numero);
	}else {
		printf("error");
	}


	return EXIT_SUCCESS;
}
