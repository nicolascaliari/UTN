#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculos.h"
#include "utn.h"


/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_imprimir(Product* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %s - %.2f",pElemento->id,pElemento->nombre,pElemento->descripcion,pElemento->precio);
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
int prod_imprimirArray(Product* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			prod_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_inicializarArray(Product* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_altaArray(Product* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Product bufferPantalla;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferPantalla.nombre,NOMBRE_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getDescripcion(bufferPantalla.descripcion,DESCRIPCION,"\nDescripcion?\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferPantalla.precio,"\nPrecio?\n","\nERROR\n",0,10000,2) == 0) //&&
//			utn_getNumero(&bufferPantalla.tipo,"Ingrese tipo [0:LCD 1:LED]:","No!",0,1,2)==0)
		{
			respuesta = 0;
			bufferPantalla.id = *id;
			bufferPantalla.isEmpty = 0;
			array[indice] = bufferPantalla;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_modificarArray(Product* array,int limite, int indice)
{
	int respuesta = -1;
	Product bufferProduct;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(bufferProduct.nombre,NOMBRE_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getDescripcion(bufferProduct.descripcion,DESCRIPCION,"\nDescripcion?\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferProduct.precio,"\nPrecio?\n","\nERROR\n",0,10000,2) == 0) //&&
//			utn_getNumero(&bufferPantalla.tipo,"Ingrese tipo [0:LCD 1:LED]:","No!",0,1,2)==0)
		{
			respuesta = 0;
			bufferProduct.id = array[indice].id;
			bufferProduct.isEmpty = 0;
			array[indice] = bufferProduct;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_bajaArray(Product* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prod_buscarId(Product array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int prod_getEmptyIndex(Product* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Ordenar el array de clientes por nombre
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int prod_ordenarPorDescripcion(Product* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Product buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].descripcion,array[i+1].descripcion,NOMBRE_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}


int OrdenaArrayInt(Product* array,int limite)
{
   int flagSwap;
   int i;
   int contador = 0;
   int retorno = -1;
   Product buffer;

   if(array != NULL && limite > 0){
	   do{
		   flagSwap=0;
		   for(i=0; i<limite-1;i++){
			   if(array[i].precio < array[i+1].precio){
				   flagSwap = 1;
				   buffer = array[i];
				   array[i] = array[i+1];
				   array[i+1] = buffer;
			   }
			   contador++;
		   }
	   }while(flagSwap);
	   retorno = contador;
   }
   return retorno;
}


