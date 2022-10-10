/*
 * utn.h
 *
 *  Created on: 17 sep. 2022
 *      Author: kevin
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>
#include <stdlib.h>

/*/ Pide un numero entero
 *
 */int utn_getEntero(int* pResultado,char* mensaje, char* mensajeError, int maximo, int minimo,int reintentos);

 /*/ PIDE UN NUMERO FLOTANTE
 *
 */int utn_getFlotante(float* pResultado,char* mensaje, char* mensajeError, float maximo, float minimo, int reintentos);

/*/ PIDE UNA LETRA
 *
 */int utn_getCaracter(char* pResultado,char* mensaje, char* mensajeError, char maximo, char minimo,int reintentos);

 /*/ VERIFICA QUE SOLO SE INGRESE S o N
  * PARA SALIR DEL MENU
  * @param pRespuesta
  *
  */int funcionSalir(char* pRespuesta, char* mensaje, char* mensajeError,int reintentos);



/*/
 *
 */int menu();

 /*/
  *
  */char subMenuPeliculas();

/*/
 *
 */void convertirMayuscula(char cadena[], int size);


#endif /* UTN_H_ */

