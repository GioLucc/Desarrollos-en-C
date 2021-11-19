/*
 ============================================================================

 Name        : TP_2.c
 Author      : Giovanni Lucchetta
 Version     :
 Copyright   : Tano™
 Description :

Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
Datos:
El sistema deberá tener el siguiente menú de opciones:

1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.

2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector

3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.

4. INFORMAR:

1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.
Para la realización de este programa, se utilizará una biblioteca llamada “ArrayEmployees” que
facilitará el manejo de la lista de empleados y su modificación.

 ============================================================================
 */

#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#define PORCENTAJE '%'
#define len 1000

int main(void)
{
	setbuf(stdout,NULL);
	Employee employeeList[1000];

	int id = 0;
	int option;
	int firstEmployeeIngressFlag;


		firstEmployeeIngressFlag = -1;

	do
	{
	printf("\t\t\t================================================================================================\n");
	printf("\t\t\t\t\t\t\t\tWelcome to the Data Base                                  \n");
	printf("\t\t\t\t\t\t\t\t\tDalaran                                           \n");
	printf("\t\t\t================================================================================================\n\t\t\t\t\t\t\t\t\t"
			"\t\t\t\t\t\t  \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  \n");

	printf("\t\t\t\t\t\t             ( V ) Menu de Opciones ( V )\t\t\t\t  ");
	printf("\t\t\t\t  \n\t\t\t");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t  \n");
	printf("\t\t\t\t\t\t         > 1 - Dar de ALTA un empleado. - 1 <\t\t\t           \n \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  \n");
	printf("\t\t\t\t\t\t          > 2 - MODIFICAR un empleado. - 2 <\t\t\t\t  \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  \n");
	printf("\t\t\t\t\t\t         > 3 - Dar de BAJA a un empleado. - 3 <\t\t\t          \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  \n");
	printf("\t\t\t           > 4 - INFORMAR ( - Ingrese para seleccionar las opciones de informe - ). - 4 <       \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  \n");
	printf("\t\t\t\t\t\t\t\t  > 5 - Salir. - 5 <\t\t\t\t\t  \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  \n");

	option = OnlyIntegrersValidation("\t\t\t\t\t\t\t ! Dalaran Data Base a su disposicion !\t\t\t          \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  \n\t\t\t\t\t\t\t\t"
			"  Ingrese una opcion: ","ERROR - Reingrese una opcion correcta del menu: ", 1, 5);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  \n");

	switch(option)
	{
		case 1:
			if(firstEmployeeIngressFlag == -1)
			{
				initEmployees(employeeList,len);
				askForEmployee(employeeList,len,&id);
				firstEmployeeIngressFlag = 0;
			}
			else
			{
				askForEmployee(employeeList,len,&id);
			}
		break;

		case 2:
			if(firstEmployeeIngressFlag == 0)
			{
				modifyEmployee(employeeList,len);
			}
			else
			{
				printf("ERROR - Primero debe dar de alta un empledado - ERROR");
			}

		break;

		case 3:
			if(firstEmployeeIngressFlag == 0)
			{
				getIdToRemove(employeeList,len);
				system("cls");
				printf("\n\n\n");
				printf("\t\t\t\t\t");system("pause");
				system("cls");
			}
			else
			{
				printf("ERROR - Primero debe dar de alta un empledado - ERROR");
			}
		break;

		case 4:
			if(firstEmployeeIngressFlag == 0)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\t\t\t\tRecopilando los datos ingresados, espere unos segundos.");
				sleep(1);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\t\t\t\tRecopilando los datos ingresados, espere unos segundos..");
				sleep(0.9);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\t\t\t\tRecopilando los datos ingresados, espere unos segundos...");
				sleep(1);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\t\t\t\tRecopilando los datos ingresados, espere unos segundos....");
				sleep(0.9);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\t\t\t\tRecopilando los datos ingresados, espere unos segundos.....");
				sleep(1);
				system("cls");
				printEmployees(employeeList,len);
				system("cls");
			}
			else
			{
				printf("ERROR - Primero debe dar de alta un empledado - ERROR");
			}

		break;

		case 5:
			system("cls");
			printf("\n\n\n\n\n\n\n\n\t\t\t\t\tGracias por haber actualizado la Base de Datos");
			sleep(1.5);
			system("cls");
			printf("\n\n\n\n\n\n\n\n\t\t\t\t      Nos vemos la proxima vez que necesites añadir otro empleado!!");
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

	}while(option != 5);

}
