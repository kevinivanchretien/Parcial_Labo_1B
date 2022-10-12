/*
 * peliculas.h
 *
 *  Created on: 10 oct. 2022
 *      Author: kevin
 */

#ifndef PELICULAS_H_
#define PELICULAS_H_

#include "fecha.h"

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int codigoPelicula;
	char titulo[25];
	int duracion;
	char director[25];
	eFecha estreno;
	double recaudacion;
	int oscar;// 1 si 0 no
	int isEmpty;

}ePelicula;


#endif /* PELICULAS_H_ */


void inicializarPeliculas(ePelicula peliculas[],int size);

void mostrarUnaPelicula(ePelicula peliculas);

void mostrarPeliculas(ePelicula peliculas[], int size);

int harcodearPeliculas(ePelicula peliculas[], int size);

int buscarEspacioLibre(ePelicula peliculas[], int size);

int buscarCodigoPelicula(ePelicula peliculas[], int size, int valorBuscado);

int bajaPeliculas(ePelicula peliculas[],int size, int indice);

int altaPeliculas(ePelicula peliculas[], int size, int indice, int* id);
