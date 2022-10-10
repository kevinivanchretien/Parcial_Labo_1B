/*
 ============================================================================
 Name        : Parcial.c
 Author      : Kevin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//mis bibliotecas
#include "utn.h"
#include "fecha.h"
#include "peliculas.h"

#define TAMPELIS 5
int main(void) {

	setbuf(stdout,NULL);
	puts("!!! A Darle Atomos!!!"); /* prints !!! A Darle Atomos!!! */


	//char salir='N';

	//eFecha vFecha;
	ePelicula vPelicula[TAMPELIS]; //={1000,"Thor 45",90,"Taika Waikiki",{20,10,2045},100000000,1};

	inicializarPeliculas(vPelicula, TAMPELIS);
	harcodearPeliculas(vPelicula, TAMPELIS);
	mostrarPeliculas(vPelicula,TAMPELIS);


	/*do
	{
		switch(menu())
		{
			case 1:
				printf("\npelis");
				break;
			case 2:
				printf("\n actores");
				break;
			case 3:
				printf("\n informes.");
				break;
			case 4:
				funcionSalir(&salir,"Desea Salir (S/N): ","Error ",2);
				break;
		}
	}while(salir !='S');
	*/
	return EXIT_SUCCESS;
}
