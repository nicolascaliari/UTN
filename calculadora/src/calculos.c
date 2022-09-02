#include <stdio.h>

int calcularDivisiones(int numero1, int numero2, int * resultado){
	int retorno = -1;

	if(numero2 != 0){
		*resultado = numero1 / numero2;
		retorno = 0;
	}

	return retorno;
}

int calcularSuma(int numero1, int numero2, int * suma){

	if(suma != NULL){
	*suma = numero1 + numero2;
	}


	return suma;
}

int calcularResta(int numero1, int numero2, int * resta){

	if(resta != NULL) {
	*resta = numero1 - numero2;
	}

	return resta;
}

int calcularMultiplicacion(int numero1, int numero2, int * multiplicacion){
if(multiplicacion != NULL){
	*multiplicacion = numero1 * numero2;
	}

	return multiplicacion;
}
