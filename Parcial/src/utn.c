/*
 * utn.c
 *
 *  Created on: 17 sep. 2022
 *      Author: kevin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"
int utn_getEntero(int* pResultado,char* mensaje, char* mensajeError, int maximo, int minimo, int reintentos)
{
	int todoOk=-1;
	int bufferInt=0;

	if(pResultado != NULL && mensaje != NULL && mensajeError !=NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("\n %s", mensaje);
			scanf("%d", &bufferInt);

			if(bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado=bufferInt;
				todoOk=0;
				break;
			}
			else
			{
				printf("\n %s \n", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return todoOk;
}


int utn_getFlotante(float* pResultado,char mensaje[], char mensajeError[], float maximo, float minimo, int reintentos)
{
	int todoOk=-1;
	int bufferFloat=0;

	if(pResultado != NULL && mensaje != NULL && mensajeError !=NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("\n %s", mensaje);
			fflush(stdin);
			if(scanf("%d", &bufferFloat)==1)//si scanf devuelve 1 porque se ingreso un numero
			{
				if(bufferFloat>=minimo && bufferFloat<=maximo)
				{
					*pResultado=bufferFloat;
					todoOk=0;
					break;
				}
				else
				{
					printf("\n %s \n", mensajeError);
					reintentos--;
				}
			}
		}while(reintentos>=0);
	}
	return todoOk;
}


int utn_getCaracter(char* pResultado,char* mensaje, char* mensajeError, char maximo, char minimo,int reintentos)
{
	int todoOk=-1;
	char bufferChar=0;

	if(pResultado != NULL && mensaje != NULL && mensajeError !=NULL && minimo<=maximo && reintentos >=0)
	{
		do{
			printf("\n %s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar>=minimo && bufferChar<=maximo)
			{
				*pResultado=bufferChar;
				todoOk=0;
				break;
			}
			else
			{
				printf("\n %s \n", mensajeError);

				reintentos--;
			}
		}while(reintentos>=0);
	}
	return todoOk;
}




int funcionSalir(char* pRespuesta, char* mensaje, char* mensajeError,int reintentos)
{
	int todoOk=-1;
	char buffer;
	char bufferMayuscula;
	if(pRespuesta != NULL && mensaje !=NULL && mensajeError !=NULL && reintentos>=0)
	{
		do
		{
		printf("\n%s", mensaje);
		fflush(stdin);
		scanf("%c",  &buffer);
		bufferMayuscula=toupper(buffer);
		if(bufferMayuscula=='S' || bufferMayuscula == 'N')
		{
			*pRespuesta=bufferMayuscula;
			todoOk=1;
			break;
		}
		else
		{
			printf("\n %s ingreso %c", mensajeError, bufferMayuscula);
			reintentos--;

		}
		}while(reintentos>=0);
	}
	return todoOk;
}

int menu()
{
	int opcion=0;

	printf("\n    Menu    \n");

	printf("\n1. Gestion de Peliculas.");
	printf("\n2. Gestion de Actores.");
	printf("\n3. Informes.");
	printf("\n4. Salir");

	utn_getEntero(&opcion,"Opcion: ","Error opciones del 1 al 4 ",4,1,2);

	return opcion;
}



char subMenuPeliculas()
{
	char opcion;

	printf("A-ALTAS.\n");// TIENEN QUE SER HARCODEADAS
	printf("B-MODIFICAR.\n");// BAJA LOGICA. TAMBIEN DAR DE BAJA LOS ACTORES AFECTADOS
	printf("C-CALCULAR RECAUDACION.\n"); // SE CALCULARA DE MANERA ALEATORIA LA RECAUDACION

	utn_getCaracter(&opcion,"\nOpcion: ", "\nError ",'a','c',3);

	return opcion;
}



void convertirMayuscula(char cadena[], int size)
{
	int i;
	for(i=0;i <size;i++)
	{
		cadena[i]=toupper(cadena[i]);
	}
}
