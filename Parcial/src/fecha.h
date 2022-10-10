/*
 * fecha.h
 *
 *  Created on: 9 oct. 2022
 *      Author: kevin
 */

#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

#endif /* FECHA_H_ */



/*/
 *
 */int cargarFecha(eFecha fecha[]);

 void mostrarFecha(eFecha* fecha);
