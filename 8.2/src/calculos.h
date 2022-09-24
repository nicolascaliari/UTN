/*
 * calculos.h
 *
 *  Created on: 24 sep. 2022
 *      Author: nicolas
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
typedef struct{
	int idProduct;
	char description[20];
	int nation;
	int type;
	float price;
	int isEmpty;
}products;

void initDatos(products apple[], int len);
int deleteDatos(products apple[], int len);
int encontrarId(products apple[], int len);
void cargarProducto(products apple[], int len);



int eGen_Alta(products array[], int TAM);
products eGen_CargarDatos(void);
static int eGen_ObtenerID(void);
static int eGen_ObtenerID(void);

int eGen_MostrarTodos(products array[], int TAM);
void eGen_MostrarUno(products Gen);

#endif /* CALCULOS_H_ */
