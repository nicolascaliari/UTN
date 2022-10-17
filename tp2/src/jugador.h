/*
 * jugador.h
 *
 *  Created on: 16 oct. 2022
 *      Author: nicolas
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;


void inicializar_array(eJugador unJugador[], int limiteJugador);
int jugador_imprimir(eJugador unJugador);
int jugador_imprimirArray(eJugador arrayJugador[], int limiteJugador);
int alta_jugador(eJugador arrayJugador[], int limiteJugador);
int jugador_bajaArray(eJugador arrayJugador[], int limiteJugador);
int recurso_modificarRecurso(eJugador arrayJugador[], int limiteJugador);
int buscarEspacioLibre(eJugador arrayJugador[], int limiteJugador);
int recurso_buscarId(eJugador arrayJugador[], int limiteJugador, int valorBuscado);

#endif /* JUGADOR_H_ */
