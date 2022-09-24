#include "calculos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initDatos(products apple[], int len) {
	int i;

	for (i = 0; i < len; i++) {
		apple[i].isEmpty = 0;
	}
}

void deleteDatos(products apple[], int len) {

	int retorno = -1;
	if (apple != NULL && len > 0) {

		apple[len].isEmpty = 0;
		retorno = 0;
	}

	return retorno;
}

int encontrarId(products apple[], int len, int IdProduct) {
	int i;
	int retorno = -1;
	for (i = 0; i < len; i++) {
		if (apple[i].idProduct == IdProduct) {
			retorno = i;
		}
	}
	return retorno;
}

void loadProduct(products apple[], int len) {

	int i;

	for (i = 0; i < len; i++) {

		apple[i].isEmpty = 0;

	}

	for (i = 0; i < len; i++) {

		if (apple[i].isEmpty == 0) {

			printf("Ingrese ID: \n");
			__fpurge(stdin);
			scanf("%d", &apple[i].idProduct);

			printf("Ingrese descripcion: \n");
			__fpurge(stdin);
			fgets(apple[i].description, 20, stdin);

			printf("Ingrese nacionalidad: \n");
			__fpurge(stdin);
			scanf("%d", &apple[i].nation);

			printf("Ingrese tipo: \n");
			scanf("%d", &apple[i].type);

			printf("Ingrese precio: \n");
			__fpurge(stdin);
			scanf("%f", &apple[i].price);

			apple[i].isEmpty = 1;
			break;
		} else {
			printf("No se puede cargar mas productos");
		}
	}
	for (i = 0; i < 2; i++) {
		printf(
				"id %d, descripcion %s, nacionalidad %d, tipo %d, precio %.2f \n",
				apple[i].idProduct, apple[i].description, apple[i].nation,
				apple[i].type, apple[i].price);
	}

}

//void eliminarProducto(void){
//
//}
