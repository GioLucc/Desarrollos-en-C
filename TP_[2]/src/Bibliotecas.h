/*
 * Bibliotecas.h
 *
 *  Created on: 1 oct. 2021
 *      Author: Giovanni
 */

#ifndef BIBLIOTECAS_H_
#define BIBLIOTECAS_H_
#include <stdlib.h>
#include <stdio.h>

#endif /* BIBLIOTECAS_H_ */

int getValidInt(char mensaje []);
int ValidadorNumero (char [],int numeroIngresado, int min, int max);
void IngresoVectores(int vectorNumeros[], int TAM);
void ValidadorVector (int vectorNumeros[], int min, int max ,int T);
int OnlyIntegrersValidation(char mensaje[], char error[],int min,int max);
int OnlyCharacterValidation(char str[]);
int OnlyFloatValidation(char str[]);
void MostrarNumeros(int vectorNumeros[], int TAM);
void getString(char mensaje[],char input[]);
void showString(char array[]);
void BubbleSortingPos (int vectorNumeros[],int TAM);
void BubbleSortingNeg (int vectorNumeros[],int TAM);
void ShowBubbleSortingPos(int vectorNumeros[], int TAM);
void ShowBubbleSortingNeg(int vectorNumeros[], int TAM);
int EvaluadorSigno (int numero);
void RertornarNombreCompleto (char nombre[], char apellido[], char nombreCompleto[]);
void FormartearCadena(char nombreCompleto[]);
int getFloatWithParams(char requestMessage[], char errorMessage[], float* input, float lowLimit, float hiLimit);
int getStringNumerosFlotantes(char mensaje[], char input[]);
int esNumericoFlotante(char str[]);


