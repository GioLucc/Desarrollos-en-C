/*
 * ArrayEmployees.c
 *
 *  Created on: 1 oct. 2021
 *      Author: Giovanni
 *
 */

#include "ArrayEmployees.h"
#include "Bibliotecas.h"

/// @fn int initEmployees(Employee*, int)
/// @brief
///
/// @param list
/// @param len
/// @return
int initEmployees(Employee* list, int len)
{
	int state;

	state = -1;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == FULL)
		{
			list[i].isEmpty = EMPTY;
		}
	}
	return state;
}

int askForEmployee (Employee* list, int len, int *id)
{
	Employee oneEmployee;
	int state;

		*id = *id+1;
		state = -1;

	    oneEmployee.id = *id;

		while(OnlyCharacterValidation(oneEmployee.name)==0)
		{
			getString("\t\t\t\t\t\t     Ingrese su nombre por favor :) - 50 LETRAS MAX: ",oneEmployee.name);
		}

		while(OnlyCharacterValidation(oneEmployee.lastName)==0)
		{
			getString("\t\t\t\t\t\t     Ingrese su apellido por favor :) - 50 LETRAS MAX: ",oneEmployee.lastName);
		}

		getFloatWithParams("\t\t\t\t\t\t\t  Ingrese con puntos su sueldo porfavor: ", "\n\t\t\t\t\t\t  ERROR - Reingrese su sueldo correctamente - ERROR\n", &oneEmployee.salary, 10000, 300000);

		oneEmployee.sector = OnlyIntegrersValidation("\t\t\t\t\t\tIngrese el sector en el cual trabaja {Sectores actuales 1 - 5}: ",
														"\t\t\t\tERROR REingrese el sector en el cual trabaja por favor {Sectores actuales 1 - 5} - ERROR",
																								0,5);
		oneEmployee.isEmpty= EMPTY;

		state = 0;

		addEmployee(list,len,oneEmployee.id,oneEmployee.name,oneEmployee.lastName,oneEmployee.salary,oneEmployee.sector);

	return state;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int state;
	state = -1;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == EMPTY)
		{
			list[i].id = id;
			strcpy(list[i].name ,name);
			strcpy(list[i].lastName ,lastName);
			list[i].salary = salary;
			list[i].sector = sector;
			list[i].isEmpty= FULL;
			state = 0;
			break;
		}
	}

	return state;
}

int modifyEmployee(Employee* list, int len)
{
	int state;
	int opcionModificacion;
	int pos;

	state = 0;

	printEmployees(list,len);

	pos = getIdToRemove(list, len);

	opcionModificacion = OnlyIntegrersValidation("\n\t\t\t\t\tSegun los ID del listado ingresado anteriormente, ingrese el ID que quiera modificar: ",
			"\n\t\t\t\t\tSegun los ID del listado ingresado anteriormente, Reingrese el ID que quiera modificar: " ,1,1000);

			opcionModificacion  = OnlyIntegrersValidation("\t\t\t\t\tReingrese nuevamente la opcion que desea modificar: 1 Nombre - 2 Apellido - 3 Salario - 4 Sector - 5 - TODO: ",
							"\t\t\t\t\tIngrese nuevamente la opcion que desea modificar: 1 Nombre - 2 Apellido - 3 Salario - 4 Sector - 5 - TODO: ",1,5);

				switch(opcionModificacion)
				{
					case 1:
						getString("\t\t\t\t\tIngrese su nombre por favor :)- 50 LETRAS MAX: ",list[pos].name);
						while(OnlyCharacterValidation(list[pos].lastName)==0)
						{
							getString("\t\t\t\t\t ERROR Reingrese su Nombre por favor :)- 50 LETRAS MAX: ",list[pos].name);
						}

					break;
					case 2:
						getString("\t\t\t\t\tIngrese su Apellido por favor :)- 50 LETRAS MAX: ",list[pos].lastName);
						while(OnlyCharacterValidation(list[pos].lastName)==0)
						{
							getString("\t\t\t\t\t ERROR Reingrese su Apellido por favor :) - 50 LETRAS MAX: ",list[pos].lastName);
						}

					break;
					case 3:
						getFloatWithParams("\t\t\t\t\tIngrese el sueldo de su ultimo recibo: ",
								"\t\t\t\t\tERROR Reingrese el sueldo de su ultimo recibo: ",&list[pos].salary ,0,300000);
					break;
					case 4:
						list[pos].sector = OnlyIntegrersValidation("\t\t\t\t\tIngrese el sector en el cual trabaja: ",
								"\t\t\t\t\tERROR Reingrese el sector en el cual trabaja: ",1,5);
					break;
					case 5:
						getString("\t\t\t\t\tIngrese su nombre - 50 LETRAS MAX: ",list[pos].name);
						getString("\t\t\t\t\tIngrese su apellido - 50 LETRAS MAX: ",list[pos].lastName);
						getFloatWithParams("\t\t\t\t\tIngrese el sueldo de su ultimo recibo: ",
														"\t\t\t\t\tERROR Reingrese el sueldo de su ultimo recibo: ",&list[pos].salary ,0,300000);
						list[pos].sector = OnlyIntegrersValidation("\t\t\t\t\tIngrese el sector en el cual trabaja {Sectores actuales 1 - 5}: ",
								"\t\t\t\t\tERROR Reingrese el sector en el cual trabaja {Sectores actuales 1 - 5}: ",1,5);
						state = 1;
					break;
				}
	return state;
}

