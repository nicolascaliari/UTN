#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacion.h"

void loadProduct(apple products[]) {

	int i;

	for (i = 0; i < 2; i++) {

		products[i].isEmpty = 0;

	}

	for (i = 0; i < 2; i++) {

		if (products[i].isEmpty == 0) {

			printf("Ingrese ID: \n");
			__fpurge(stdin);
			scanf("%d", &products[i].idProduct);

			printf("Ingrese descripcion: \n");
			__fpurge(stdin);
			fgets(products[i].description, 20, stdin);

			printf("Ingrese nacionalidad: \n");
			__fpurge(stdin);
			scanf("%d", &products[i].nation);

			printf("Ingrese tipo: \n");
			scanf("%d", &products[i].type);

			printf("Ingrese precio: \n");
			__fpurge(stdin);
			scanf("%f", &products[i].price);

			products[i].isEmpty = 1;
			break;
		} else {
			printf("No se puede cargar mas productos");
		}
	}
	for (i = 0; i < 2; i++) {
		printf(
				"id %d, descripcion %s, nacionalidad %d, tipo %d, precio %.2f \n",
				products[i].idProduct, products[i].description,
				products[i].nation, products[i].type, products[i].price);
	}

}

//void eliminarProducto(void){
//
//}
