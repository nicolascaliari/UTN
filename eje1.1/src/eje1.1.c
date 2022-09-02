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

	int numeroUno;
	int numeroDos;
	int resultado;

	printf("Numero uno: ");
	scanf("%d" , &numeroUno);
	printf("Numero dos: ");
	scanf("%d" , &numeroDos);


	//numeroUno = 34;
	//numeroDos = 23;

	resultado = numeroUno + numeroDos;




	printf("El resultado de sumar esto:%d  y esto : %d es : %d" ,
			numeroUno, numeroDos, resultado);

	return 0;
}
