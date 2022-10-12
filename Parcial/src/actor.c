/*
 * actor.c
 *
 *  Created on: 12 oct. 2022
 *      Author: kevin
 */


#include "actor.h"


void inicializarActores(eActor actores[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		actores[i].isEmpty=LIBRE;
	}
}

int buscarEspacioLibreActores(eActor actores[], int size)
{
	int indice;
    indice = -1;
    if(actores!=NULL && size >=0)
    {
    	for(int i=0; i<size; i++)
    	{
    	  if(actores[i].isEmpty==LIBRE)
    	  {
    		  indice = i;
    	      break;
    	   }
    	}
    }
    return indice;
}

int altaActores(eActor actores[], int size,int* id)
{
	int todoOk=0;
	int indice;
	eActor buffer;
	if(actores !=NULL && size>0 && id>=0)
	{
		utn_getCadena(buffer.nombre,"Nombre del actor: ","Error. ",30,1,3);
		//printf("\nnombre: %s",buffer.nombre);
		utn_getCadena(buffer.apellido,"Apellido del actor: ","Error. ",30,1,3);
		//printf("\napellido: %s",buffer.apellido);
		utn_getEntero(&buffer.idPelicula,"Ingrese el codigo de la pelicula: ","Error ese codigo no Existe",2000,1000,3);
		//printf("\nid peli: %d",buffer.idPelicula);
		utn_getCadena(buffer.nombrePersonaje,"Nombre del personaje: ","Error",64,1,3);
		//printf("\nnombre del personaje: %s",buffer.nombrePersonaje);
		utn_getCadena(buffer.rol,"Rol del personaje: ","Error Heroe/Villano/Secundario",64,1,3);
		//printf("\nrol del personaje: %s",buffer.rol);
		utn_getDouble(&buffer.contrato,"Sueldo Mensual","Error.",1000000,0,3);
		//utn_getFlotante(&buffer.contrato,"Sueldo Mensual","Error.",1000000,0,3);
		//printf("\nsueldo: %lf",buffer.contrato);
		printf("\nInicio del contrato.");
		cargarFecha(&buffer.inicioContrato);
		mostrarFecha(&buffer.inicioContrato);

		printf("\nFin del contrato.");
		cargarFecha(&buffer.finContrato);
		mostrarFecha(&buffer.finContrato);

		buffer.codigoActor=*id;
		id++;
		buffer.isEmpty=OCUPADO;
		buffer.oscar=0;
		indice=buscarEspacioLibreActores(actores,size);



		/*actores[indice].codigoActor=*id;
		actores[indice].isEmpty=OCUPADO;
		actores[indice].oscar=0;
		id++;*/
		actores[indice]=buffer;

		printf(" ______________________________________________________________________________________________________________________\n");
		printf("|_Codigo_|___Nombre___|___Apellido___|__Personaje__|____Rol____|____Valor____|_Fecha Inicio_|__Fecha fin__|_Gano Oscar_|\n");
		mostrarUnActor(actores[indice]);
	}

	return todoOk;
}




int bajaActores(eActor actores[],int size, int indice)
{
	int todoOk=-1;

	if(actores !=NULL && size>=0 && actores[indice].isEmpty==OCUPADO)
	{
		actores[indice].isEmpty=LIBRE;
		todoOk=0;
	}
	return todoOk;
}



void mostrarUnActor(eActor actor)
{
	///		Id	  nombre  apelli personaj  ROL
printf("|  %3d   | %-10s | %-12s | %-10s  |  %-8s |  %0.2lf  |  %02d/%02d/%d  |  %02d/%02d/%d |     %d      |\n",	actor.codigoActor,
																									actor.nombre,
																									actor.apellido ,
																									//actor.idPelicula ,
																									actor.nombrePersonaje,
																									actor.rol,
																									actor.contrato,
																									actor.inicioContrato.dia,
																									actor.inicioContrato.mes,
																									actor.inicioContrato.anio,
																									actor.finContrato.dia,
																									actor.finContrato.mes,
																									actor.finContrato.anio,
																									actor.oscar);
}





void mostrarActores(eActor actores[], int size)
{
	int i;
	printf(" ______________________________________________________________________________________________________________________\n");
	printf("|_Codigo_|___Nombre___|___Apellido___|__Personaje__|____Rol____|____Valor____|_Fecha Inicio_|__Fecha fin__|_Gano Oscar_|\n");
	for(i=0;i<size;i++)
	{
		if(actores[i].isEmpty==OCUPADO)
		{
			mostrarUnActor(actores[i]);
		}
	}

}


int harcodearActor(eActor actores[], int size)
{
	int todoOk=0;
	int i;
	if(actores != NULL && size>=0)
		{
			for(i=0;i<size;i++)
			{
				actores[0].codigoActor=1;
				strcpy(actores[0].nombre,"German");
				strcpy(actores[0].apellido,"Scarafino");
				strcpy(actores[0].nombrePersonaje,"Malefica");
				strcpy(actores[0].rol,"Villano");
				actores[0].contrato=150000;
				actores[0].inicioContrato.dia=20;
				actores[0].inicioContrato.mes=8;
				actores[0].inicioContrato.anio=2022;
				actores[0].finContrato.dia=31;
				actores[0].finContrato.mes=12;
				actores[0].finContrato.anio=2022;
				actores[0].oscar=0;
				actores[0].isEmpty=OCUPADO;
			}

		}
		return todoOk;
}
