#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "informes.h"
#include "jugador.h"
#include "confederacion.h"
#include <string.h>

void menuInformes(eJugador arrayJugador[], int limiteJugador, eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int opcion;

	do
	{
		if (utn_getNumero(&opcion,
				"\n         Bienvenido al menu de informes\n"
						"\n1-Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador."
						"\n2-Listado de confederaciones con sus jugadores."
						"\n3-Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio."
						"\n4-Informar la confederación con mayor cantidad de años de contratos total."
						"\n5.Informar porcentaje de jugadores por cada confederación."
						"\n6.Informar cual es la región con más jugadores y el listado de los mismos."
						"\n7-Salir", "\nError, solo puede ingresar del 1 al 5",1, 7, 2) == 0)
		{

			switch (opcion)
			{
			case 1:
				recurso_ordenarPorIdDescripcion(arrayConfederacion, arrayJugador, limiteConfederacion, limiteJugador);
				jugador_imprimirArray(arrayJugador, limiteJugador, arrayConfederacion, limiteConfederacion);
				break;
			case 2:
				jugador_imprimirArray_informes(arrayJugador, limiteJugador, arrayConfederacion, limiteConfederacion);
				break;
			case 3:
				totalyPromedioSalarios(arrayJugador, limiteJugador);
				break;
			case 4:
				confederaciónMayorAñosContratosTotal(arrayJugador, limiteJugador);
				break;
			case 5:
				break;
			case 6:
				break;
			}

		}

	} while (opcion != 5);
}

void recurso_ordenarPorIdDescripcion(eConfederacion arrayConfederacion[],eJugador arrayJugador[], int limiteConfederacion, int limiteJugador)
{
	int i;
	int j;
	int bandera;
	eJugador auxJugador;


	if (arrayConfederacion != NULL && limiteConfederacion > 0 && arrayJugador != NULL && limiteJugador > 0)
	{

		do {
			bandera = 0;
			for( j = 0; j < limiteJugador -1 ; j++)
			{
				for (i = 0; i < limiteConfederacion -1 ; i++)
				{


//				 if(arrayJugador[i].isEmpty || arrayJugador[i+1].isEmpty)
//				 {
//				 continue;
//				 }
				 if(strncmp(arrayConfederacion[i].nombre,arrayConfederacion[i+1].nombre,30) < 0)
				 {
				 bandera = 1;
				 auxJugador = arrayJugador[j];
				 arrayJugador[j] = arrayJugador[j+1];
				 arrayJugador[j+1]=auxJugador;
				 }
				 else if(strncmp(arrayConfederacion[i].nombre,arrayConfederacion[i+1].nombre,30) == 0)
				 {
				 if(strncmp(arrayJugador[j].nombre,arrayJugador[j+1].nombre,30) > 0)
				 {
				 bandera = 1;
				 auxJugador = arrayJugador[j];
				 arrayJugador[j] = arrayJugador[j+1];
				 arrayJugador[j+1]=auxJugador;
				 	 	 }
				 	 }

				}
			}
			limiteConfederacion--;
		} while (bandera);

	}
}





int jugador_imprimirArray_informes(eJugador arrayJugador[], int limiteJugador, eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int respuesta = -1;
	int i;
	if (arrayJugador != NULL && limiteJugador > 0)
	{
		for (i = 0; i < limiteJugador; i++)
		{
			jugador_imprimir_informes(arrayJugador[i], arrayConfederacion,limiteConfederacion);

		}
		respuesta = 0;
	}

	return respuesta;
}






int jugador_imprimir_informes(eJugador unJugador, eConfederacion arrayConfederacion[],int limiteConfederacion)
{
	int retorno = -1;
	if (unJugador.isEmpty == 1 && arrayConfederacion != NULL
			&& limiteConfederacion > 0)
	{
		for (int i = 0; i < limiteConfederacion; i++)
		{
			if (unJugador.idConfederacion == arrayConfederacion[i].id)
			{

			printf("  NOMBRE:%s  CONFEDERACION: %s\n\n",
					 unJugador.nombre, arrayConfederacion[i].nombre);

			retorno = 0;
			}
		}

	}
	return retorno;
}



void totalyPromedioSalarios(eJugador arrayJugadores[], int limiteJugadores)
{
int i;
float acumulador = 0;
int contador = 0;
int contadorJugadores = 0;
float promedio;
float total;

	for(i = 0; i < limiteJugadores; i++)
	{
		if(arrayJugadores[i].isEmpty == 1)
		{

			acumulador+= arrayJugadores[i].salario;
			contador++;
		}
	}
	total = acumulador;
	promedio = acumulador / contador;

	for(int j = 0; j < limiteJugadores; j++ )
	{
		if(arrayJugadores[j].isEmpty == 1 && arrayJugadores[j].salario > promedio)
		{
			contadorJugadores++;
		}
	}
	printf("\nEl total de los salarios es: %2.f", total);
	printf("\nEl promedio es:%2.f", promedio);
	printf("\nLa cantidad de jugadores que superan el salario prmomedio es: %d", contadorJugadores);
}


void confederaciónMayorAñosContratosTotal(eJugador arrayJugador[], int limiteJugador)
{
int i;
int acumulador100 = 0;
int acumulador101 = 0;
int acumulador102 = 0;
int acumulador103 = 0;
int acumulador104 = 0;
int acumulador105 = 0;


	for(i = 0; i < limiteJugador; i++)
	{
		if(arrayJugador[i].idConfederacion == 100)
		{
			acumulador100+= arrayJugador[i].aniosContrato;
		}
		else if(arrayJugador[i].idConfederacion == 101)
		{
			acumulador101+= arrayJugador[i].aniosContrato;
		}
		else if(arrayJugador[i].idConfederacion == 102)
		{
			acumulador102+= arrayJugador[i].aniosContrato;
		}
		else if(arrayJugador[i].idConfederacion == 103)
		{
			acumulador103+= arrayJugador[i].aniosContrato;
		}
		else if(arrayJugador[i].idConfederacion == 104)
		{
			acumulador104+= arrayJugador[i].aniosContrato;
		}
		else if(arrayJugador[i].idConfederacion == 105)
		{
			acumulador105+= arrayJugador[i].aniosContrato;
		}
	}

if(acumulador100 > acumulador101 && acumulador100 > acumulador102 && acumulador100 > acumulador103 && acumulador100 > acumulador104 && acumulador100 > acumulador105)
{
	printf("\nLa confederacion con mas anios de contrato es: CONMEBOL con un total de: %d", acumulador100);
}
else if(acumulador101 > acumulador102 && acumulador101 > acumulador103 && acumulador101 > acumulador104 && acumulador101 > acumulador105)
{
	printf("\nLa confederacion con mas anios de contrato es: UEFA con un total de: %d", acumulador101);
}
else if(acumulador102 > acumulador103 && acumulador102 > acumulador104 && acumulador102 > acumulador105)
{
	printf("\nLa confederacion con mas anios de contrato es: AFC  con un total de: %d", acumulador102);
}
else if(acumulador103 > acumulador104 && acumulador103 > acumulador105)
{
	printf("\nLa confederacion con mas anios de contrato es: CAF  con un total de: %d", acumulador103);
}
else if(acumulador104 > acumulador105)
{
	printf("\nLa confederacion con mas anios de contrato es: CONCACAF  con un total de: %d", acumulador104);
}
else
{
	printf("\nLa confederacion con mas anios de contrato es: OFC  con un total de: %d", acumulador105);
}



}
