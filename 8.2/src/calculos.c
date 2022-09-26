#include "calculos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initDatos(products apple[], int len) {
	int i;

	if (apple != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			apple[i].isEmpty = 0;
		}
	}

}

int encontrarId(products apple[], int len) {
	int i;
	int retorno = -1;
	if (apple != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (apple[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int deleteDatos(products apple[], int len) {

	int retorno = -1;
	if (apple != NULL && len > 0) {

		apple[len].isEmpty = 0;
		retorno = 0;
	}

	return retorno;
}

static int eGen_ObtenerID(void);
static int eGen_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eGen_ObtenerID();
	static int Gen_idIncremental = 0;
	return Gen_idIncremental++;
}

products eGen_CargarDatos(void) {
	products auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

int eGen_Alta(products array[], int TAM) {
	int rtn = 0;
	products apple;

	//BUSCO ESPACIO EN ARRAY
	int index = encontrarId(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		printf("Ingrese ID: \n");
		__fpurge(stdin);
		scanf("%d", &apple.idProduct);

		printf("Ingrese descripcion: \n");
		__fpurge(stdin);
		fgets(apple.description, 20, stdin);

		printf("Ingrese nacionalidad: \n");
		__fpurge(stdin);
		scanf("%d", &apple.nation);

		printf("Ingrese tipo: \n");
		scanf("%d", &apple.type);

		printf("Ingrese precio: \n");
		__fpurge(stdin);
		scanf("%f", &apple.price);
//		apple = eGen_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		apple.idProduct = eGen_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		apple.isEmpty = 1;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = apple;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

// mostrar productos

void eGen_MostrarUno(products Gen) {
//PRINTF DE UN SOLO Gen

	printf(
			"EL id es:%d \n La descripcion es: %s: \n La nacion es: %d \n EL precio es: %d \n Y el tipo es: %d \n",
			Gen.idProduct, Gen.description, Gen.nation, Gen.price, Gen.type);
}

int eGen_MostrarTodos(products array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Gen");
//	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == 1) {
				//MUESTRO UN SOLO Gen
				eGen_MostrarUno(array[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	} else {
		printf("No cargo ninguna alta");
	}

	return rtn;
}

