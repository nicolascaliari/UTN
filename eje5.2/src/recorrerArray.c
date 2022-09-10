#include <stdio.h>
#include <stdlib.h>
void recorrerArray(int ENTEROS[], int len){
	int i;
	for(i=0; i < len ;i++)
	{
		printf("numeros enteros: %d  \n ",ENTEROS[i]);
	}

}



void arrayPares(int array[],int len){
	int i;

	for(i=0; i < len ;i++){
		if(array[i] % 2 == 0){
			printf("pares: %d \n", array[i]);
	}
}
}

void arrayIndicesImpares(int array[], int len){
	int i;
	for(i=0 ; i < len ; i++){
		if(i  %2 == 1){
			printf("El indice impar es: %d y su numero es: %d \n", i, array[i]);
		}
	}
}

