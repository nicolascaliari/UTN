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

int main(void) {
	setbuf(stdout , NULL);

	int i;
	int numeros[7];

	for(i = 0 ; i < 7; i++){
		numeros[i]=5;
	}
	return EXIT_SUCCESS;
}
