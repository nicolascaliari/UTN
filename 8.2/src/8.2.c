/*
 ============================================================================
 Name        : 2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacion.h"




int main(void) {
	apple products[2];
	int option = 0;

	do{


	printf("\n Por favor, ingrese un numero \n \n "
			"\n 1-ALTA Producto:"
			"\n 2-BAJA Producto: "
			"\n 3-MODIFICACIÓN Producto: "
			"\n 4-LISTADO Productos. "
			"\n 5-LISTADO ordenado por precio. "
			"\n 6-LISTADO ordenado por descripción. "
			"\n \n  7-EXIT: \n");
	scanf("%d", &option);

	switch (option) {
	case 1:
		printf("\n Selecciono ALTA Producto: \n \n");


		loadProduct(products);
		break;
	case 2:
		printf("\n \n Selecciono BAJA Producto:  \n \n");

		break;
	case 3:
		printf("\n \n Selecciono MODIFICACIÓN Producto: \n \n");

		break;
	case 4:
		printf("\n \n Selecciono LISTADO Productos. \n \n");

		break;
	case 5:
		printf("\n \n Selecciono LISTADO ordenado por precio. \n \n");
		fflush(stdin);
		break;
	case 6:
		printf("\n \n Selecciono LISTADO ordenado por descripción. \n \n");
		fflush(stdin);
		break;
	}
	}while(option != 7);
	return EXIT_SUCCESS;
}
