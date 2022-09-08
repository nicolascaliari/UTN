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
#include "validaciones.h"
#include "desarrolloTemperatura.h"
int main(void) {

char ingresarTipoTemperatura;
int ingresarTemperatura;
int retornoValidacion;
int retornoDesarrollo;
int resultado;


printf("Ingrese el tipo de temperatura: c / f ");
scanf("%c" , &ingresarTipoTemperatura);
while(ingresarTipoTemperatura!='c' && ingresarTipoTemperatura!='f')
{
	printf("ERROR, Ingrese el tipo de temperatura: c / f ");
	scanf("%c" , &ingresarTipoTemperatura);
}

printf("Ingrese la temperatura: ");
scanf("%d", &ingresarTemperatura);


switch(ingresarTipoTemperatura)
{
case 'f':
retornoValidacion = validarFarenheit(ingresarTemperatura);
if(retornoValidacion == 0){
	retornoDesarrollo = calcularPasajeTemperaturaFarenheit(ingresarTemperatura);
	resultado = printf("El resultado es: %d", retornoDesarrollo);

}else {
	resultado = printf("Algo salio mal");
}

break;

case 'c':
	retornoValidacion = validarCelcius(ingresarTemperatura);
	if(retornoValidacion == 0){
		retornoDesarrollo = calcularPasajeTemperaturaCelcius(ingresarTemperatura);
		resultado = printf("La temperatura es: %d", retornoDesarrollo);
	}else {
		resultado = printf("Algo salio mal!");
	}
	break;


}

	return EXIT_SUCCESS;
}
