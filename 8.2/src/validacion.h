/*
 * validacion.h
 *
 *  Created on: 17 sep. 2022
 *      Author: nicolas
 */

#ifndef VALIDACION_H_
#define VALIDACION_H_
typedef struct{
	int idProduct;
	char description[20];
	int nation;
	int type;
	float price;
	int isEmpty;
}apple;

void loadProduct(apple products[]);



#endif /* VALIDACION_H_ */
