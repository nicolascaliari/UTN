/*
 ============================================================================
 Name        : primeraClaseSabado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int importe;
	char origen;
	int flag;
	int minimoImporte;
	char minimoImportePais;
	int promedio;
	int contadorImporte = 0;
	int acumuladorImporte = 0;
	int contadorProductosChina = 0;
	int productos;


	flag = 0;

	for(int i=0; i < 5; i++){
		printf("Ingrese el importe: ");
		scanf("%d", &importe);
		while(importe < 0){
			printf("ERROR, Ingrese el importe: ");
			scanf("%d", &importe);
	}

		printf("Ingrese el pais de origes c(china)/u(uruguay)/p(paraguay): ");
		scanf("%c" , &origen);
		while(origen!='c' && origen!='u' && origen!='p'){
			printf("ERROR, Ingrese el pais de origes c(china)/u(uruguay)/p(paraguay): ");
			scanf("%c" , &origen);
		}

		printf("Ingrese cantidad de productos: ");
		scanf("%d", &productos);

		contadorImporte++;
		acumuladorImporte+=importe;

		if(flag == 0){
			minimoImporte = importe;
			minimoImportePais = origen;
			flag = 1;
		}else {
			if(minimoImporte > importe){
				minimoImporte = importe;
				minimoImportePais = origen;
			}
		}

		if(origen == 'c') {
			contadorProductosChina+= productos;
		}


	}

promedio= acumuladorImporte / contadorImporte;

	printf("\n El minimo importe es: %d y su pais es: %c", minimoImporte, minimoImportePais);
	printf("\n El promedio de los importes es: %d", promedio);
	printf("\n La cantidad de productos de china es: %d", contadorProductosChina);
	return EXIT_SUCCESS;
}
