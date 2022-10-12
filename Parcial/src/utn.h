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
#include <string.h>
#include <ctype.h>


/**
 *
 */
 //static int getInt(int* pResultado);


 //static int myGets(char* cadena, int tamanio);

 //static int esNumerica(char* cadena);

 //static int getInt(int* pResultado);

/*/ Pide un numero entero
 *
 */int utn_getEntero(int* pResultado,char* mensaje, char* mensajeError, int maximo, int minimo,int reintentos);

 int utn_getDouble(double* pResultado,char* mensaje, char* mensajeError, int maximo, int minimo,int reintentos);
 /*/ PIDE UN NUMERO FLOTANTE
 *
 */int utn_getFlotante(float* pResultado,char* mensaje, char* mensajeError, float maximo, float minimo, int reintentos);

/*/ PIDE UNA LETRA
 *
 */int utn_getCaracter(char* pResultado,char* mensaje, char* mensajeError, char maximo, char minimo,int reintentos);

 /**
  *
  */int utn_getCadena(char* pResultado, char* mensaje, char* mensajeError,int maximo, int minimo,int reintentos);




 /*/ VERIFICA QUE SOLO SE INGRESE S o N
  * PARA SALIR DEL MENU
  * @param pRespuesta
  *
  */int funcionSalir(char* pRespuesta, char* mensaje, char* mensajeError,int reintentos);



  /*/
   *
   */void convertirMayuscula(char cadena[], int size);

/*/
 *
 */int menu();

 /*/
  *
  */char subMenuPeliculas();


  int numeroAleatorio(int maximo, int minimo);

#endif /* UTN_H_ */

