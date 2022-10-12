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
#include <string.h>

//mis bibliotecas
#include "utn.h"
#include "fecha.h"
#include "peliculas.h"
#include "actor.h"

#define TAMPELIS 5
#define TAMACTORES 5
int main(void) {

	setbuf(stdout,NULL);
	puts("!!! A Darle Atomos!!!"); /* prints !!! A Darle Atomos!!! */


	char salir='N';
	//peliculas
	char salirPelis='N';
	int* codigoPeli=1000;
	int idPelicula;
	int indicePelicula;
	int indice=0;

	ePelicula vPelicula[TAMPELIS];

	//ACTORES
	eActor vActores[TAMACTORES];
	int* idActores=1;

	inicializarPeliculas(vPelicula, TAMPELIS);
	inicializarActores(vActores,TAMACTORES);


	harcodearActor(vActores,TAMACTORES);
	harcodearPeliculas(vPelicula, TAMPELIS);


	do
	{
		switch(menu())
		{
		case 1:
				printf("\n Peliculas.\n");
				do
				{
					switch(subMenuPeliculas())
					{
					case 1:
						printf("\nindice peli: %d \n",indice);
						indice=buscarEspacioLibre(vPelicula,TAMPELIS);
						printf("\nindice peli despues de buscar espacio libre: %d\n",indice);
						altaPeliculas(vPelicula,TAMPELIS,indice,*codigoPeli);
						//mostrarPeliculas(vPelicula,TAMPELIS);
						break;
					case 2:
						mostrarPeliculas(vPelicula,TAMPELIS);
						utn_getEntero(&idPelicula,"Codigo de la pelicula a dar de baja: ","Eror",3000,1000,3);
						indicePelicula = buscarCodigoPelicula(vPelicula,TAMPELIS,idPelicula);
						bajaPeliculas(vPelicula, TAMPELIS,indicePelicula);

						break;
					case 3:
						mostrarPeliculas(vPelicula,TAMPELIS);
					break;
					case 4:
						funcionSalir(&salirPelis,"Volver al menu Principal (S/N): ","opcion invalida ",2);
						break;
					}
				}while(salirPelis != 'S');
					break;
			case 2:
				printf("\nalta actores");
					altaActores(vActores,TAMACTORES,*idActores);
				break;
			case 3:
				printf("\n informes.");
				break;
			case 4:
				funcionSalir(&salir,"Desea Salir (S/N): ","Error ",2);
				break;
		}
	}while(salir !='S');

	return EXIT_SUCCESS;
}
