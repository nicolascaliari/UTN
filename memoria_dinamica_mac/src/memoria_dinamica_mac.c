/*
 ============================================================================
 Name        : memoria_dinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "utn.h"
#define CANTIDAD_CLIENTES 100

//int initArray(int* pArray, int limite, int valor){
//	int retorno = -1;
//	int i;
//
//	if(pArray != NULL && limite > 0)
//	{
//		retorno = 0;
//		for(i=0; i < limite; i++)
//		{
//		*(pArray + 1) = valor;
//		}
//	}
//	return retorno;
//}
//
//
//
//int imprimirArray(int* pArray, int limite)
//{
//	int retorno = -1;
//	int i;
//	if(pArray != NULL && limite > 0)
//	{
//		retorno = 0;
//
//		for(i=0; i < limite; i++)
//		{
//			printf("\nValor:%d",*(pArray + i) );
//		}
//	}
//return retorno;
//}
//
//
//int resizeArray(int** pArray, int* sizeActual, int sizeNuevo){
//	 int* pArrayNuevo = NULL;
//	 int retorno = -1;
//
//	 if(pArray != NULL && sizeActual != NULL && sizeNuevo >= 0)
//
//
//	 pArrayNuevo = (int*)realloc(*pArray, sizeof(int) * sizeNuevo);
//
//		  if(pArrayNuevo != NULL)
//		  {
//			  *sizeActual = sizeNuevo;
//			  *pArray = pArrayNuevo;
//			  pArrayNuevo = NULL;
//			  retorno = 0;
//		  }
//	return retorno;
//}



int main(void) {

	Cliente* pc;
	Cliente* punterosClientes[CANTIDAD_CLIENTES];
	init_arrayPunteros(punterosClientes, CANTIDAD_CLIENTES);

int opcion;
int aux;
int id = 0;

do {
		if (utn_getNumero(&opcion, "\n         Bienvenido al menu\n"
				"\n1-Alta de jugador"
				"\n2-Baja de jugador"
				"\n3-Modificacion de jugador"
				"\n4-Informes"
				"\n5-Salir", "\nError, solo puede ingresar del 1 al 5", 1, 5, 2)
				== 0) {

			switch (opcion)
			{
			case 1:
				aux = buscarEspacioLibre(punterosClientes, CANTIDAD_CLIENTES);

				if(aux >= 0)
				{
					pc = cli_new();
					if(pc != NULL)
					{
						pan_altaArray(punterosClientes, CANTIDAD_CLIENTES, aux, &id);
						imprimir_alumno(punterosClientes, CANTIDAD_CLIENTES);
					}
				}

				break;
			case 2:
				borrarArray(punterosClientes, CANTIDAD_CLIENTES);
				imprimir_alumno(punterosClientes, CANTIDAD_CLIENTES);

				break;
			}

		}

	} while (opcion != 5);




















//  int* pArray = NULL;
//  int sizeArray = 10;
//
//  pArray = (int*) malloc(sizeof(int)* sizeArray); // malloc recibe la cantidad de bites que quiero reservar
//
//  if(pArray != NULL){
//
//	  if(initArray(pArray, sizeArray, 0) == 0){
//
//		  imprimirArray(pArray, sizeArray);
//	  }
//
//	if(resizeArray(&pArray, &sizeArray , 20) == 0){
//		printf("OK");
//		 imprimirArray(pArray, sizeArray);
//	}
//
//  }

	return EXIT_SUCCESS;
}
