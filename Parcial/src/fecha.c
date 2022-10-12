/*
 * fecha.c
 *
 *  Created on: 9 oct. 2022
 *      Author: kevin
 */
#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "fecha.h"

int cargarFecha(eFecha fecha[])
{
	int todoOk=0;
	if(fecha!=NULL)
	{

		utn_getEntero(&fecha->mes,"Mes: ","Mes invalido.",12,1,3);
		if(fecha->mes==2)
		{
			utn_getEntero(&fecha->dia,"Dia: ","Dia invalido.",28,1,2);//febrero
		}
		else if(fecha->mes == 4 || fecha->mes == 6 || fecha->mes == 9 || fecha->mes == 11)
		{
			utn_getEntero(&fecha->dia,"Dia: ","Dia invalido.",30,1,2);//abril 4,junio 6,septiembre 9y noviembre 11
		}
		else
		{
			utn_getEntero(&fecha->dia,"Dia: ","Dia invalido.",31,1,2);
		}
		utn_getEntero(&fecha->anio,"Anio: ","Anio invalido.",3000,1939,3);


	}

		//mostrarFecha(fecha);

	return todoOk;
}


void mostrarFecha(eFecha* fecha)
{
	printf(" %2.d/%2d/%d \n", fecha->dia, fecha->mes, fecha->anio);
}


