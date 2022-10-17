#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "jugador.h"


void menu(eJugador unJugador[], int limiteJugador){
	int opcion;

	do{
		if(utn_getNumero(&opcion, "\n         Bienvenido al menu\n"
								  "\n1-Alta de jugador"
								  "\n2-Baja de jugador"
								  "\n3-Modificacion de jugador"
								  "\n4-Informes"
								  "\n5-Salir",
								  "\nError, solo puede ingresar del 1 al 5", 1, 5, 2) == 0){
			switch(opcion){
			case 1:
				inicializar_array(unJugador, limiteJugador);
				alta_jugador(unJugador, limiteJugador);
				break;
			case 2:
				jugador_bajaArray(unJugador, limiteJugador);
				break;
			case 3:
				recurso_modificarRecurso(unJugador, limiteJugador);
				break;
			case 4:
				jugador_imprimirArray(unJugador, limiteJugador);
				break;
			}

		}


	}while(opcion != 5);
}
