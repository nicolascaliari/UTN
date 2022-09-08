/*
 ============================================================================
 Name        : segundaClaseSabado.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"


int pedirEntero(void);
int main(void) {
int resultadoEntero;
int resultadoPromedio;
int resultadoVerificarEntero;
int resultadoDiezNumeros;
int retorno;

resultadoEntero = pedirEntero();
resultadoPromedio = calcularPromedio(20, 30);

resultadoVerificarEntero = verificarRetorno(4);
resultadoDiezNumeros = ingresarDiezNumeros();

if(resultadoVerificarEntero > 0){
	retorno = 1;
}else{
	if(resultadoVerificarEntero < 0){
		retorno = -1;
	}else {
		retorno = 0;
	}
}


printf("\n %d", resultadoEntero);
printf("\n %d" , resultadoPromedio);
printf("\n %d", retorno);
printf("\n %d", resultadoDiezNumeros);

	return EXIT_SUCCESS;
}



