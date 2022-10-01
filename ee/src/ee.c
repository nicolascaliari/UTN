/*
 ============================================================================
 Name        : ee.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* pEntero =NULL;
	int variablea = 50;
	int variableb = 60;
	pEntero = &variablea;

	*pEntero+= variableb;

	printf("El valor es: %d", pEntero);
	return EXIT_SUCCESS;
}
