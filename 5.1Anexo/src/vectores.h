/*
 * vectores.h
 *
 *  Created on: 15 sep. 2022
 *      Author: nicolas
 */

#ifndef VECTORES_H_
#define VECTORES_H_

int esNumerica(char cadena[]);
int getInt(int *pResultado);
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
void mostrarMenu(int opciones);
void iniciarlizarArray(int array[], int len, int inicial);
void pedirEdades(void);
void mostrarPorPantalla(int array[] , int len);
void cargarEdades(int *array, int len);
void calcularPromedio(int * array);

#endif /* VECTORES_H_ */