int findEmployeeById(Employee* list, int len,int id)
{

	int pos;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(id == list[i].id && list[i].isEmpty == FULL)
			{
				pos = list[i].id;
				break;
			}
			else
			{
				getIdToRemove(list, len);
			}
		}
	}

	return pos;
}

int getIdToRemove(Employee* list, int len)
{
	int idToRemove;
	int state;
	state = -1;

	if(list != NULL && len > 0)
	{
		idToRemove = OnlyIntegrersValidation("Seleccione el Id que quiere dar de baja","Ese Id no existe ingreselo nuevamente",1,1000);
		state = 0;
	}

	findEmployeeById(list, len, idToRemove);

	return state;
}
int removeEmployee(Employee* list, int len, int id)
{
	int state;
	state = -1;

	for(int i = 0; i < len; i++)
	{
		if(id == list[i].id && list[i].isEmpty == FULL)
		{
			list[i].isEmpty = EMPTY;
			state = 0;
			break;
		}
	}

	return state;
}
int sortEmployees(Employee* list, int len, int order)
{
	int state;
	state = 1;
	Employee aux;

	if(list != NULL && len > 0 && order != 4)
	{
		switch(order)
		{
			case 1:
					for (int i = 0; i < len - 1; i++)
					{
						for (int j = i + 1; j < len; j++)
						{
							if (strcmp(list[i].lastName, list[j].lastName) > 0)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
							else
							{
								if (strcmp(list[i].lastName, list[j].lastName) == 0)
								{
									if (list[i].sector < list[j].sector)
									{
										aux = list[i];
										list[i] = list[j];
										list[j] = aux;
									}
								}
							}
						}
					}

					return state;
			break;

			case 2:
				for (int i = 0; i < len - 1; i++)
				{
					for (int j = i + 1; j < len; j++)
					{
						if (strcmp(list[i].lastName, list[j].lastName)< 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
						else
						{
							if (strcmp(list[i].lastName, list[j].lastName) == 0)
							{

								if (list[i].sector > list[j].sector)
								{
									aux = list[i];
									list[i] = list[j];
									list[j] = aux;
								}
							}
						}
					}
				}
			break;
			case 3:
			averageSalaryAndAbove(list,len);
			break;
		}

	}

	return state;
}

int printEmployees(Employee* list, int len)
{
	int state;
	int sortOption;

	state = -1;
	printf("\n\n\n\n\n\n\n\n\t\t\t___________________________________________________________________________\n");
	printf("\t\t\t| ID   |      Nombre       |       Apellido      |   Salario   | Sector   |\n");
	printf("\t\t\t|______|___________________|_____________________|_____________|__________|");



	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == FULL)
		{
			printf("\n\t\t\t| %2d  |%14s     |  %14s     |  %9.2f  |%7d   |",
					list[i].id,
					list[i].name,
					list[i].lastName,
					list[i].salary,
					list[i].sector);
			state = 0;
		}
	}

	sortOption = OnlyIntegrersValidation("\n\n\t\t\t\tLe gustaria ordenar a los empleados de forma distinta?\n"
			"\t\t\t\t> 1 - Ordenar empleados de manera Ascendente segun [SECTOR y APELLIDO]. - 1 <\n"
			"\t\t\t\t> 2 - Ordenar empleados de manera Descendente segun [SECTOR y APELLIDO]. - 2 <\n"
			"\t\t\t\t> 3 - Ordenar Total y promedio de los salarios, y cuántos empleados superan el salario promedio. - 3 <\n"
			"\t\t\t\t> 4 - Salir - 1 <\n\n\n"
			"\t\t\t\tQue le gustaria hacer?", "Error seleccione un opcion correcta porfavor", 1, 4);

	sortEmployees(list, len, sortOption);


	return state;
}
int averageSalaryAndAbove(Employee *list, int len)
{
    int employeesCounter;
    int salaryAccumulator;
    int aboveAverageSalary;
    float averageSalary;


    salaryAccumulator = 0;
    employeesCounter = 0;
    aboveAverageSalary = 0;

    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {

            if (list[i].isEmpty == FULL)
            {
            	salaryAccumulator = salaryAccumulator + list[i].salary;
                employeesCounter++;
            }
        }

    }

    averageSalary = salaryAccumulator / (float) employeesCounter;

    for (int i = 0; i < len; i++)
    {
        if (list[i].salary > averageSalary && list[i].isEmpty == FULL)
        {
        	aboveAverageSalary++;
        }

    }

    printf("El promedio de los salarios de los empleados es: %.2f \n"
            "La cantidad de empleados que superan el promedio de sueldos son de :%d\n",
			averageSalary, aboveAverageSalary);
    return 1;
}






