/*
 * calculos.h
 *
 *  Created on: 24 sep. 2022
 *      Author: nicolas
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
#define NOMBRE_LEN 50
#define DESCRIPCION 20

#define TIPO_LCD	0
#define TIPO_LED	1

typedef struct
{
	char nombre[NOMBRE_LEN];
	char descripcion[DESCRIPCION];
	float precio;
	int isEmpty;
	int id;
	int tipo; // agregado!
}Product;

int pan_imprimir(Product* auxProducto);
int pan_inicializarArray(Product* array,int limite);
int pan_altaArray(Product* array,int limite, int indice, int* id);
int pan_getEmptyIndex(Product* array,int limite);
int pan_imprimirArray(Product* array,int limite);
int pan_buscarId(Product array[], int limite, int valorBuscado);
int pan_modificarArray(Product* array,int limite, int indice);
int pan_bajaArray(Product* array,int limite, int indice);
int pan_ordenarPorNombre(Product* array,int limite);

#endif /* CALCULOS_H_ */
