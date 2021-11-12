#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* punteroAux;
	char idAux[MAX_NAME];
	char nombreStrAux[MAX_NAME];
	char horasTrabajadasStrAux[MAX_NAME];
	char sueldoStrAux[MAX_NAME];
	int readCounter;
	int state;


	state = -1;
	readCounter = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",idAux,nombreStrAux,horasTrabajadasStrAux,sueldoStrAux);

	while(!feof(pFile))
	{

		readCounter = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",idAux,nombreStrAux,horasTrabajadasStrAux,sueldoStrAux);

		if(readCounter == 4)
		{
			punteroAux = employee_newParametros(idAux, nombreStrAux, horasTrabajadasStrAux, sueldoStrAux);
			if(punteroAux != NULL)
			{
				/// El add devuelve si lo pudo agregar, sinó taria bueno un remove
				ll_add(pArrayListEmployee, punteroAux);
				state = 0;
			}
		}

	}

    return state;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

/*
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int punteroAux;
	int idAux;
	char nombreAux;
	int horasTrabajadas;
	int sueldoAux;
	int contadorLeidas;
	int state;

	state = -1;

	while(!feof(pFile))
	{
		contadorLeidas = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",idAux,nombreAux,horasTrabajadas,sueldoAux);

		if(contadorLeidas == 4)
		{
			punteroAux = employee_newParametros(idAux, nombreAux, horasTrabajadas, sueldoAux);
			if(punteroAux != NULL)
			{
				ll_add(pArrayListEmployee, punteroAux);
				state = 0;
			}
		}
	}

    return state;

}
*/

int parser_EmployeeToSaveAsText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int state;

	state = -1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		printf("\n\n\t\t\t\t\t\t| ID   |      Nombre   |  Horas Trabajadas  |    Salario  |\n");

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			state = 0;

			auxEmployee = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &id);
			employee_getNombre(auxEmployee, nombre);
			employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
			employee_getSueldo(auxEmployee, &sueldo);

			fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
		}
	}

	return state;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int state;
	Employee* aux;

	state = -1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			aux = employee_new();

			fread(aux, sizeof(Employee), 1, pFile);

			if(feof(pFile))
			{
				break;
			}
			else
			{
				ll_add(pArrayListEmployee, aux);
			}
		}
	}

    return state;
}

int parser_EmployeeToSaveAsBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int state;
	Employee* aux;
	int workersQty;

	state = -1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		workersQty = ll_len(pArrayListEmployee);

		for(int i = 0; i < workersQty; i++)
		{
			aux = ll_get(pArrayListEmployee, i);

			fwrite(aux,sizeof(Employee),1,pFile);
		}

		state = 0;
	}

	return state;

}

