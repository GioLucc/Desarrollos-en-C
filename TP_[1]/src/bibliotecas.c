/*
 * input.c
 *
 *  Created on: 11 sep. 2021
 *      Author: Giovanni
 */

#include "bibliotecas.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define T 100


float FuncionSuma (float primerOperando, float segundoOperando)
{
	float resultado;

	resultado = (float)primerOperando + segundoOperando;

	return resultado;

}

float FuncionResta (float primerOperando, float segundoOperando)
{
	float resultado;

	resultado = (float)primerOperando - segundoOperando;

	return resultado;
}

float FuncionMultiplicacion (float primerOperando, float segundoOperando)
{
	float resultado;

	resultado = (float)primerOperando * segundoOperando;

	return resultado;
}

float FuncionDivision (float primerOperando, float segundoOperando)
{
	float resultadoDivision;

	resultadoDivision = primerOperando / segundoOperando;

	return resultadoDivision;
}

int FuncionFactorial(float operando,float *numeroDevuelto)
{
    int i;
    int retorno;

    if(operando==(int)operando)
    {
        if(operando==0)
        {
			retorno=1;
			*numeroDevuelto=1;
        }
        else
        {
            if(operando>0)
            {
                retorno=1;
                for(i=(operando-1);i>0;i--)
                {
                	operando*=i;
                }
            }
        }
        *numeroDevuelto=operando;
    }
    else
    {
        retorno=0;
    }

    return retorno;
}

int IngreseOperandosMasVerificacion(char mensaje[], float* operandoValidado)
{

    char numeroIngresado[20];
    int auxI=0;
    int esNegativo=0;
    int contadorDePuntos=0;
    int retorno=1;

    printf("%s",mensaje);
    scanf("%s",numeroIngresado);

    if(numeroIngresado[0]=='-')
    {
		auxI=1;
		esNegativo=1;
    }

    for(int i=auxI; numeroIngresado[i]!='\0'; i++)
    {

    	if(numeroIngresado[i]<'.' || (numeroIngresado[i]>'.' && numeroIngresado[i]<'0') || numeroIngresado[i]>'9')
        {
            retorno=0;
            break;
        }
        else
        {
			if(numeroIngresado[i]=='.')
			{
				contadorDePuntos++;
				if(contadorDePuntos>1 || (esNegativo==0&&i==0) || (esNegativo==1&&i==1))
				{
					retorno=0;
					break;
				}
            }
        }
    }

    *operandoValidado = atof(numeroIngresado);
    return retorno;
}
/*
 * bibliotecas.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Giovanni
 */


