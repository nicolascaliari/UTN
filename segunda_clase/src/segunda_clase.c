
/*
 ============================================================================
 Name        : segundaClase.c
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
	  int ingresarNumero;
	    int contadorPares = 0;
	    int contadorImpares = 0;
	    int acumuladorPositivos = 0;
	    int acumuladorNegativos = 1;
	    int menorNumero;
	    int flag;
	    int flagPar;



	    flag = 0;
	    flagPar = 0;

	    for(int i = 0; i < 10 ; i++){
	    printf("Ingresa un numero:  ");
	    scanf("%d" , &ingresarNumero);
	    while(ingresarNumero == 0){
	        printf("ERROR, Ingresa un numero:  ");
	        scanf("%d" , &ingresarNumero);
	    }

	        if(ingresarNumero%2 == 0){
	            contadorPares++;

	        }
	        if(flagPar == 1 || flagPar < ingresarNumero){
	        	flagPar = ingresarNumero;
	        }


	        if(ingresarNumero%2 == 1 ){
	            contadorImpares++;
	        }

	        if(flag == 1){
	            menorNumero = ingresarNumero;
	            flag = 0;
	        }else {
	            if(menorNumero > ingresarNumero){
	                menorNumero = ingresarNumero;
	            }
	        }


	        if(ingresarNumero > 0){
	        	acumuladorPositivos+= ingresarNumero;
	        }else {
	        	acumuladorNegativos*=ingresarNumero;

	        }

	    }

	    printf("La cantidad de pares es: %d \n" , contadorPares);

	    printf("De los numeros pares el mayor es: %d \n" , flagPar);

	    printf("La cantidad de impares es: %d \n" , contadorImpares);

	    printf("El menor de los numeros ingresados es: %d \n" , menorNumero);

		printf("La suma de los positivos es: %d \n" , acumuladorPositivos);

		printf("El producto de los numeros negativos es: %d \n" , acumuladorNegativos);
	return 0;
}
