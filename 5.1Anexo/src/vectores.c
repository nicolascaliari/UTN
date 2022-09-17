#include <stdio.h>
#include <stdlib.h>


int esNumerica(char cadena[]) {
	int i;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		for(i = 0; i < strlen(cadena); i++) {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}


int getInt(int *pResultado) {
	int ret = -1;
	char buffer[1024];

	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';

	if (esNumerica(buffer)) {
		*pResultado = atoi(buffer);
		ret = 1;
	}
	return ret;
}


int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {
	int ret;
	int num;
	while (reintentos > 0) {
		printf("%s", mensaje);
		__fpurge(stdin);
		if (getInt(&num) == 1) {
			if (num <= maximo && num >= minimo){
				break;
			}
		}
		reintentos--;
		printf("%s", mensajeError);
		__fpurge(stdin);
	}
	if (reintentos == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResultado = num;
	}
	return ret;
}

void mostrarMenu(int opciones){


	int edades[5];
	int flag =0;

	utn_getNumero(&opciones, "1.Inicializar\n 2.Cargar\n 3.Mostrar\n 4.Calcular promedio\n 5.Ordenar" , "error", 1,5,5);

	switch(opciones){

	case 1:
		iniciarlizarArray(edades, 5, 0);

		break;
	case 2:
		cargarEdades(edades, 5);
		flag =1;
		break;
	case 3:
		if(flag != 1){
			mostrarPorPantalla(edades , 5);
		}else {
			printf("NO podes ingresar\n");
		}

		break;
	case 4:
		calcularPromedio(edades);
		break;
	case 5:
		break;
	}


}


void iniciarlizarArray(int array[], int len, int inicial){
	int i;
		for(i=0 ; i < len ; i++){

				array[i] = inicial;
		}

}

int pedirEdades(void){
int numero;
char array[5];

printf("Ingrese su edad: ");
fgets(array, sizeof(array) , stdin);
array[strlen(array) - 1];

numero = atoi(array);

return numero;
}

void cargarEdades(int *array, int len){

	int acc = 0;
	for(int i = 0; i < len; i++){

		array[i] = pedirEdades();
		acc+=array[i];
	}
	printf("EL total es %d\n", acc);
}


void mostrarPorPantalla(int array[] , int len){

	for(int i = 0; i < len ; i++){

		printf("Las edades son: %i\n" ,array[i]);
	}
}




void calcularPromedio(int * array){

	float promedio;
	float acc = 0;
	for(int i =0; i< 5 ; i++){

		acc+=array[i];
	}

	promedio = acc / 5;
//	printf("El promedio es:  %.2f\n",promedio);


}
