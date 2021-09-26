/*
 ============================================================================
 Name        : TP.c
 Author      : Giovanni Lucchetta
 Version     : Calculadora 2.14
 Copyright   : Giovanni Lucchetta™
 Description : Calculadora en su version mas reciente que te permitira realizar casi cualquier calculo posible.

 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:

	1. Ingresar 1er operando (A=x)
	2. Ingresar 2do operando (B=y)
	3. Calcular todas las operaciones
	a) Calcular la suma (A+B)
	b) Calcular la resta (A-B)
	c) Calcular la division (A/B)
	d) Calcular la multiplicacion (A*B)
	e) Calcular el factorial (A!)
	4. Informar resultados
	a) “El resultado de A+B es: r”
	b) “El resultado de A-B es: r”
	c) “El resultado de A/B es: r” o “No es posible dividir por cero”
	d) “El resultado de A*B es: r”
	e) “El factorial de A es: r1 y El factorial de B es: r2”
	5. Salir
	// si el factorial es -1
	// si la division es por 0
	 *

	• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
	que contenga las funciones para realizar las cinco operaciones.
	• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
	(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
	• Deberán contemplarse los casos de error (división por cero, etc)
	• Documentar todas las funciones
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas.h"
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#define PORCENTAJE '%'

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	float auxOpcion;
	float primerOperando = 0;
	float segundoOperando = 0;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	float resultadoFactorialR1;
	float resultadoFactorialR2;
	int banderaDePrimerOperando = 0;
	int banderaDeSegundoOperando = 0;
	int banderaDivision = 0;
	int banderaFactorialR1 = 0;
	int banderaFactorialR2 = 0;


	printf("\t\t\t\t==================================================\n");
	printf("\t\t\t\t\tBienvenido a la Calculadora V2.14\n");
	printf("\t\t\t\t==================================================\n\n\n");

	do
	{
		printf("\t\t\t\t\t|| ( V ) Menu de Opciones ( V ) ||\n\n");

		if(banderaDePrimerOperando == 0)
		{
			printf("\t\t\t\t\t> 1 - Ingresar 1er operando (A = X).\n");
		}
		else
		{
			printf("\t\t\t\t\t> 1 - Ingresar 1er operando (A = %.2f).\n", primerOperando);
		}

		if(banderaDeSegundoOperando == 0)
		{
			printf("\t\t\t\t\t> 2 - Ingresar 2do operando (B = Y).\n");
		}
		else
		{
			printf("\t\t\t\t\t> 2 - Ingresar 2do operando (B = %.2f).\n", segundoOperando);
		}

			printf("\t\t\t\t\t> 3 - Calcular todas las operaciones.\n");
			printf("\t\t\t\t\t> 4 - Informar resultados\n");
			printf("\t\t\t\t\t> 5 - Salir\n\n");

			while(IngreseOperandosMasVerificacion("\n\t\t\t\t\t Ingrese una opcion del menu por favor: ",&auxOpcion)==0 || (auxOpcion < 1 || auxOpcion > 5))
			{
				printf("\n\n\t\t\t\t\t*Syntax ERROR Ingrese un numero valido*\n\n");
			}
			opcion = (int)auxOpcion;

			switch(opcion)
			{
				case 1:
					while(IngreseOperandosMasVerificacion("\n\n\t\t\t\t\t Ingrese su primer numero por favor: ",&primerOperando)==0)
					{
						printf("\n\n\t\t\t\t\t*Syntax ERROR Ingrese un numero valido*");

					}
					banderaDePrimerOperando = 1;
					printf("\n\t\t\t\t\t El primer numero ingresado fue: %.2f\n\n", primerOperando);
					printf("\t\t\t\t\t");system("pause");
					system("cls");
				break;

				case 2:
					while(IngreseOperandosMasVerificacion("\n\n\t\t\t\t\t Ingrese su segundo numero por favor: ",&segundoOperando)==0)
					{
						printf("\n\n\t\t\t\t\t*Syntax ERROR Ingrese un numero valido*");
					}
					banderaDeSegundoOperando = 1;
					printf("\n\n\t\t\t\t\tEl segundo numero ingresado fue: %.2f\n\n", segundoOperando);
					printf("\t\t\t\t\t");system("pause");
					system("cls");
				break;

				case 3:
					resultadoSuma = FuncionSuma (primerOperando, segundoOperando);
					resultadoResta = FuncionResta (primerOperando, segundoOperando);
					resultadoMultiplicacion = FuncionMultiplicacion (primerOperando, segundoOperando);
					if(segundoOperando != 0)
					{
						resultadoDivision = FuncionDivision (primerOperando, segundoOperando);
						banderaDivision = 1;
					}
					else
					{
						banderaDivision = 0;
					}

					if(primerOperando < 13 && FuncionFactorial(primerOperando, &resultadoFactorialR1)==1)
					{
						banderaFactorialR1 = 1;
					}
					else
					{
						banderaFactorialR1 = 0;
					}

					if(segundoOperando < 13 && FuncionFactorial(segundoOperando, &resultadoFactorialR2)==1)
					{
						banderaFactorialR2 = 1;
					}
					else
					{
						banderaFactorialR2 = 0;
					}

					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\tRealizando las operaciones, espere unos segundos.");
					sleep(1);
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\tRealizando las operaciones, espere unos segundos..");
					sleep(0.9);
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\tRealizando las operaciones, espere unos segundos...");
					sleep(1);
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\tRealizando las operaciones, espere unos segundos....");
					sleep(0.9);
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\tRealizando las operaciones, espere unos segundos.....");
					sleep(1);
					system("cls");
				break;

				case 4:
					system("cls");
					printf("\n\n\n\t\t\t\t\tEl resultado de A= %.2f + B = %.2f es: %.2f\n",primerOperando,segundoOperando,resultadoSuma);
					printf("\n\n\n\t\t\t\t\tEl resultado de A= %.2f - B = %.2f es: %.2f\n",primerOperando,segundoOperando,resultadoResta);
					printf("\n\n\n\t\t\t\t\tEl resultado de A= %.2f * B = %.2f es: %.2f\n",primerOperando,segundoOperando,resultadoMultiplicacion);
					if(banderaDivision == 0)
					{
						printf("\n\n\t\t\t\t\t*Syntax ERROR - No es posible dividir por 0*\n\n");
					}
					else
					{
						printf("\n\n\n\t\t\t\t\tEl resultado de A= %.2f / B = %.2f es: %.2f\n",primerOperando,segundoOperando,resultadoDivision);
					}

					if(banderaFactorialR1 == 0)
					{
						printf("\n\n\t\t\t\t*Syntax ERROR - No es posible calcular el factorial de este numero*\n\n");
					}
					else
					{
						printf("\n\n\n\t\t\t\t\tEl resultado de A= %.2f a factorial es: %.2f\n",primerOperando,resultadoFactorialR1);
					}

					if(banderaFactorialR2 == 0)
					{
						printf("\n\n\t\t\t\t*Syntax ERROR - No es posible calcular el factorial de este numero*\n\n");
					}
					else
					{
						printf("\n\n\n\t\t\t\t\tEl resultado de B= %.2f a factorial es: %.2f\n",segundoOperando,resultadoFactorialR2);
					}

					printf("\n\n\n");
					printf("\t\t\t\t\t");system("pause");
					system("cls");
				break;

				case 5:
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\t\tGracias por usar la Calculadora V2.14");
					sleep(1.5);
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\t      No se olvide de probar nuestra Calculadora Premium!!");
					printf("\n\t\t\t\t\t\tEn nuestra pagina Oficial!!");
					sleep(3);
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\t    Este proceso se finalizara cuando termine la carga.");
					sleep(1);
					printf("\n\n\t\t\t\t\t\t\t\a[#     ]10%c",PORCENTAJE);
					sleep(1);
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\t    Este proceso se finalizara cuando termine la carga.");
					printf("\n\n\t\t\t\t\t\t\t\a[##    ]33%c",PORCENTAJE);
					sleep(1);
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\t    Este proceso se finalizara cuando termine la carga.");
					printf("\n\n\t\t\t\t\t\t\t\a[###   ]46%c",PORCENTAJE);
					sleep(1);
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\t    Este proceso se finalizara cuando termine la carga.");
					printf("\n\n\t\t\t\t\t\t\t\a[####  ]54%c",PORCENTAJE);
					sleep(1);
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\t    Este proceso se finalizara cuando termine la carga.");
					printf("\n\n\t\t\t\t\t\t\t\a[##### ]71%c",PORCENTAJE);
					sleep(1);
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t\t    Este proceso se finalizara cuando termine la carga.");
					printf("\n\n\t\t\t\t\t\t\t\a[######]99%c",PORCENTAJE);
					sleep(1);
					system("cls");
				break;
			}
				printf("\n\n");

	}while(opcion != 5);

	return EXIT_SUCCESS;
}
