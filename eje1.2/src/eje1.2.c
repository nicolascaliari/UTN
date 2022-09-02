/*
 ============================================================================
 Name        : 2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main()
{
   	int numeroUno;
	int numeroDos;
	int numeroTres;
	int resultado;

	printf("Numero uno: ");
	scanf("%d" , &numeroUno);
	printf("Numero dos: ");
	scanf("%d" , &numeroDos);
	printf("Numero tres: ");
	scanf("%d" , &numeroTres);


	if(numeroUno > numeroDos && numeroUno > numeroTres){
	    printf("El numero mayor es: %d" , numeroUno);
	}else {
	    if(numeroDos > numeroTres){
	        printf("El numero mayor es: %d" , numeroDos);
	    }else {
	        printf("El numero mayor es: %d" , numeroTres);
	    }
	}

    return 0;
}
