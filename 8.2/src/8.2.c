#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "utn.h"
#include "informes.h"

#define CANTIDAD_PANTALLAS 		100
#define CANTIDAD_CONTRATACIONES 1000

int main(void) {
#define CANTIDAD_PANTALLAS 		100
#define CANTIDAD_CONTRATACIONES 1000

//	Contratacion arraysContrataciones[CANTIDAD_CONTRATACIONES];
	Product arrayPantallas[CANTIDAD_PANTALLAS];
	int idPantallas=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;
	float respuesta;

	if(prod_inicializarArray(arrayPantallas,CANTIDAD_PANTALLAS) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}
	/*
	if(con_inicializarArray(arraysContrataciones,CANTIDAD_CONTRATACIONES) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}*/

	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar una pantalla"
							"\n2.Modificar una pantalla"
							"\n3.Eliminar una pantalla"
							"\n4.-Listar productos"
							"\n5.Listado ordenado por precio"
							"\n6.-Listado ordenado por descripcion"
							"\n7.Informes\n"
							"\n8.Salir",
							"\nError opcion invalida",1,7,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = prod_getEmptyIndex(arrayPantallas,CANTIDAD_PANTALLAS);
				if(auxiliarIndice >= 0)
				{
					if(prod_altaArray(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarIndice,&idPantallas) == 0)
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				prod_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a modificar","\nID invalido",0,idPantallas,5) == 0)
				{
					auxiliarIndice = prod_buscarId(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarId);
					if(	auxiliarIndice >= 0 &&
							prod_modificarArray(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				prod_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a eliminar","\nID invalido",0,idPantallas,5)==0)
				{
					auxiliarIndice = prod_buscarId(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarId);
					if(	auxiliarIndice >= 0 &&
							prod_bajaArray(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:
				prod_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);

				break;

			case 5:
				respuesta = OrdenaArrayInt(arrayPantallas, CANTIDAD_PANTALLAS);

//				if(respuesta > 0){
//					printf("\n %f" , respuesta);
//				}
				prod_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);
				break;

			case 6:
				respuesta = prod_ordenarPorDescripcion(arrayPantallas, CANTIDAD_PANTALLAS);
				prod_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);
				break;

			case 7:
				menu(arrayPantallas ,CANTIDAD_PANTALLAS);
				break;

			}
		}
	}while(opcion != 8);

	return EXIT_SUCCESS;
}

