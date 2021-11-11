/*
 * BasicFunctions.c
 *
 *  Created on: 19 oct. 2021
 *      Author: giova
 */

#include "BasicFunctions.h"

void printMenu(void)
{

	printf("\n\n\n\t\t\t================================================================================================\n");
	printf("\t\t\t\t\t\t\t\tWelcome to the Data Base\n");
	printf("\t\t\t\t\t\t\t\t\tDalaran\n");
	printf("\t\t\t================================================================================================\n\t\t\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t               ( V ) Menu de Opciones ( V )\t\t\t\t  \n\n");
	printf("\t\t\t        > 1 - Cargar los datos de los empleados desde el archivo data.csv (modo texto). - 1 <\n");
	printf("\t\t\t          > 2 - Cargar los datos de los empleados desde el archivo data.csv (modo binario). - 2 <\n");
	printf("\t\t\t\t\t\t            > 3 - Alta de empleado. - 3 <\n");
	printf("\t\t\t\t\t\t       > 4 - Modificar datos de empleado - 4 <\n");
	printf("\t\t\t\t\t\t            > 5 - Baja de empleado - 5 <\n");
	printf("\t\t\t\t\t\t            > 6 - Listar empleados - 6 <\n");
	printf("\t\t\t\t\t\t            > 7 - Ordenar empleados - 7 <\n");
	printf("\t\t\t           > 8 - Guardar los datos de los empleados en el archivo data.csv (modo texto). - 8<\n");
	printf("\t\t\t           > 9 - Guardar los datos de los empleados en el archivo data.csv (modo binario). - 9 <\n");
	printf("\t\t\t\t\t\t\t          > 10 - Salir - 10 <");

}

int getValidInt(char mensaje [], char error [], int min, int max)
{
	char integrer[MAX];
	int validIntegrer;

	validIntegrer = OnlyIntegrersValidation(integrer,error,mensaje, min, max);

	return validIntegrer;

}

int OnlyIntegrersValidation(char integrer [],char error [], char mensaje[], int min, int max)
{
	int resultado = 0;
	int valido;
	do
	{
		valido = 1;
		printf ("%s",mensaje);
		scanf ("%s", integrer);

	/*	for(char* ptr = integrer; *ptr != 0; ptr++)
		{
			if (!isdigit(*ptr))
			{

			}
		}
*/
		while(valido == 0)
		{
			char *ptr;

			ptr = integrer;

			if(!isdigit(*ptr))
			printf("\n\n\t\t\t\t\t    ERROR - (Has ingresado %s y solo se aceptan numeros) - ERROR\n", integrer);
			valido = 0;
		}


		if (valido == 1)
		{
			resultado = atof(integrer);
			if (resultado < min || resultado > max)
			{
				valido = 0;
			}

			if(valido == 0)
			{
				printf("%s", error);
			}
		}
	} while (!valido);

	return resultado;
}

int getString(char mensaje[],char str[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]s", str);

    return 1;
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

int askForAdress (char message[], char str[])
{
    printf("%s",message);
    fflush(stdin);
    scanf("%[^\n]s",str);

    return 1;
}

int getStringVerificado(char mensaje[], char mensajeError[], char *input)
{
    int retorno = -1;
    char aux[256];

    getString(mensaje, aux);

    while (retorno == -1)
    {
        if (OnlyCharacterValidation(aux) == 0)
        {
            getString(mensajeError, aux);
        }
        else
        {
            retorno = 0;
            strcpy(input, aux);
        }
    }
    return retorno;
}

int argentinianCuitValidation (char mensaje[], char mensajeError[], char *input)
{
	int i;
	int state;
	char aux [12];

	i = 0;
	state = -1;

	getString(mensaje, aux);

	while(state == -1)
	{
		/*
		for(int i = 0; i < 12; i++)
		{
			if(aux[0] && aux[1] > 0 && aux[2] == '-' &&
			   aux[3] && aux[4] && aux[5] && aux[6]
		   	   && aux[7] && aux[8] && aux[9] && aux[10] > 0 &&
			   aux[11] == '-' && aux[12] > 0)
			{
				state = 0;
				strcpy(input, aux);
			}
			else
			{
				state = -1;
				getString(mensajeError, aux);



			}
		}
		*/
			while(aux[i] != '\0')
		   {
			   if(aux[0] > 0 && aux[1] > 0 && aux[2] == '-' &&
					   aux[3] && aux[4] && aux[5] && aux[6]
					   && aux[7] && aux[8] && aux[9] && aux[10] > 0 &&
					   aux[11] == '-' && aux[12] > 0)
				   return 0;
			   i++;
		   }
			state = 0;
			strcpy(input, aux);
	}

	return state;

}

