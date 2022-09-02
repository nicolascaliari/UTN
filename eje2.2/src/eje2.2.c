/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
     int ingresarNumero;
	    int contadorPares = 0;
	    int contadorImpares = 0;
	    int menorNumero;
	    int flag;



	    flag = 1;

	    for(int i = 0; i < 4; i++){
	    printf("Ingresa un numero:  ");
	    scanf("%d" , &ingresarNumero);
	    while(ingresarNumero == 0){
	        printf("ERROR, Ingresa un numero:  ");
	        scanf("%d" , &ingresarNumero);
	    }

	        if(ingresarNumero%2 == 0 ){
	            contadorPares++;

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

	    }

	    printf("La cantidad de pares es: %d, la cantidad de impares es: %d y el menor numero es: %d ",
	    		contadorPares , contadorImpares , menorNumero);

    return 0;
}
