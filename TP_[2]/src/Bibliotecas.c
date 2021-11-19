/*
 * Bibliotecas.c
 *
 *  Created on: 1 oct. 2021
 *      Author: Giovanni
 */

/*
 * BibiliotecasDef.c
 *
 *  Created on: 14 sep. 2021
 *      Author: giova
 */

#include "Bibliotecas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define T 100


int getValidInt(char mensaje [])
{
	int enteredNumber;

	printf("%s", mensaje);
	scanf("%d", &enteredNumber);

	return enteredNumber;
}

int ValidadorNumero (char error[], int numeroIngresado, int min, int max)
{
	while(numeroIngresado < min || numeroIngresado > max)
	{
		printf("%s",error);
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}

void IngresoVectores(int vectorNumeros[], int TAM)
{
	for(int i=0;i<TAM;i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &vectorNumeros[i]);
	}
}

void ValidadorVector (int vectorNumeros[], int min, int max ,int tam)
{
	while(vectorNumeros[T] < min || vectorNumeros[T] > max)
	{
		printf("ERROR - INGRESE NUEVAMENTE EL NUMERO: ");
		scanf("%d", &vectorNumeros[T]);
	}
}

void MostrarNumeros(int vectorNumeros[], int TAM)
{
	int contadorPosicionNumeros;

	contadorPosicionNumeros = 1;

	printf("\n * Los Numeros Ingresados fueron: *\n\n");
	for(int i=0;i<TAM;i++)
	{
		printf("%d.  [ %d ]\n",contadorPosicionNumeros++,vectorNumeros[i]);
	}
}

void getString(char mensaje[],char str[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]s", str);

    OnlyCharacterValidation(str);
}

void showString(char array[])
{
	printf("\nEl nombre ingresado fue: %s\n", array);
}

void BubbleSortingPos (int vectorNumeros[],int TAM)
{
	int aux;

	for (int i=0;i<TAM;i++)
	{
		if(EvaluadorSigno(vectorNumeros[i])==1)
		{
			for(int i=0;i<TAM-1;i++)
			{
				for(int j=i+1;j<TAM;j++)
				{
					if(vectorNumeros[i]>vectorNumeros[j])
					{
						aux = vectorNumeros[i];
						vectorNumeros[i] = vectorNumeros[j];
						vectorNumeros[j] = aux;
					}
				}
			}
		}
	}
}

void BubbleSortingNeg (int vectorNumeros[],int TAM)
{
	int aux;

	for (int i=0;i<TAM;i++)
	{
		if(EvaluadorSigno(vectorNumeros[i])==0)
		{
			for(int i=0;i<TAM-1;i++)
			{
				for(int j=i+1;j<TAM;j++)
				{
					if(vectorNumeros[i]<vectorNumeros[j])
					{
						aux = vectorNumeros[i];
						vectorNumeros[i] = vectorNumeros[j];
						vectorNumeros[j] = aux;
					}
				}
			}
		}
	}
}

void ShowBubbleSortingPos (int vectorNumeros[], int TAM)
{
	int contadorPosicionNumeros;

		contadorPosicionNumeros = 0;

	printf("\n\nLos numeros positivos fueron ordenados y quedaron de esta manera: \n\n");

	for(int i=0;i<TAM;i++)
	{
		contadorPosicionNumeros++;
		if(vectorNumeros[i] > 0)
		{
			printf("%d.  %d\n", contadorPosicionNumeros,vectorNumeros[i]);
		}
	}
}

void ShowBubbleSortingNeg (int vectorNumeros[], int TAM)
{
	int contadorPosicionNumeros;

		contadorPosicionNumeros = 0;

	printf("\n\nLos numeros negativos fueron ordenados y quedaron de esta manera: \n\n");

	for(int i=0;i<TAM;i++)
	{
		contadorPosicionNumeros++;
		if(vectorNumeros[i] < 0)
		{
			printf("%d.  %d\n", contadorPosicionNumeros,vectorNumeros[i]);
		}
	}
}

int EvaluadorSigno(int numero) //Funcion que evalua el signo de UN numero.
{
	int resultadoPosNeg;

		if(numero < 0)
		{
			resultadoPosNeg = 0;
		}
		else
		{
			resultadoPosNeg = 1;
		}

		return resultadoPosNeg;
}

void RertornarNombreCompleto (char nombre[], char apellido[], char nombreCompleto[])
{
	if(nombre != NULL && apellido !=NULL)
	{
		strcpy(nombreCompleto,apellido);
		strcat(nombreCompleto, ", ");
		strcat(nombreCompleto, nombre);

		printf("\nEl string de nombre quedó así: %s\n\n", nombreCompleto);
	}
}

void FormartearCadena(char nombreCompleto[])
{
	int strLenght;
	int i;

	strLenght=strlen(nombreCompleto);
	strlwr(nombreCompleto);

	if(nombreCompleto != NULL)
	{
		for(i = 0;i<strLenght;i++)
		{
			if(i == 0 || nombreCompleto[i-1]==32)
			{
				nombreCompleto[i]= toupper(nombreCompleto[i]);
			}
		}
	}

}

int ValidadorNumeros (int numeroIngresado)
{

	while(numeroIngresado < 0 || numeroIngresado > 0)
		{

			printf("ERROR - INGRESE NUEVAMENTE EL NUMERO: ");
			scanf("%d", &numeroIngresado);
		}

	return numeroIngresado;
}

int OnlyIntegrersValidation(char mensaje[], char error[],int min,int max)
{
	char operandos[T];
	int resultado = 0;
	int valido;
	do
	{
		// Inicialmente asumimos que el usuario va a introducir un numero valido

		valido = 1;
		printf ("%s",mensaje);
		scanf ("%s", operandos);

		for( char* ptr = operandos; *ptr != 0; ptr++)
		{
			if (!isdigit(*ptr))
			{
				printf("ERROR - Has ingresado %s y solo se aceptan numeros.", operandos);
				valido = 0; // En vez del return actualizamos el flag
			}
		}

		// comprobamos el valor del flag, no tiene sentido hacer mas validaciones
		// si el dato no es numérico
		if (valido == 1)
		{
			resultado = atof(operandos);
			if (resultado < min || resultado > max)
			{
				printf("%s\n",error);
				valido = 0;
			}
		}
	} while (!valido);

	return resultado;
}
int OnlyCharacterValidation(char str[])
{
   int i=0;

   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int getFloatWithParams(char requestMessage[], char errorMessage[], float *input,
        float lowLimit, float hiLimit) {
    char auxStr[256];
    int retorno = -1;
    float auxInt;
    while (retorno == -1) {

        if (!getStringNumerosFlotantes(requestMessage, auxStr)) {
            printf("%s", errorMessage);
        }
        auxInt = atof(auxStr);
        if (auxInt < lowLimit || auxInt > hiLimit) {
            printf("%s", errorMessage);

        } else {
            *input = auxInt;
            retorno = 0;
            return retorno;
        }

    }

    return retorno;

}

int getStringNumerosFlotantes(char mensaje[], char input[]) {
    char aux[256];
    getString(mensaje, aux);
    if (esNumericoFlotante(aux)) {
        strcpy(input, aux);

        return 1;
    }
    return 0;
}

int esNumericoFlotante(char str[])
{
    int i = 0;
    int cantidadPuntos = 0;
    while (str[i] != '\0')
    {
        if (i == 0 && str[i] == '-')
        {
            i++;
            continue;
        }
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

