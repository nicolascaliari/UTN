/*
 * informes.h
 *
 *  Created on: 23 oct. 2022
 *      Author: nicolas
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Jugador.h"
#include "Confederacion.h"

void menuInformes(eJugador arrayJugador[], int limiteJugador , eConfederacion arrayConfederacion[], int limiteConfederacion);
int recurso_ordenarPorIdDescripcion(eConfederacion arrayConfederacion[],eJugador arrayJugador[], int limiteConfederacion, int limiteJugador);
int totalyPromedioSalarios(eJugador arrayJugadores[], int limiteJugadores);
int jugador_imprimir_informes(eJugador unJugador, eConfederacion arrayConfederacion[],int limiteConfederacion);
int jugador_imprimirArray_informes(eJugador arrayJugador[], int limiteJugador, eConfederacion arrayConfederacion[], int limiteConfederacion);

int confederaciónMayorAñosContratosTotal(eJugador arrayJugador[],eConfederacion arrayConfederacion[],int limiteConfederacion, int limiteJugador);
int regionMasJugadores(eJugador arrayJugador[],eConfederacion arrayConfederacion[], int limiteConfederacion, int limiteJugador);
int max(int num1, int num2, int num3, int num4, int num5, int num6, int *pResultado,  int *pIdMayor);
int porcentajeJugadores (eJugador arrayJugador[],eConfederacion arrayConfederacion[],int limiteConfederacion, int limiteJugador);
int calcularPromedio(float *pResultado, int multiplicador, int divisor);
#endif /* INFORMES_H_ */
