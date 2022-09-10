/*
 ============================================================================
 Name        : 2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 5-2:
Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
Cantidad de positivos y negativos.
Sumatoria de los pares.
El mayor de los impares.
Listado de los números ingresados.
Listado de los números pares.
Listado de los números de las posiciones impares.
 */

#include <stdio.h>
#include <stdlib.h>
#include "recorrerArray.h"


#define len 10
int main(void) {


	int i;
	int numeros[len];
	int cantidadPositivos = 0;
	int cantidadNegativos = 0;
	int sumarPares = 0;
	int imparMaximo;
	int flag;



	flag = 0;


	for(i=0; i < len ; i++){
		printf("Ingrese un numero: ");
		scanf("%d", &numeros[i]);

		while(numeros[i] < -1000 || numeros[i] > 1000){
			printf("ERROR, Ingrese un numero: ");
			scanf("%d", &numeros[i]);

		}

	if(numeros[i] > 0){
		cantidadPositivos++;
	}else {
		cantidadNegativos++;
	}

	if(numeros[i] % 2 == 0){
		sumarPares+=numeros[i];
	}else if(imparMaximo < numeros[i] || flag == 0){
		imparMaximo = numeros[i];
		flag =1;
	}


	}
	recorrerArray(numeros , len);
	arrayPares(numeros, len);
	arrayIndicesImpares(numeros,len);
	printf("La cantidad de positivos es: %d \n", cantidadPositivos);
	printf("La cantidad de negativos es: %d \n",cantidadNegativos);
	printf("La suma de los pares es: %d \n", sumarPares);
	printf("El impar maximo es: %d \n" , imparMaximo);

	return EXIT_SUCCESS;
}








