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
	int promedio;
	int acc = 0;
	int contador = 0;
	int flag;
	int menorNegativo;
	int acumuladorNegativos = 0;
	int resultadoAntecesor;

	flag = 0;

	InicializarVector(numeros, len, 0);
	arrayAleatorio(numeros);

	for(int i=0; i<len; i++)
	    {
	        if(numeros[i]!=0)
	        {
	             	 if(numeros[i] > 0)
	             	 {
	             		 contador++;
	             	 	 acc+=numeros[i];
	             	 }else
	             	 {
	             		 acumuladorNegativos+= numeros[i];

	             	 if(flag == 0)
	             	 {
	             		 menorNegativo = numeros[i];
	             		 flag =1;
	             	 }else
	             	 {
	             		if(menorNegativo < numeros[i])
	             		{
	             			 menorNegativo = numeros[i];
	             		}
	             	 }
	             }
	        }

	   }
	resultadoAntecesor = acumuladorNegativos - menorNegativo;
	promedio = acc / contador ;
	printf("El promedio de los positivos es: %d" , promedio);
	printf("La suma de los antecesores es: %d", resultadoAntecesor);

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
