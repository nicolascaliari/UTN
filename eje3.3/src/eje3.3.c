/*
 ============================================================================
 Name        : 3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int resultado;

	resultado = retornarEntero();

	printf("El retorno es %d", resultado);


	return EXIT_SUCCESS;
}



int retornarEntero(void){
	int ingresarEntero;

	printf("Ingrese un entero: ");
	scanf("%d", &ingresarEntero);

	return ingresarEntero;
}
