#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "salida_datos.h"
#include "Jugador.h"
#include "Confederacion.h"
#include "Validaciones.h"



void HardcodeoConfederacion(eConfederacion arrayConfederacion[], int limiteConfedracion) {
	if (arrayConfederacion != NULL && limiteConfedracion > 0) {

		arrayConfederacion[0].id = 100;
		strncpy(arrayConfederacion[0].nombre, "CONMEBOL", 30);
		strncpy(arrayConfederacion[0].region, "SUDAMERICA", 30);
		arrayConfederacion[0].anioCreacion = 1916;


		arrayConfederacion[1].id = 101;
		strncpy(arrayConfederacion[1].nombre, "UEFA", 30);
		strncpy(arrayConfederacion[1].region, "EUROPA", 30);
		arrayConfederacion[1].anioCreacion = 1954;


		arrayConfederacion[2].id = 102;
		strncpy(arrayConfederacion[2].nombre, "AFC", 30);
		strncpy(arrayConfederacion[2].region, "ASIA", 30);
		arrayConfederacion[2].anioCreacion = 1954;


		arrayConfederacion[3].id = 103;
		strncpy(arrayConfederacion[3].nombre, "CAF", 30);
		strncpy(arrayConfederacion[3].region, "AFRICA", 30);
		arrayConfederacion[3].anioCreacion = 1957;


		arrayConfederacion[4].id = 104;
		strncpy(arrayConfederacion[4].nombre, "CONCACAF", 30);
		strncpy(arrayConfederacion[4].region, "NORTE Y CENTRO AMERICA", 30);
		arrayConfederacion[4].anioCreacion = 1961;


		arrayConfederacion[5].id = 105;
		strncpy(arrayConfederacion[5].nombre, "OFC", 30);
		strncpy(arrayConfederacion[5].region, "OCEANIA", 30);
		arrayConfederacion[5].anioCreacion = 1966;


	}
}


/**
 * \brief Pide un ID y lo retorna
 * \param arrayTipo Array de tipos
 * \param limiteTipo Limite del array de tipos
 * \return Retorna el ID ingresado
 *
 */
int pedirConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int opcion;

	if(arrayConfederacion != NULL && limiteConfederacion > 0)
	{

		mostrarConfederaciones(arrayConfederacion, limiteConfederacion);

		utn_getNumero(&opcion, "\nElija el ID del tipo que quiera ingresar","error", 100, 105, 3);

	}
	return opcion;
}

/**
 * \brief Muestra todos los tipos hardcodeados
 * \param arrayTipo Array de tipos
 * \param limiteTipo Limite del array de tipos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int mostrarConfederaciones(eConfederacion arrayConfederacion[], int limiteConfederacion) {
	int i;
	int retorno = -1;

	if (arrayConfederacion != NULL && limiteConfederacion > 0) {
		retorno = 0;
		printf(" id    descripcion");
		for (i = 0; i < limiteConfederacion; i++) {
			printf("\n%d   %s  %s   %d", arrayConfederacion[i].id, arrayConfederacion[i].nombre, arrayConfederacion[i].region, arrayConfederacion[i].anioCreacion);
		}
	}
	return retorno;
}




int buscarFederacion(eConfederacion arrayConfederacion[], int limiteConfederacion, int idConfederacion, char *pConfederacion )
{
	int retorno = -1;
	int i;

	if(arrayConfederacion != NULL && limiteConfederacion > 0 && idConfederacion > 0 && pConfederacion != NULL)
	{
		for(i = 0; i < limiteConfederacion; i++)
		{
			if(arrayConfederacion[i].id == idConfederacion)
			{
				strncpy(pConfederacion, arrayConfederacion[i].nombre, 50);
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}




int buscarRegion(eConfederacion arrayConfederacion[], int limiteConfederacion, int idConfederacion, char *pConfederacion )
{
	int retorno = -1;
	int i;

	if(arrayConfederacion != NULL && limiteConfederacion > 0 && idConfederacion > 0 && pConfederacion != NULL)
	{
		for(i = 0; i < limiteConfederacion; i++)
		{
			if(arrayConfederacion[i].id == idConfederacion)
			{
				strncpy(pConfederacion, arrayConfederacion[i].region, 50);
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
