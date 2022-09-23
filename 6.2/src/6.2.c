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


int ordenarArray(int* array, int len);
int ordenarArrayDescendiente(int* array, int len);
int pedirEnteros(void);
int imprimirArray(int* array, int len);
int main(void) {

	int numeros[10];

	cargarEdades(numeros, 10);


	imprimirArray(numeros, 10);


	return EXIT_SUCCESS;
}




int pedirEnteros(void){
int numero;
char array[10];

printf("Ingrese un numero: ");
fgets(array, sizeof(array) , stdin);
array[strlen(array) - 1];

numero = atoi(array);

return numero;
}

void cargarEdades(int *array, int len){

	int acc = 0;
	for(int i = 0; i < len; i++){

		array[i] = pedirEnteros();
//		acc+=array[i];
	}
//	printf("EL total es %d\n", acc);
}


int ordenarArray(int* array, int len){
    int flagSwap;
    int i;
    int retorno = -1;
    int buffer;

    if(array != NULL && len > 0){
        do{
            flagSwap = 0;
            for(i = 0; i < len - 1; i++){
                if(array[i] > array[i+1]){
                    flagSwap = 1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
            }
        }while(flagSwap);
    }
    retorno = 0;
    return retorno;
}


int ordenarArrayDescendiente(int* array, int len){
    int flagSwap;
    int i;
    int retorno = -1;
    int buffer;

    if(array != NULL && len > 0){
        do{
            flagSwap = 0;
            for(i = 0; i < len - 1; i++){
                if(array[i] < array[i+1]){
                    flagSwap = 1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
            }
        }while(flagSwap);
    }
    retorno = 0;
    return retorno;
}

void imprimirArray(int* array, int len){
    for(int i = 0; i < len; i++){

    	if(array[i] > 0){
    		ordenarArray(array, 10);
    		printf("%d \n", array[i]);
    	}else {
    		ordenarArrayDescendiente(array, len);
    		printf("%d \n", array[i]);
    	}

    }
}


