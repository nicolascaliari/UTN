
/*
 ============================================================================
 Name        : pruebaLibreria.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int main(void) {

	char operador;
	int numeroUno;
	int numeroDos;
	int respuesta;
	int resultado;

	printf("Ingrese el primer numero: ");
	scanf("%d", &numeroUno);
	__fpurge(stdin);

	printf("Elija el operador: ");
	scanf("%c", &operador);
	__fpurge(stdin);

	printf("Ingrese el segundo numero: ");
	scanf("%d", &numeroDos);
	__fpurge(stdin);

	switch (operador) {
	case '/':
		respuesta = calcularDivisiones(numeroUno, numeroDos, &resultado);
		if (respuesta == 0) {
			printf("%d", resultado);
		} else {
			printf("No se puede dividir por cero \n");
		}
		break;

	case '+':
		respuesta = calcularSuma(numeroUno, numeroDos, &resultado);
		break;

	case '-':
		respuesta = calcularResta(numeroUno, numeroDos, &resultado);
		break;

	case '*':
		respuesta = calcularMultiplicacion(numeroUno, numeroDos, &resultado);
		break;
	}

//	printf("%d", resultado);
	return EXIT_SUCCESS;
}
