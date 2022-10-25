/*
 ============================================================================
 Name        : tp_2_mac.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "salida_datos.h"
#include "Jugador.h"
#include "Confederacion.h"
#include "Validaciones.h"


#define CANTIDAD_JUGADOR 100
#define CANTIDAD_CONFEDERACIONES 6
int main(void) {

eJugador arrayJugadores[CANTIDAD_JUGADOR];
eConfederacion arrayConfederaciones[CANTIDAD_CONFEDERACIONES];
inicializar_array(arrayJugadores, CANTIDAD_JUGADOR);
HardcodeoConfederacion(arrayConfederaciones,CANTIDAD_CONFEDERACIONES);

	menu(arrayJugadores, CANTIDAD_JUGADOR, arrayConfederaciones , CANTIDAD_CONFEDERACIONES);

	return EXIT_SUCCESS;
}

