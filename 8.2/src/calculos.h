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


typedef struct
{
	char nombre[NOMBRE_LEN];
	char descripcion[DESCRIPCION];
	float precio;
	int isEmpty;
	int id;
	int tipo;
}Product;

int prod_imprimir(Product* auxProducto);
int prod_inicializarArray(Product* array,int limite);
int prod_altaArray(Product* array,int limite, int indice, int* id);
int prod_getEmptyIndex(Product* array,int limite);
int prod_imprimirArray(Product* array,int limite);
int prod_buscarId(Product array[], int limite, int valorBuscado);
int prod_modificarArray(Product* array,int limite, int indice);
int prod_bajaArray(Product* array,int limite, int indice);
int prod_ordenarPorDescripcion(Product* array,int limite);
int OrdenaArrayInt(Product* array,int limite);

#endif /* CALCULOS_H_ */
