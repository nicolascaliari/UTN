#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "utn.h"


Cliente* cli_new(void)
{
	Cliente* p;

	p = (Cliente*)malloc(sizeof(Cliente)*1);
	if(p != NULL)
	{
		p->idCliente=0;
		p->nombre[0]='\0';
		p->apellido[0]='\0';
		return p;
	}
	else
	{
		return NULL;
	}
}


int init_arrayPunteros(Cliente* array[], int limite)
{
	int i;
	int retorno = -1;
	if (array != NULL && limite > 0)
	{
		retorno =0;
		for (i = 0; i < limite; i++)
		{
			array[i] = NULL;
		}
	}
	return retorno;
}




int pan_altaArray(Cliente* array[],int limite, int indice, int* id)
{
	int respuesta = -1;
	Cliente bufferPantalla;
	Cliente* pc;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferPantalla.nombre,50,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getDescripcion(bufferPantalla.apellido,50,"\nDireccion?\n","\nERROR\n",2) == 0)
		{
			bufferPantalla.idCliente = *id;
			pc = cli_new();
			if(pc != NULL){
				*pc = bufferPantalla;
				array[indice] = pc;

				(*id)++;
				respuesta = 0;
			}
		}
	}
	return respuesta;
}

int borrarArray(Cliente* array[], int limite)
{
	int retorno = -1;
	int indice;
	int id;

	if(array != NULL && limite > 0)
	{
		printf("INgrese el id que quiere eliminar");
		scanf("%d", &id);
		indice = buscarId(array, limite,id);

		retorno =0;
		free(array[indice]);
		array[indice] = NULL;
	}
	return retorno;
}


int imprimir_alumno(Cliente* array[], int limite)
{
	int retorno=-1;
	int i;

	for(i=0; i<limite; i++)
	{
		if(array[i] != NULL)
		{
			printf("\nNombre:%s  - apellido:%s", array[i]->nombre, array[i]->apellido);
		}
	}
	return retorno;
}





int buscarEspacioLibre(Cliente* array[], int limite) {
	int i;
	int retorno = -1;
	if (array != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			if (array[i] == NULL) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}



int buscarId(Cliente* array[], int limite, int id)
{
	int retorno = -1;
	int i;
	if(array != NULL && limite > 0 && id >= 0)
	{
		for(i=0 ; i < limite ; i++)
		{
			if(array[i] != NULL && array[i]->idCliente == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
