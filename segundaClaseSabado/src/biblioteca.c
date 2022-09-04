#include <stdio.h>
#include <stdlib.h>

int pedirEntero(void)
{
	int pedirNumero;

	printf("Ingrese un numero: ");
	scanf("%d", &pedirNumero);

	return pedirNumero;
}


int calcularPromedio(int numeroUno, int numeroDos)
{
	int promedio;

	promedio =(numeroUno + numeroDos)/2;

	return promedio;
}


int verificarRetorno(int numeroEntero){


	return numeroEntero;

}


int ingresarDiezNumeros(){

}
