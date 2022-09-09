#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pedirDatosNumericos(int ​* pResultado,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int ingresarNumero;


	if(pResultado != NULL && mensaje!= NULL && mensajeError != NULL && minimo <= maximo){

		do{
			printf("Ingrese su edad: ");
			scanf("%d" , &ingresarNumero);

			if(ingresarNumero >= minimo && ingresarNumero <= maximo){
				*pResultado = ingresarNumero;
				retorno = 0;
				break;
			}else {
				printf("%s" , mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
