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


int sumarUno(int numeroUno,int numeroDos);
int sumarDos(void);
void sumarTres(int numeroUno, int numeroDos);
void sumarCuatro(void);

int main(void) {

	int numeroUno = 10;
	int numeroDos = 10;
	int resultadoUno;
	int resultadoDos;


	resultadoUno = sumarUno(numeroUno, numeroDos);
	resultadoDos = sumarDos();
	sumarTres(2,3);


	printf("\n El resultado es %d", resultadoUno);
	printf("\n El resultado es %d", resultadoDos);

	return EXIT_SUCCESS;
}

int sumarUno(numeroUno, numeroDos)
{
	int suma;
	suma = numeroUno + numeroDos;

	return suma;
}

int sumarDos(void){
	int numeroUno;
	int numeroDos;
	int suma;
	printf("Ingrese un numero: ");
	scanf("%d", &numeroUno);

	printf("Ingrese otro numero");
	scanf("%d", &numeroDos);

	suma = numeroUno + numeroDos;
	return suma;
}

void sumarTres(int numeroUno, int numeroDos){
	int suma;
	suma = numeroUno + numeroDos;
	printf("El resultado es %d" , suma);
}

void sumarCuatro(void){
	int numeroUno;
	int numeroDos;
	int suma;

	printf("Ingrese un numero: ");
	scanf("%d", &numeroUno);

	printf("Ingrese otro numero");
	scanf("%d", &numeroDos);

	suma = numeroUno + numeroDos;
	printf("El resultado es %d", suma);
}

