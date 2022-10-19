#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "jugador.h"
#include "confederacion.h"


void menu(eJugador arrayJugador[], int limiteJugador , eConfederacion arrayConfederacion[], int limiteConfederacion) {
	int opcion;
	int bandera = 0;
	int contador = 0;

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
				if(buscarEspacio(arrayJugador, limiteJugador) == 1)
				{
					if(alta_jugador(arrayJugador, limiteJugador, arrayConfederacion, limiteConfederacion) == 0)
					{
						printf("Dado de alta exitosamente");
						bandera = 1;
						contador++;
					}
					else
					{
						printf("No se pudo dar de alta");
					}
				}
				else
				{
					printf("No hay mas espacio");
				}

				break;
			case 2:
				if(bandera == 1 && jugador_bajaArray(arrayJugador, limiteJugador) == 0)
				{
					printf("Dado de baja exitosamente");
					contador--;
					if(contador == 0)
					{
						bandera = 0;
					}
				}
				else
				{
					printf("No se pudo dar de baja");
				}
				break;
			case 3:
				if(bandera == 1 && recurso_modificarRecurso(arrayJugador, limiteJugador) == 0)
				{
					printf("Modificacion exitosa");
				}
				else
				{
					printf("No se pudo realizar la modificacion");
				}
				break;
			case 4:
				menuInformes(arrayJugador,limiteJugador, arrayConfederacion, limiteConfederacion);
				break;
			case 5:
				jugador_imprimirArray(arrayJugador, limiteJugador, arrayConfederacion, limiteConfederacion);
				break;
			}

		}

	} while (opcion != 5);
}
