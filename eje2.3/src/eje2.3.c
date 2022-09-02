
/*
 ============================================================================
 Name        : 3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numeroCliente;
	char estadoCivil;
	int edad;
	int temperatura;
	char genero;
	int numeroClienteMujer;
	int edadMujerJoven = 0;
	int cantidadViudaJubilado = 0;
	int precioPasajero = 600;
	int cantidadJubilado = 0;
	int descuento = 0;
	int acumuladorPrecioBruto = 0;
	int precioFinal;

	for(int i = 0 ; i < 50 ; i++){

		printf("Ingrese su numero de clientes: ");
		scanf("%d" , &numeroCliente);
		fflush(stdin);
		while(numeroCliente < 0){
			printf("ERROR, Ingrese su numero de clientes: ");
			scanf("%d" , &numeroCliente);
			fflush(stdin);
		}

		printf("Enter condition civil s/c/v: ");
		scanf("%c" , &estadoCivil);
		fflush(stdin);
		while(estadoCivil!='s' && estadoCivil!='c' && estadoCivil!='v'){
			printf("ERROR, enter condition civil s/c/v: ");
			scanf("%c" , &estadoCivil);
			fflush(stdin);
		}

		printf("Enter your age: ");
		scanf("%d" , &edad);
		fflush(stdin);
		while(edad <= 17){
			printf("ERROR, Enter your age: ");
			scanf("%d" , &edad);
			fflush(stdin);
		}

		printf("Enter your temperature corporal: ");
		scanf("%d" , &temperatura);
		fflush(stdin);
		while(temperatura < 0) {
		    printf("ERROR, Enter your temperature corporal: ");
		    scanf("%d" , &temperatura);
		    fflush(stdin);
		}

		printf("Enter your gender m/f/o: ");
		scanf("%c" , &genero);
		fflush(stdin);
		while(genero!='m' && genero!='f' && genero!='o'){
			printf("ERROR,Enter your gender m/f/o: ");
			scanf("%c" , &genero);
			fflush(stdin);
		}

		acumuladorPrecioBruto+=precioPasajero*1;

		switch(estadoCivil){
		case 's':
			switch(genero){
			case 'f':
				if(edadMujerJoven == 0 ||  edadMujerJoven > edad){
					edadMujerJoven = edad;
					numeroClienteMujer = numeroCliente;
				}
				break;
			}
			break;
		case 'v':
			if(edad > 60){
				cantidadViudaJubilado++;
			}
			break;
		}

		if(edad >= 60){
			cantidadJubilado++;
		}




	}
	if(cantidadJubilado > 49){
				descuento = 25;
				precioFinal = acumuladorPrecioBruto -(acumuladorPrecioBruto * descuento)/100;
			}else {
				precioFinal = acumuladorPrecioBruto;
			}



	printf("La cantidad de gente viuda con mas de 60 anios son: %d " , cantidadViudaJubilado);
	printf("el número de cliente es: %d y edad de la mujer soltera más joven: %d " , numeroClienteMujer, edadMujerJoven);
	printf("El precio final es %d", precioFinal);
	return EXIT_SUCCESS;
}
