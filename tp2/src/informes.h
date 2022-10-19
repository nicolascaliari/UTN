/*
 * informes.h
 *
 *  Created on: 17 oct. 2022
 *      Author: nicolas
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "jugador.h"
#include "confederacion.h"

void menuInformes(eJugador arrayJugador[], int limiteJugador , eConfederacion arrayConfederacion[], int limiteConfederacion);
void recurso_ordenarPorIdDescripcion(eConfederacion arrayConfederacion[],eJugador arrayJugador[], int limiteConfederacion, int limiteJugador);
void totalyPromedioSalarios(eJugador arrayJugadores[], int limiteJugadores);
int jugador_imprimir_informes(eJugador unJugador, eConfederacion arrayConfederacion[],int limiteConfederacion);
int jugador_imprimirArray_informes(eJugador arrayJugador[], int limiteJugador, eConfederacion arrayConfederacion[], int limiteConfederacion);

void confederaciónMayorAñosContratosTotal(eJugador arrayJugador[], int limiteJugador);



#endif /* INFORMES_H_ */
