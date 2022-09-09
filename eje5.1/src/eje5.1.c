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

#define valor 5


int main(void) {

int edades[valor];
int i;
int edad;


for(i=0 ; i < valor ; i++){

	printf("Ingrese su edad: ");
	scanf("%d" , &edad);

	edades[i] = edad;

}

for(i=0; i<valor ; i++) {
	printf("%d \n" , edades[i]);
}
	return EXIT_SUCCESS;
}
