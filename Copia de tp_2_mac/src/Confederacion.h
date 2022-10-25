/*
 * confederacion.h
 *
 *  Created on: 16 oct. 2022
 *      Author: nicolas
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
}eConfederacion;


void HardcodeoConfederacion(eConfederacion arrayConfederacion[], int limiteConfedracion);
int pedirConfederacion(eConfederacion arrayConfederacion[], int limiteConfederacion);
int mostrarConfederaciones(eConfederacion arrayConfederacion[], int limiteConfederacion);
int buscarFederacion(eConfederacion arrayConfederacion[], int limiteConfederacion, int idConfederacion, char *pConfederacion );
int buscarRegion(eConfederacion arrayConfederacion[], int limiteConfederacion, int idConfederacion, char *pConfederacion );

#endif /* CONFEDERACION_H_ */
