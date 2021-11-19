/*
 * ArrayEmployees.h
 *
 *  Created on: 1 oct. 2021
 *      Author: Giovanni
 *
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bibliotecas.h"
#include <unistd.h>
#include <ctype.h>

//ESTADOS

#define EMPTY 1
#define FULL 0

struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

int initEmployees(Employee* list, int len);
int askForEmployee (Employee* list, int len,int *id);
int addEmployee(Employee* list, int len, int id, char name[],char
		lastName[],float salary,int sector);
int modifyEmployee(Employee* list, int len);
int findEmployeeById(Employee* list, int len,int id);
int getIdToRemove(Employee* list, int len);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
int averageSalaryAndAbove(Employee *list, int len);


#endif /* ARRAYEMPLOYEES_H_ */
