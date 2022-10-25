#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "informes.h"
#include "Jugador.h"
#include "Confederacion.h"


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
				if(recurso_ordenarPorIdDescripcion(arrayConfederacion, arrayJugador, limiteConfederacion, limiteJugador)==0)
				{
				jugador_imprimirArray(arrayJugador, limiteJugador, arrayConfederacion, limiteConfederacion);
				}else
				{
					printf("\nAlgo salio mal");
				}
				break;
			case 2:
				if(jugador_imprimirArray_informes(arrayJugador, limiteJugador, arrayConfederacion, limiteConfederacion)==0)
				{
					printf("\nListado de jugadores por confederacion realizado con exito");
				}else
				{
					printf("\nAlgo salio mal");
				}
				break;
			case 3:
				if(totalyPromedioSalarios(arrayJugador, limiteJugador)==0)
				{
					printf("\nCalculo de promedio de salarios realizado con exito");
				}else
				{
					printf("\nAlgo salio mal");
				}
				break;
			case 4:
				if(confederaciónMayorAñosContratosTotal(arrayJugador,arrayConfederacion,limiteConfederacion ,limiteJugador)==0)
				{
					printf("\nTodo salio bien");
				}else
				{
					printf("\nAlgo salio mal");
				}
				break;
			case 5:
				if(porcentajeJugadores(arrayJugador, arrayConfederacion, limiteConfederacion, limiteJugador)==0)
				{
					printf("\nTodo salio bien");
				}else
				{
					printf("Algo salio mal");
				}
				break;
			case 6:
				if(regionMasJugadores(arrayJugador, arrayConfederacion,limiteConfederacion,limiteJugador)==0)
				{
					printf("\nTodo salio bien");
				}else
				{
					printf("Algo salio mal");
				}
				break;
			}

		}

	} while (opcion != 5);
}

int recurso_ordenarPorIdDescripcion(eConfederacion arrayConfederacion[],eJugador arrayJugador[], int limiteConfederacion, int limiteJugador)
{
	int retorno = -1;
	int i;
	int j;
	int bandera;
	eJugador auxJugador;
	char nombreConfederacion[50];
	char nombreConfederacion2[50];
	if (arrayConfederacion != NULL && limiteConfederacion > 0 && arrayJugador != NULL && limiteJugador > 0)
	{

		do {
			bandera = 0;
			for( i = 0; i < limiteJugador -1 ; i++)
			{
				for (j = i + 1; j < limiteJugador ; j++)
				{

					if(arrayJugador[i].isEmpty == 1 && arrayJugador[j].isEmpty == 1  && buscarFederacion(arrayConfederacion, limiteConfederacion, arrayJugador[i].idConfederacion, nombreConfederacion)==0
						&& buscarFederacion(arrayConfederacion, limiteConfederacion, arrayJugador[j].idConfederacion, nombreConfederacion2)==0)
					{
						if(strncmp(nombreConfederacion, nombreConfederacion2,30) < 0)
						{
							bandera = 1;
							auxJugador = arrayJugador[i];
							arrayJugador[i] = arrayJugador[j];
							arrayJugador[j]=auxJugador;
					    }
				    }
					else if(strncmp(nombreConfederacion, nombreConfederacion2,30) == 0)
					{
					if(strncmp(arrayJugador[i].nombre,arrayJugador[j].nombre,30) < 0)
					{
						bandera = 1;
						auxJugador = arrayJugador[i];
						arrayJugador[i] = arrayJugador[j];
						arrayJugador[j]=auxJugador;
				 	 	 }
				 	 }

				}
			}
		} while (bandera);

	}
	return retorno;
}





