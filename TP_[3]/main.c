#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir

    // ABM DE DATOS PEGANDO A UN ARCHIVO

*****************************************************/

int main ()
{
	setbuf(stdout,NULL);
	int menuOption;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int firstLoadFlag;
    int employeeQty;

    firstLoadFlag = 0;

    do
    {
    	employeeQty = ll_len(listaEmpleados);

    	printMenu();

    	menuOption = getValidInt("\n\n\t\t\t\t\t      Ingrese una opcion del menu para realizar del 1 al 10: ",
    	"\n\n\t\t\t\t      ERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR\n\n", 1, 10);

        switch(menuOption)
        {
            case 1:
               firstLoadFlag = 1;
               controller_firstObligatoryLoad(&firstLoadFlag);
               controller_loadFromText("data.csv",listaEmpleados);
			break;

            case 2:
            	firstLoadFlag = 1;
            	controller_loadFromBinary("data.bin", listaEmpleados);
            break;

            case 3:
            	if((controller_firstObligatoryLoad(&firstLoadFlag)) == 1
				&& (ll_isEmpty(listaEmpleados)) == 0)
            	{
            		controller_addEmployee(listaEmpleados);

                	printf("\n\t\t\t\t\t\t\tEmpleado creado satisfactoriamente!\n"
                			"\t\t\t\t\t   La cantidad de empleados actuales ahora mismo es de %d!", employeeQty);
            	}
            	else
            	{
            		printf("\n\t\t\t\t\t   No hay Empleados cargados en el sistema vuelva al menu y agregue al menos uno!\n"
            				"\t\t\t\t\t\t\t\t   Regresando al menu\n\n");
            	}
            break;

            case 4:
            	if((controller_firstObligatoryLoad(&firstLoadFlag)) == 1
				&& (ll_isEmpty(listaEmpleados)) == 0)
                {
                	controller_editEmployee(listaEmpleados);
                }
                else
                {
            		printf("\n\t\t\t\t\t   No hay Empleados cargados en el sistema vuelva al menu y agregue al menos uno!\n"
            				"\t\t\t\t\t\t\t\t   Regresando al menu\n\n");
                }
			break;

            case 5:
            	if((controller_firstObligatoryLoad(&firstLoadFlag)) == 1
				&& (ll_isEmpty(listaEmpleados)) == 0)
            	{
            		controller_removeEmployee(listaEmpleados);
                }
            	else
            	{
            		printf("\n\t\t\t\t\t   No hay Empleados cargados en el sistema vuelva al menu y agregue al menos uno!\n"
            				"\t\t\t\t\t\t\t\t   Regresando al menu\n\n");
            	}
			break;

            case 6:
            	if((controller_firstObligatoryLoad(&firstLoadFlag)) == 1
				&& (ll_isEmpty(listaEmpleados)) == 0)
            	{
            		controller_ListEmployee(listaEmpleados);
                }
            	else
            	{
            		printf("\n\t\t\t\t\t   No hay Empleados cargados en el sistema vuelva al menu y agregue al menos uno!\n"
            				"\t\t\t\t\t\t\t\t   Regresando al menu\n\n");
            	}
            break;

            case 7:
            	if((controller_firstObligatoryLoad(&firstLoadFlag)) == 1
				&& (ll_isEmpty(listaEmpleados)) == 0)
            	{
            		controller_sortEmployee(listaEmpleados);
                }
            	else
				{
            		printf("\n\t\t\t\t\t   No hay Empleados cargados en el sistema vuelva al menu y agregue al menos uno!\n"
            				"\t\t\t\t\t\t\t\t   Regresando al menu\n\n");				}
            break;

            case 8:
            	if((controller_firstObligatoryLoad(&firstLoadFlag)) == 1
				&& (ll_isEmpty(listaEmpleados)) == 0)
            	{
            		controller_saveAsText("data.csv",listaEmpleados);
            	}
            	else
            	{
            		printf("\n\t\t\t\t\t   No hay Empleados cargados en el sistema vuelva al menu y agregue al menos uno!\n"
            				"\t\t\t\t\t\t\t\t   Regresando al menu\n\n");            	}
			break;

            case 9:
            	if((controller_firstObligatoryLoad(&firstLoadFlag)) == 1
				&& (ll_isEmpty(listaEmpleados)) == 0)
            	{
            		controller_saveAsBinary("data.bin",listaEmpleados);
            	}
            	else
            	{
            		printf("\n\t\t\t\t\t   No hay Empleados cargados en el sistema vuelva al menu y agregue al menos uno!\n"
            				"\t\t\t\t\t\t\t\t   Regresando al menu\n\n");            	}
			break;

        }
    }while(menuOption != 10);


}

