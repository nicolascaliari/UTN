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
#include <string.h>

int main(void) {
	char nombre[20];
	char apellido[20];
	char nombre_completo[60];

	printf("Ingrese un nombre");
	fgets(nombre, 20, stdin);

	printf("Ingrese un apellido");
	fgets(apellido, 20, stdin);
	int largoNom;
	largoNom=strlen(apellido);
	apellido[largoNom-1]='\0';

	strcpy(nombre_completo, apellido);
	strcat(nombre_completo, ", ");
	strcat(nombre_completo, nombre);

	printf("%s",nombre_completo);

//	printf("El nombre es:%s" , nombre);
//	printf("El apellido es:%s" , apellido);

	return EXIT_SUCCESS;
}
