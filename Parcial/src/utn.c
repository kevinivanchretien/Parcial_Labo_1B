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
#include <time.h>


#include "utn.h"




static int myGets(char* cadena, int tamanio)
{
	int retorno=-1;
	if(cadena != NULL && tamanio >0 && fgets(cadena,tamanio,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]='\0';
		}
		retorno=0;
	}
	return retorno;
}


static int esNumerica(char* cadena)
{
	int retorno=-1;
	int i=0;


	if(cadena!= NULL && strlen(cadena)>0)
	{
		if(cadena[0]== '-')
		{
			i=1;
		}
		for(  ;cadena[i] != '\0';i++)
		{
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

static int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado!=NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
		{
			*pResultado=atoi(buffer);//atoi cambia los caracteres a numeros
			retorno=0;

		}

	}

	return retorno;
}

int utn_getEntero(int* pResultado,char* mensaje, char* mensajeError, int maximo, int minimo, int reintentos)
{
	int todoOk=-1;
	int bufferInt=0;

	if(pResultado != NULL && mensaje != NULL && mensajeError !=NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("\n %s", mensaje);
			if(getInt(&bufferInt)==0)
			{
				if(bufferInt>=minimo && bufferInt<=maximo)
				{
					*pResultado=bufferInt;
					todoOk=0;
					break;
				}
				else
				{
					printf("\n %s ", mensajeError);
					reintentos--;
				}
			}

		}while(reintentos>=0);
	}
	return todoOk;
}


int utn_getFlotante(float* pResultado,char mensaje[], char mensajeError[], float maximo, float minimo, int reintentos)
{
	int todoOk=-1;
	float bufferFloat=0;

	if(pResultado != NULL && mensaje != NULL && mensajeError !=NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("\n %s", mensaje);
			fflush(stdin);
			if(scanf("%f", &bufferFloat)==1)//si scanf devuelve 1 porque se ingreso un numero
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


int utn_getCadena(char* pResultado, char* mensaje, char* mensajeError,int maximo, int minimo,int reintentos)
{
	int todoOk;
	char buffer[64];

	if(pResultado != NULL && mensaje != NULL && mensajeError !=NULL &&maximo>=minimo && reintentos>0)
	{
		do{
			printf("\n %s", mensaje);
			gets(buffer);
			if(strlen(buffer)>=minimo &&  strlen(buffer)<=maximo)
			{
				strcpy(pResultado,buffer);
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

void convertirMayuscula(char cadena[], int size)
{
	int i;
	for(i=0;i <size;i++)
	{
		cadena[i]=toupper(cadena[i]);
	}
	return;
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
	int opcion;

	printf("1-ALTAS.\n");// TIENEN QUE SER HARCODEADAS
	printf("2-MODIFICAR.\n");// BAJA LOGICA. TAMBIEN DAR DE BAJA LOS ACTORES AFECTADOS
	printf("3-CALCULAR RECAUDACION.\n"); // SE CALCULARA DE MANERA ALEATORIA LA RECAUDACION
	printf("4-<-Menu Principal.\n");
	utn_getEntero(&opcion,"Opcion: ", "\nError opciones del 1 al 3",4,1,2);


	return opcion;
}



int utn_getDouble(double* pResultado,char* mensaje, char* mensajeError, int maximo, int minimo,int reintentos)
{
	int todoOk=-1;
	double buffer=0;

	if(pResultado != NULL && mensaje != NULL && mensajeError !=NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("\n %s", mensaje);
			fflush(stdin);
			if(scanf("%lf", &buffer)==1)//si scanf devuelve 1 porque se ingreso un numero
			{
				if(buffer>=minimo && buffer<=maximo)
				{
					*pResultado=buffer;
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


int numeroAleatorio(int maximo, int minimo)
{
	int resultado=0;
    double numero=0;

    numero = rand()% (maximo-minimo)+maximo;
    printf("\n %lf\n ", numero);


	return resultado;
}
