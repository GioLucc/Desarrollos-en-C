#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "BasicFunctions.h"
#include "LinkedList.h"
#define MAX_NAME 100

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

}Employee;

Employee* employee_newAlta(int id);
Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

void employee_delete(Employee*);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_setNombreManually(Employee* this);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setHorasTrabajadasManually(Employee* this);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_setSueldoManually(Employee* this);

int employee_compareBySueldo(void* elemento1 ,void* elemento2);
int employee_compareByName(void* elemento1 ,void* elemento2);


int employee_showOneEmployee(Employee* this);
int employee_showAllEmployee(LinkedList* listaEmpleados);

//// ID's Manipulation

int employee_searchIndexById(LinkedList* listaEmpleados, int id);
int employee_askValidId(LinkedList* listaEmpleados);




#endif // employee_H_INCLUDED
