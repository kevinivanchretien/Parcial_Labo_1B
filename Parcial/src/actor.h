/*
 * actor.h
 *
 *  Created on: 12 oct. 2022
 *      Author: kevin
 */

#ifndef ACTOR_H_
#define ACTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fecha.h"
#include "utn.h"
#include "peliculas.h"

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int codigoActor;
	char nombre[25];
	char apellido[25];
	int idPelicula;
	char nombrePersonaje[25];
	char rol[25];
	double contrato;
	eFecha inicioContrato;
	eFecha finContrato;
	int oscar;// 1 si 0 no
	int isEmpty;

}eActor;

#endif /* ACTOR_H_ */



void inicializarActores(eActor actores[],int size);
int buscarEspacioLibreActores(eActor actores[], int size);

int altaActores(eActor actores[], int size,int* id);

int bajaActores(eActor actores[],int size, int indice);

void mostrarUnActor(eActor actor);

void mostrarActores(eActor actores[], int size);

int harcodearActor(eActor actores[], int size);
