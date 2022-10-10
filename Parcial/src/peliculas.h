/*
 * peliculas.h
 *
 *  Created on: 10 oct. 2022
 *      Author: kevin
 */

#ifndef PELICULAS_H_
#define PELICULAS_H_

#include "fecha.h"

typedef struct
{
	int codigoPelicula;
	char titulo[25];
	int duracion;
	char director[25];
	eFecha estreno;
	int recaudacion;
	int oscar;// 1 si 0 no
	int isEmpty;

}ePelicula;


#endif /* PELICULAS_H_ */


void inicializarPeliculas(ePelicula peliculas[],int size);

void mostrarUnaPelicula(ePelicula peliculas);

void mostrarPeliculas(ePelicula peliculas[], int size);

int harcodearPeliculas(ePelicula peliculas[], int size);
