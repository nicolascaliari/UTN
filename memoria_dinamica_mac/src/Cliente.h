/*
 * Cliente.h
 *
 *  Created on: 22 oct. 2022
 *      Author: nicolas
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct{
	int idCliente;
	char nombre[50];
	char apellido[50];
	char cuit;
}Cliente;

Cliente* cli_new(void);
int init_arrayPunteros(Cliente* array[], int limite);
int pan_altaArray(Cliente* array[],int limite, int indice, int* id);
int buscarEspacioLibre(Cliente* array[], int limite);
int imprimir_alumno(Cliente* array[], int limite);
int borrarArray(Cliente* array[], int limite);
int buscarId(Cliente* array[], int limite, int id);


#endif /* CLIENTE_H_ */
