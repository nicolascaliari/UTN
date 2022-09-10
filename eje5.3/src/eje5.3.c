/*
 ============================================================================
 Name        : 3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define len 10
void InicializarVector(int vector[], int size, int inicial);
void arrayAleatorio(int array[]);
int main(void) {

	int numeros[len];

	InicializarVector(numeros, len, 0);
	arrayAleatorio(numeros);


	printf("La lista de numeros es: \n");

	for(int i=0; i<len; i++)
	    {
	        if(numeros[i]!=0)
	        {
	             printf("%d\n", numeros[i]);
	        }

	    }

	return EXIT_SUCCESS;
}

void InicializarVector(int vector[], int size, int inicial)
{
    for(int i = 0; i<size; i++)
    {
        vector[i] = inicial; //valor ilogico para inicializar
    }
}


void arrayAleatorio(int array[]){
int numero;
int posicion;
char seguir;


do
{
	printf("Ingrese un numero: ");
	scanf("%d", &numero);
	while(numero == 0){
		printf("ERROR, Ingrese un numero distinto a 0: ");
		scanf("%d", &numero);
	}

	printf("Ingrese la posicion del array");
	scanf("%d", &posicion);
	__fpurge(stdin);

	array[posicion -1] = numero;

	printf("Desea ingresar otro numero? ");
	__fpurge(stdin);

	scanf("%c", &seguir);
	}while(seguir == 's');
}
