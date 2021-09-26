/*
 * input.h
 *
 *  Created on: 11 sep. 2021
 *      Author: Giovanni
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

/// @fn float FuncionSuma(float, float)
/// @brief esta funcion se encarga de recibir dos parametros numericos, realizar un calculo dentro de la misma y devolverlo para mostrarlo.
///
/// @param primerOperando es el primer numero ingresado por el usuario.
/// @param segundoOperando es el primer segundo ingresado por el usuario.
/// @return el resultado de la suma de primerOperando + segundoOperando.
float FuncionSuma (float primerOperando, float segundoOperando);

/// @fn float FuncionResta(float, float)
/// @brief esta funcion se encarga de recibir dos parametros numericos, realizar un calculo dentro de la misma y devolverlo para mostrarlo.
///
/// @param primerOperando es el primer numero ingresado por el usuario.
/// @param segundoOperando es el primer segundo ingresado por el usuario.
/// @return el resultado de la resta de primerOperando - segundoOperando.
float FuncionResta (float primerOperando, float segundoOperando);

/// @fn float FuncionMultiplicacion(float, float)
/// @brief esta funcion se encarga de recibir dos parametros numericos, realizar un calculo dentro de la misma y devolverlo para mostrarlo.
///
/// @param primerOperando es el primer numero ingresado por el usuario.
/// @param segundoOperando es el primer segundo ingresado por el usuario.
/// @return el resultado de la multiplicacion de primerOperando * segundoOperando.
float FuncionMultiplicacion (float primerOperando, float segundoOperando);

/// @fn float FuncionDivision(float, float)
/// @brief esta funcion se encarga de recibir dos parametros numericos, realizar un calculo dentro de la misma y devolverlo para mostrarlo.
///
/// @param primerOperando es el primer numero ingresado por el usuario.
/// @param segundoOperando es el primer segundo ingresado por el usuario.
/// @return el resultado de la division de primerOperando / segundoOperando.
float FuncionDivision (float primerOperando, float segundoOperando);


/// @fn float FuncionFactorial(float, float*)
/// @brief esta funcion se encarga de recibir un parametro numerico, realizar un calculo dentro de la misma y devolverlo mediante un puntero para mostrarlo.
///
/// @param operando es el unico numero que recibe para poder realizar el factorial de dicho numero
/// @return devuelve 1 o 0 depende de si se pudo hacer o no, y el resultado mediante puntero si se pudo llegar al mismo.
int FuncionFactorial(float operando,float *numeroDevuelto);

/// @fn float IngreseOperandosMasVerificacion(char[], float*)
/// @brief esta funcion se encarga de pedir un texto(numeros usados para las operaciones) y comprueba que no sean letras y deja pasar las execepciones de - o .
///
/// @param mensaje mediante este parametro se le pasa el mensaje predeterminado que pedira el printf dentro de la funcion y hacia el puntero para devolver el puntero con el numero validado
/// @return devuelve el numero validado o pide el reingreso del mismo
int IngreseOperandosMasVerificacion(char mensaje[], float *operandoValidado);


#endif /* INPUT_H_ */
