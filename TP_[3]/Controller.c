#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

int controller_firstObligatoryLoad(int* verification)
{
	if(*verification == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* auxFile;
	int state;


	state = -1;
	auxFile = fopen(path,"r");// Al hacer que auxfile apunte a el path del archivo

	if(auxFile != NULL)
	{
		if(!parser_EmployeeFromText(auxFile, pArrayListEmployee))
		{
			state = 0;
		}
	fclose(auxFile); // a la hora de cerrarlo tenemos que pasarle el parametro del archivo al cual apuntamos cuando lo abrimos
	}


    return state;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* auxFile;
	int state;

	state = -1;



	if(pArrayListEmployee != NULL && path != NULL)
	{
		auxFile = fopen(path,"rb");

		if(auxFile != NULL
		&& !parser_EmployeeFromBinary(auxFile, pArrayListEmployee))
		{


			state = 0;
		}

		fclose(auxFile);
	}

    return state;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *as
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int id;
	int* idAux;

	id = 20;
	idAux = &id;

	Employee* aux;

	aux = employee_new();
	employee_setNombreManually(aux);
	employee_setSueldoManually(aux);
	employee_setHorasTrabajadasManually(aux);
	employee_setId(aux, *idAux);

	ll_add(pArrayListEmployee, aux);

	employee_showOneEmployee(aux);

	id++;


    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* aux;
	int index;
	int askModify;
	int whatToDo;

	index = employee_askValidId(pArrayListEmployee);

	aux = ll_get(pArrayListEmployee, index);

	employee_showOneEmployee(aux);

	whatToDo = getValidInt("\nEstá seguro que quiere modificar el siguiente empleado?\n\t\t 1 -> (SI) || 2 -> NO \n\t\t\t   ",
	"ERROR - (Ingrese una opcion correcta) - ERROR", 1, 2);

	if(whatToDo == 1)
	{
		askModify = getValidInt("\n Que desea modificar? 1 -> (NOMBRE) || 2 -> (HORAS TRABAJADAS) || 3 -> (SUELDO)\n\t\t\t\t      ",
		"ERROR - (Ingrese una opcion correcta) - ERROR" , 1, 3);

		switch(askModify)
		{
			case 1:
				employee_setNombreManually(aux);
			break;

			case 2:
				employee_setHorasTrabajadasManually(aux);
			break;

			case 3:
				employee_setSueldoManually(aux);
			break;
		}
	}


    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int idSelectedToRemove;
	Employee* aux;
	int whatToDo;

	if(pArrayListEmployee != NULL)
	{
		idSelectedToRemove = employee_askValidId(pArrayListEmployee);

		aux = ll_get(pArrayListEmployee, idSelectedToRemove);

		printf("\t\t");employee_showOneEmployee(aux);
		whatToDo = getValidInt("\nEstá seguro que quiere remover el siguiente empleado?\n\t\t 1 -> (SI) || 2 -> NO \n\t\t\t    ",
			"ERROR - (Ingrese una opcion correcta) - ERROR", 1, 2);

			if(whatToDo == 1)
			{
				ll_remove(pArrayListEmployee, idSelectedToRemove);
				printf("\n\t     Empleado satisfactoriamente removido :)");
			}
			else
			{
				printf("\n\n\t    Cancelando operacion, volviendo al menu.");
			}

			sleep(3);
	}

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* aux;
	int workersQty;
	int state;

	state = -1;

	if(pArrayListEmployee != NULL)
	{
		workersQty = ll_len(pArrayListEmployee);

		printf("\n\n\t\t\t\t\t\t| ID   |      Nombre   |  Horas Trabajadas  |    Salario  |\n");

		for(int i = 0; i < workersQty; i++)
		{
			aux = ll_get(pArrayListEmployee, i);

			employee_showOneEmployee(aux);

		}
		state = 0;
	}

    return state;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int menuOption;

	printf("Bienvenido al criterio de ordenamiento multiple :)");

	menuOption = getValidInt("\n\nComo le gustaria ordenar los empleados?\n\t\t 1 -> (Sueldos [Mayor] Ascendentes) || 2 -> (Sueldos [Mayor]  Descendentes) "
			"\n\t\t|| 3 -> (Nombres A - Z Descendentes) || 4 -> (Nombres A - Z Ascendentes) \n\t\t\t    ",
			"\n\nERROR - (Ingrese una opcion correcta) - ERROR", 1, 4);

	switch(menuOption)
	{
		case 1:
			ll_sort(pArrayListEmployee, employee_compareBySueldo, 1); /// Menor mayor
			printf("Se han ordenado los empleados satisfactoriamente");
		break;

		case 2:
			ll_sort(pArrayListEmployee, employee_compareBySueldo, 0); /// Mayor menor
			printf("Se han ordenado los empleados satisfactoriamente");
		break;

		case 3:
			ll_sort(pArrayListEmployee, employee_compareByName,1); /// A
			printf("Se han ordenado los empleados satisfactoriamente");
		break;

		case 4:
			ll_sort(pArrayListEmployee, employee_compareByName,0); /// Z
			printf("Se han ordenado los empleados satisfactoriamente");
		break;

	}

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int state;
	FILE* pFile;

	state = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL && !parser_EmployeeToSaveAsText(pFile, pArrayListEmployee))
		{
			state = 0;
		}
			fclose(pFile);
	}

	return state;
}


//	fprintf(pFile, _Format);


	/*
	 * FILE* auxFile;
	int state;


	state = -1;
	auxFile = fopen(path,"r");// Al hacer que auxfile apunte a el path del archivo

	if(auxFile != NULL)
	{
		if(!parser_EmployeeFromText(auxFile, pArrayListEmployee))
		{
			state = 0;
		}
	fclose(auxFile); // a la hora de cerrarlo tenemos que pasarle el parametro del archivo al cual apuntamos cuando lo abrimos
	}
	 */




/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int state;
	FILE* pFile;

	state = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"wb");

		if(pFile != NULL && !parser_EmployeeToSaveAsBinary(pFile, pArrayListEmployee))
		{
			state = 0;
		}
			fclose(pFile);
	}

    return state;
}

