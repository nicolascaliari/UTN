#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculos.h"
#include "utn.h"

void menu(Product *array, int limite) {

	int opcion;
	do {
		if (!utn_getNumero(&opcion,
				"\n\n1.Productos mas caros"
				"\n2.Productos de mas de 700 pesos"
				"\n7.Iphone mas barato\n\n"
				, "\nError opcion invalida", 1, 7,
				2)) {
			switch (opcion) {
			case 1:

				break;
			case 2:
				prod_imprimirArrayInformes(array, 20);
				break;
			}
		}
	} while (opcion != 8);
}

int prod_imprimirInformes(Product *pElemento) {
	int retorno = -1;
	if (pElemento != NULL && pElemento->isEmpty == 0) {
		retorno = 0;
		printf("\nID: %d - %s - %s - %.2f", pElemento->id, pElemento->nombre,
				pElemento->descripcion, pElemento->precio);
	}
	return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_imprimirArrayInformes(Product *array, int limite) {
	int respuesta = -1;
	int i;
	if (array != NULL && limite > 0) {
		respuesta = 0;
		for (i = 0; i < limite; i++) {
			if (array[i].precio > 700) {

				prod_imprimir(&array[i]);
			}
		}
	}
	return respuesta;
}
//int InformarMasSetecientos(){
//
//}
//
//int IphoneMasBarato(){
//
//}
//
//int MacMasSetecientos(){
//
//}
//
//int AccesoriosMasCaros(){
//
//}
