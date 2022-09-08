/*
 ============================================================================
 Name        : 1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int nuevaFuncion(int numeroPar, int * respuesta);

int main(void) {
	setbuf(stdout , NULL);
	int ingresarNumero;
	int resultado;
	int respuesta;

	printf("Ingrese un numero: ");
	scanf("%d" , &ingresarNumero);

	resultado = nuevaFuncion(ingresarNumero , &respuesta);
	printf("%d", respuesta);

	return 0;
}


int nuevaFuncion(int numeroPar, int * respuesta){
int retorno = 0;

	if(numeroPar%2 == 0){
		*respuesta = 1;
	}else {
		*respuesta = 0;
	}

	return retorno;
}
