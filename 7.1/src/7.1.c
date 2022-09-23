/*
 ============================================================================
 Name        : 1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct{
	char nombre[20];
	int goles;
	int partidosJugados;
	float promedioGoles;
 }jugadores;


void cargarDatos();
void imprimirDatos();
void calcularPromedio();
int main(void)
{

	cargarDatos();
	imprimirDatos();
	calcularPromedio();



    return EXIT_SUCCESS;
}


void cargarDatos(jugadores valor){



	printf("Ingrese nombre del jugador:\n" );
	fgets(valor.nombre, 20, stdin);
	__fpurge();

	printf("Ingrese cantidad de goles :\n");
	scanf("%d", &valor.goles);
	__fpurge(stdin);

	printf("Ingrese cantidad de partidos jugados\n");
	scanf("%d", &valor.partidosJugados);
	__fpurge(stdin);

}


void imprimirDatos(jugadores valor){


	printf("El nombre del jugador es:%s\n", valor.nombre);
	printf("La cantidad de goles son: %d\n", valor.goles);
	printf("La cantidad de partidos jugados son: %d\n", valor.partidosJugados);

}


void calcularPromedio(jugadores valor){

valor.promedioGoles = (float)valor.goles / valor.partidosJugados;

printf("EL promedio es: %.2f" , valor.promedioGoles);
__fpurge(stdin);

}
