/*
 * peliculas.c
 *
 *  Created on: 10 oct. 2022
 *      Author: kevin
 */

#include <stdio.h>
#include <string.h>


#include "peliculas.h"
#include "fecha.h"
#include "utn.h"

void inicializarPeliculas(ePelicula peliculas[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		peliculas[i].isEmpty=LIBRE;
	}
}

void mostrarUnaPelicula(ePelicula peliculas)
{

	printf("|  %3d  |  %-20s |    %4d'   | %-25s |   %02d/%02d/%d  | $%-11.0lf |       %d       |\n",	peliculas.codigoPelicula,
																							peliculas.titulo,
																							peliculas.duracion,
																							peliculas.director,
																							peliculas.estreno.dia,
																							peliculas.estreno.mes,
																							peliculas.estreno.anio,
																							peliculas.recaudacion,
																							peliculas.oscar);
}


void mostrarPeliculas(ePelicula peliculas[], int size)
{
	int i;
	printf(" ________________________________________________________________________________________________________________________\n");
	printf("|_Codigo_|_________Titulo________|__Duracion__|__________Director_________|_Fecha Estreno_|_Recaudacion__|_Gano un Oscar_|\n");
	for(i=0;i<size;i++)
	{
		if(peliculas[i].isEmpty==OCUPADO)
		{
			mostrarUnaPelicula(peliculas[i]);
		}
	}

}


int harcodearPeliculas(ePelicula peliculas[], int size)
{
	int todoOk=0;
	int i;
	if(peliculas != NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			peliculas[0].codigoPelicula=1000;
			strcpy(peliculas[0].titulo,"Thor 45");
			peliculas[0].duracion=90;
			strcpy(peliculas[0].director,"Taika Waikiki");
			peliculas[0].estreno.dia=20;
			peliculas[0].estreno.mes=10;
			peliculas[0].estreno.anio=2045;
			peliculas[0].recaudacion=100000000;
			peliculas[0].oscar=1;
			peliculas[0].isEmpty=OCUPADO;


			peliculas[1].codigoPelicula=1100;
			strcpy(peliculas[1].titulo,"Iron-man resureccion");
			peliculas[1].duracion=150;
			strcpy(peliculas[1].director,"Akira Toriyama");
			peliculas[1].estreno.dia=28;
			peliculas[1].estreno.mes=2;
			peliculas[1].estreno.anio=2051;
			peliculas[1].recaudacion=150000000;
			peliculas[1].oscar=0;
			peliculas[1].isEmpty=OCUPADO;


			peliculas[2].codigoPelicula=1200;
			strcpy(peliculas[2].titulo,"Ant-man 3");
			peliculas[2].duracion=100;
			strcpy(peliculas[2].director,"Sacarias Flores del Campo");
			peliculas[2].estreno.dia=15;
			peliculas[2].estreno.mes=12;
			peliculas[2].estreno.anio=2101;
			peliculas[2].recaudacion=75000000;
			peliculas[2].oscar=0;
			peliculas[2].isEmpty=OCUPADO;
		}
	}

	return todoOk;
}



int buscarEspacioLibre(ePelicula peliculas[], int size)
{
	int indice;
    indice = -1;
    if(peliculas!=NULL && size >=0)
    {
    	for(int i=0; i<size; i++)
    	{
    	  if(peliculas[i].isEmpty==LIBRE)
    	  {
    		  indice = i;
    	      break;
    	   }
    	  else
    	  {
    		  printf("Ya no quedan set para otra pelicula");
    	  }
    	}
    }
    return indice;
}


int altaPeliculas(ePelicula peliculas[], int size, int indice, int* id)
{
	int todoOk=0;
	double numero=0;;
	ePelicula bufferPelicula;
	if(peliculas != NULL && size >=0 && indice < size && indice>=0 && id !=NULL)
	{

			todoOk=1;
			bufferPelicula.codigoPelicula=*id;
			utn_getCadena(bufferPelicula.titulo,"Titulo de la pelicula: ","  ",30,1,3);
			utn_getEntero(&bufferPelicula.duracion,"Duracion de la pelicula (en minutos): ","Error ",360,15,3);
			utn_getCadena(bufferPelicula.director,"Nombre del director: ","Error.",30,1,3);
			printf("Fecha de estreno.");
			cargarFecha(&bufferPelicula.estreno);
			numero=numeroAleatorio(750000000,150000000);
			printf("numero aleatorio devuelve %0.2lf",numero);
			bufferPelicula.oscar=0;

			bufferPelicula.isEmpty=OCUPADO;
			peliculas[indice]=bufferPelicula;
			id = id +100;

			mostrarUnaPelicula(bufferPelicula);
	}

	return todoOk;
}


int bajaPeliculas(ePelicula peliculas[],int size, int indice)
{
	int todoOk=-1;

	if(peliculas !=NULL && size>=0 && peliculas[indice].isEmpty==OCUPADO)
	{
		peliculas[indice].isEmpty=LIBRE;
		todoOk=0;
	}
	return todoOk;
}

int buscarCodigoPelicula(ePelicula peliculas[], int size, int valorBuscado)
{
	int respuesta=-1;
	int i;
	if(peliculas != NULL && size >=0 && valorBuscado >=0)
	{
		for(i=0;i<size;i++)
		{
			if(peliculas[i].codigoPelicula==valorBuscado)
			{
				respuesta=i;
				break;
			}
		}
	}
	return respuesta;
}
