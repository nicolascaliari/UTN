/*
 ============================================================================
 Name        : 1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int ingresarNumero;
    float promedio;
    int contadorNumero = 0;
    int acumuladorNumero = 0;

    for(int i = 0; i < 5; i++){

        printf("Ingrese un numero");
        scanf("%d" , &ingresarNumero);

        contadorNumero++;
        acumuladorNumero+=ingresarNumero;
    }
    promedio = (float)acumuladorNumero / contadorNumero;
    printf("El promedio es %.2f" , promedio);


    return 0;
}