int jugador_imprimirArray_informes(eJugador arrayJugador[], int limiteJugador, eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int retorno = -1;
	int i;
	if (arrayJugador != NULL && limiteJugador > 0)
	{
		for (i = 0; i < limiteJugador; i++)
		{
			jugador_imprimir_informes(arrayJugador[i], arrayConfederacion,limiteConfederacion);

		}
		retorno = 0;
	}

	return retorno;
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



int totalyPromedioSalarios(eJugador arrayJugadores[], int limiteJugadores)
{
int retorno = -1;
int i;
float acumulador = 0;
int contador = 0;
int contadorJugadores = 0;
float promedio;
float total;
	if(arrayJugadores != NULL && limiteJugadores > 0)
	{
		retorno = 0;
	for(i = 0; i < limiteJugadores; i++)
	{
		if(arrayJugadores[i].isEmpty == 1)
		{

			acumulador+= arrayJugadores[i].salario;
			contador++;
		}
	}
	total = acumulador;
	promedio = total / contador;

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

return retorno;
}


int confederaciónMayorAñosContratosTotal(eJugador arrayJugador[],eConfederacion arrayConfederacion[],int limiteConfederacion, int limiteJugador)
{
int retorno = -1;
int i;
int acumulador100 = 0;
int acumulador101 = 0;
int acumulador102 = 0;
int acumulador103 = 0;
int acumulador104 = 0;
int acumulador105 = 0;
int resultado;
char nombreConfederacion[50];
int id;

	if(arrayJugador != NULL && limiteJugador > 0)
	{

		retorno = 0;

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

	max(acumulador100,acumulador101, acumulador102,acumulador103, acumulador104, acumulador105, &resultado, &id);
	buscarFederacion(arrayConfederacion, limiteConfederacion, id, nombreConfederacion);

	printf("\nEl nombre es: %s  y su cantidad es:%d",nombreConfederacion ,resultado);


	}
	return retorno;
}





int regionMasJugadores(eJugador arrayJugador[],eConfederacion arrayConfederacion[], int limiteConfederacion, int limiteJugador)
{
	int retorno = -1;
	int i;
	int acumulador100 = 0;
	int acumulador101 = 0;
	int acumulador102 = 0;
	int acumulador103 = 0;
	int acumulador104 = 0;
	int acumulador105 = 0;
	int resultado;
	char nombreFederacion[50];
	int idConfederacion;
	if(arrayJugador != NULL && limiteJugador > 0)
	{
		retorno = 0;
		for(i = 0; i < limiteJugador; i++)
		{
			if(arrayJugador[i].idConfederacion == 100)
			{
				acumulador100++;
			}
			else if(arrayJugador[i].idConfederacion == 101)
			{
				acumulador101++;
			}
			else if(arrayJugador[i].idConfederacion == 102)
			{
				acumulador102++;
			}
			else if(arrayJugador[i].idConfederacion == 103)
			{
				acumulador103++;
			}
			else if(arrayJugador[i].idConfederacion == 104)
			{
				acumulador104++;
			}
			else if(arrayJugador[i].idConfederacion == 105)
			{
				acumulador105++;
			}
		}

		max(acumulador100,acumulador101, acumulador102,acumulador103, acumulador104, acumulador105, &resultado, &idConfederacion);
		buscarRegion(arrayConfederacion, limiteConfederacion, idConfederacion, nombreFederacion);

		printf("\nEl nombre es: %s  y su cantidad es:%d",nombreFederacion ,resultado);

	}
	return retorno;
}



int max(int num1, int num2, int num3, int num4, int num5, int num6, int *pResultado, int *pIdMayor){

    int retorno = -1;
    int resultado;

    if(pResultado != NULL){

        if (num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5 && num1 > num6){
        	*pIdMayor = 100;
            resultado = num1;

        } else if (num2 > num3 && num2 > num4 && num2 > num5 && num2 > num6 ){
        	*pIdMayor = 101;
            resultado = num2;

        } else if (num3 > num4 && num3 > num5 && num3> num6){
        	*pIdMayor = 102;
            resultado = num3;

        } else if(num4 > num5 && num4 > num6){
        	*pIdMayor = 103;
            resultado = num4;

        }else if( num5 > num6){
        	*pIdMayor = 104;
            resultado = num5;

        }else{
        	*pIdMayor = 105;
            resultado = num6;

        }

        retorno = 0;
    }

    if(retorno == 0){

        *pResultado = resultado;
    }

    return retorno;
}







int porcentajeJugadores (eJugador arrayJugador[],eConfederacion arrayConfederacion[],int limiteConfederacion, int limiteJugador)
{
	int retorno = -1;
	int i;
	int unJugador = 0;
	int acumulador100 = 0;
	int acumulador101 = 0;
	int acumulador102 = 0;
	int acumulador103 = 0;
	int acumulador104 = 0;
	int acumulador105 = 0;
	float porcentajeConmebol;
	float porcentajeUefa;
	float porcentajeAfc;
	float porcentajeCaf;
	float porcentajeConcacaf;
	float porcentajeOfc;




	if(arrayJugador != NULL && limiteJugador > 0)
	{
		retorno = 0;
		for(i = 0; i < limiteJugador; i++)
		{
			if(arrayJugador[i].isEmpty == 1)
			{
			unJugador++;
			if(arrayJugador[i].idConfederacion == 100)
			{
				acumulador100++;
			}
			else if(arrayJugador[i].idConfederacion == 101)
			{
				acumulador101++;
			}
			else if(arrayJugador[i].idConfederacion == 102)
			{
				acumulador102++;
			}
			else if(arrayJugador[i].idConfederacion == 103)
			{
				acumulador103++;
			}
			else if(arrayJugador[i].idConfederacion == 104)
			{
				acumulador104++;
			}
			else if(arrayJugador[i].idConfederacion == 105)
			{
				acumulador105++;
				}
			}
		}


		calcularPromedio(&porcentajeConmebol,acumulador100, unJugador);
		calcularPromedio(&porcentajeUefa,acumulador101, unJugador);
		calcularPromedio(&porcentajeAfc,acumulador102, unJugador);
		calcularPromedio(&porcentajeCaf,acumulador103, unJugador);
		calcularPromedio(&porcentajeConcacaf,acumulador104, unJugador);
		calcularPromedio(&porcentajeOfc,acumulador105, unJugador);


		printf("\nEl promedio es: %.2f",porcentajeConmebol );
		printf("\nEl promedio es: %.2f",porcentajeUefa );
		printf("\nEl promedio es: %.2f",porcentajeAfc );
		printf("\nEl promedio es: %.2f",porcentajeCaf );
		printf("\nEl promedio es: %.2f",porcentajeConcacaf );
		printf("\nEl promedio es: %.2f",porcentajeOfc );

	}
	return retorno;
}


int calcularPromedio(float *pResultado, int multiplicador, int divisor){

    float promedio;
    int retorno = -1;

    if(pResultado != NULL && divisor != 0){
        promedio = (float)(multiplicador * 100) / divisor;

        *pResultado = promedio;
        retorno = 0;

    }else{
    	*pResultado = 0;
    }

    return retorno;
}

