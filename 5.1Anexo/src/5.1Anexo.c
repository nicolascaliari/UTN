/*
 ============================================================================
 Name        : 1Anexo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"



int main(void) {

int opciones = 0;


do{
	mostrarMenu(opciones);
}
	while(opciones != 6);


	return EXIT_SUCCESS;
}
