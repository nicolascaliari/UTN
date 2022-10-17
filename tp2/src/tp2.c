/*
 ============================================================================
 Name        : tp_2.c
 Author      : Nicolas Caliari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "salida_datos.h"
#include "jugador.h"
#include "confederacion.h"
#include "utn.h"

#define CANTIDAD_JUGADOR 10
int main(void) {

eJugador arrayJugadores[CANTIDAD_JUGADOR];
inicializar_array(arrayJugadores, CANTIDAD_JUGADOR);

	menu(arrayJugadores, CANTIDAD_JUGADOR);

	return EXIT_SUCCESS;
}
