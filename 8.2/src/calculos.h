/*
 * validacion.h
 *
 *  Created on: 17 sep. 2022
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

void loadProduct(products apple[], int len);



#endif /* CALCULOS_H_ */
