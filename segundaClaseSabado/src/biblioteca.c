#include <stdio.h>
#include <stdlib.h>

int pedirEntero(void)
{
	int pedirNumero;

	printf("Ingrese un numero: ");
	scanf("%d", &pedirNumero);

	return pedirNumero;
}


int calcularPromedio(int numeroUno, int numeroDos)
{
	int promedio;

	promedio =(numeroUno + numeroDos)/2;

	return promedio;
}


int verificarRetorno(int numeroEntero){


	return numeroEntero;

}


int ingresarDiezNumeros(){
	int ingresarNumero;
	int promedio;
	int contadorPositivos = 0;
	int acumuladorPositivos = 0;
	int contadorCeros = 0;

	for(int i = 0; i < 10 ; i++){
		printf("Ingrese un numero: ");
		scanf("%d", &ingresarNumero);

		if(ingresarNumero > 0)
		{
			contadorPositivos++;
			acumuladorPositivos+= ingresarNumero;
		}else
		{
			if(ingresarNumero == 0){
				contadorCeros++;
			}
		}
	}

	promedio = acumuladorPositivos / contadorPositivos;

	printf("\n El promedio de los positivos es: %d", promedio);
	printf("\n La cantidad de ceros es: %d", contadorCeros);
}
