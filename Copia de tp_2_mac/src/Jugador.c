#include <stdio.h>
#include <stdlib.h>
#include "salida_datos.h"
#include "Jugador.h"
#include "Confederacion.h"
#include "Validaciones.h"

/**
 *\brief: Otorga un ID autoincremental.
 *\param: ---
 *\return: retorna el id autoincrementado.
 **/
static int idJugador(void);
static int idJugador(void) {
	static int idIncremental = 1;
	return idIncremental++;
}

/**
 * \brief Inicia el campo isEmpty del array de tipo eJugador en 0
 * \param arrayRecurso Array de tipo recurso
 * \param limiteRecurso Limite del array
 * \return void
 *
 */
void inicializar_array(eJugador unJugador[], int limiteJugador) {
	int i;
	if (unJugador != NULL && limiteJugador > 0) {
		for (i = 0; i < limiteJugador; i++) {
			unJugador[i].isEmpty = 0;
		}
	}
}

/**
 * \brief Imprime los datos de un recurso
 * \param unRecurso variable de tipo recurso
 * \param arrayTipo de tipo tipo
 * \param limiteTipo Limite de tipo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int jugador_imprimir(eJugador unJugador, eConfederacion arrayConfederacion[],int limiteConfederacion)
{
	int retorno = -1;
	if (unJugador.isEmpty == 1 && arrayConfederacion != NULL && limiteConfederacion > 0)
	{
		for (int i = 0; i < limiteConfederacion; i++)
		{
			if (unJugador.idConfederacion == arrayConfederacion[i].id) {
				printf("  %d   |%10s        |%10s        |%10d       |%2.f        |%10d          |%10s\n\n",
					unJugador.id, unJugador.nombre, unJugador.posicion,
					unJugador.numeroCamiseta, unJugador.salario,
					unJugador.aniosContrato, arrayConfederacion[i].nombre);

			retorno = 0;
			}
		}

	}
	return retorno;
}

/**
 * \brief Imprime el array de recurso
 * \param arrayRecurso Array de tipo recurso
 * \param arrayTipo Array de tipo tipo
 * \param limiteRecurso Limite del array de recurso
 * \param limiteTipo Limite del array de tipo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int jugador_imprimirArray(eJugador arrayJugador[], int limiteJugador, eConfederacion arrayConfederacion[], int limiteConfederacion)
{
	int respuesta = -1;
	int i;
	if(arrayJugador != NULL && limiteJugador > 0)
	{
		printf("                     ***LISTA DE JUGADORES***\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("| ID  |      NOMBRE      |     POSICION     |   N DE CAMISETA |   SUELDO   | ANIOS DE CONTRATO  |    CONFEDERACION   |\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		for(i = 0; i < limiteJugador; i++)
		{
			jugador_imprimir(arrayJugador[i], arrayConfederacion,limiteConfederacion);
		}
		respuesta = 0;
	}

	return respuesta;
}

int alta_jugador(eJugador arrayJugador[], int limiteJugador, eConfederacion arrayConferacion[], int limiteConfederacion)
{
	int retorno = -1;
	eJugador auxiliar;
	int indice;

	if(arrayJugador != NULL && limiteJugador > 0)
	{
		indice = buscarEspacioLibre(arrayJugador, limiteJugador);

		if(indice != -1)
		{

			if(utn_getDescripcion(auxiliar.nombre, 50, "\nIngrese su nombre\n","\nERROR\n", 2) == 0
					&& utn_getDescripcion(auxiliar.posicion, 50,"Ingrese su posicion", "error", 2) == 0
					&& utn_getNumeroShort(&auxiliar.numeroCamiseta,"Ingrese su numero de camiseta", "error", 1, 90, 2) == 0
					&& utn_getNumeroFlotante(&auxiliar.salario,"Ingrese su salario", "error", 1, 600000, 2) == 0
					&& utn_getNumeroShort(&auxiliar.aniosContrato,"Ingrese anios de contrato", "error", 1, 50, 2)== 0)
					{
				auxiliar.idConfederacion = pedirConfederacion(arrayConferacion,limiteConfederacion);
			}
			auxiliar.isEmpty = 1;
			auxiliar.id = idJugador();
			arrayJugador[indice] = auxiliar;
			retorno = 0;
		}
	}
	return retorno;
}

int jugador_bajaArray(eJugador arrayJugador[], int limiteJugador)
{
	int retorno = -1;
	int id;
	int indice;

	if(arrayJugador != NULL && limiteJugador > 0)
	{
//		jugador_imprimirArray(arrayJugador, limiteJugador);
		if(utn_getNumero(&id, "\nIngrese el ID que desea dar de baja","\nError al ingresar id", 1, 20, 10000) == 0)
		{

			while (recurso_buscarId(arrayJugador, limiteJugador, id) == -1) {
				puts("\nNO EXISTE ID.");
				utn_getNumero(&id, "\nIngrese el ID que desea dar de baja",
						"\nError al ingresar id", 1, 20, 10000);
			}

			indice = recurso_buscarId(arrayJugador, limiteJugador, id);
			arrayJugador[indice].isEmpty = 0;
			retorno = 0;
		}
	}

	return retorno;
}

int recurso_modificarRecurso(eJugador arrayJugador[], int limiteJugador) {

	int retorno = -1;
	int id;
	int indice;
	int opcion;

	if (arrayJugador != NULL && limiteJugador > 0) {

//		jugador_imprimirArray(arrayJugador, limiteJugador);

		if (utn_getNumero(&id, "Ingrese el ID que desea modificar",
				"Error al ingresar id", 0, 20, 3) == 0) {

			while (recurso_buscarId(arrayJugador, limiteJugador, id) == -1) {
				puts("NO EXISTE ID.");
				utn_getNumero(&id, "Ingrese el ID que desea modificar",
						"Error al ingresar id", 0, 20, 3);
			}

			indice = recurso_buscarId(arrayJugador, limiteJugador, id);

			if (indice != -1) {

				if (utn_getNumero(&opcion, "\nMenu para modificar recurso"
						"\n\n1.Ingrese 1 para modificar nombre del jugador"
						"\n2.Ingrese 2 para modificar la posicion del jugador"
						"\n3.Ingrese 3 para modificar el numero de camiseta"
						"\n4.Ingrese 4 para modificar el salario"
						"\n5.Ingrese 5 para modificar los anios de contrato",
						"\nError opcion invalida", 1, 5, 2) == 0) {
					switch (opcion) {
					case 1:
						utn_getDescripcion(arrayJugador[indice].nombre, 50,
								"\nIngrese el nuevo nombre\n", "\nERROR\n",
								1000000);
						retorno = 0;
						break;
					case 2:
						utn_getDescripcion(arrayJugador[indice].posicion, 50,
								"\nIngrese la posicion a modificar\n",
								"\nERROR\n", 1000000);
						retorno = 0;
						break;
					case 3:
						utn_getNumeroShort(&arrayJugador[indice].numeroCamiseta,
								"Ingrese su numero de camiseta nuevo", "error",
								1, 90, 2);
						retorno = 0;
						break;
					case 4:
						utn_getNumeroFlotante(&arrayJugador[indice].salario,
								"\nIngrese el nuevo salario\n", "\nERROR\n", 1,
								10000, 100000);
						retorno = 0;
						break;
					case 5:
						utn_getNumeroShort(&arrayJugador[indice].aniosContrato,
								"Ingrese su numero de camiseta", "error", 1, 90,
								2);
						retorno = 0;
						break;
					}

				}

			}

		}
	}
	return retorno;
}

int recurso_buscarId(eJugador arrayJugador[], int limiteJugador,
		int valorBuscado) {
	int respuesta = -1;
	int i;
	if (arrayJugador != NULL && limiteJugador > 0 && valorBuscado > 0) {
		for (i = 0; i < limiteJugador; i++) {
			if (arrayJugador[i].id == valorBuscado) {
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

int buscarEspacioLibre(eJugador arrayJugador[], int limiteJugador) {
	int i;
	int retorno = -1;
	if (arrayJugador != NULL && limiteJugador > 0) {
		for (i = 0; i < limiteJugador; i++) {
			if (arrayJugador[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
 *\brief: Verifica que haya espacio para cargar un nuevo dato de tipo transporte.
 *\param: Array de tipo transporte, Longitud del array.
 *\return: Retorna 1 si encuentra espacio, Retorna 0 si no lo encuentra.
 **/
int buscarEspacio(eJugador arrayJugador[], int limiteJugador) {
	int retorno = 0;
	if (arrayJugador != NULL && limiteJugador > 0) {
		for (int i = 0; i < limiteJugador; i++) {

			if (arrayJugador[i].isEmpty == 0) {
				retorno = 1;
			}
		}
	}
	return retorno;
}
