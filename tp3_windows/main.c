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

    employeeQty = 0;

    do
    {
    	employeeQty = ll_len(listaEmpleados);

    	printMenu();

    	menuOption = getValidInt("\n\t\t\t\t\t         Ingrese una opcion del menu para realizar del 1 al 10: ",
    	"\n\n\t\t\t\t      ERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR\n\n", 1, 10);

        switch(menuOption)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);

			break;

            case 2:
            /*
            	controller_loadFromBinary("data.csv", listaEmpleados);

            	for(int i = 0; i < ll_len(listaEmpleados); i++)
            	{
            		auxLista = (Employee*)ll_get(listaEmpleados,i);
                	employee_showOneEmployee(auxLista);
            	}
            */
            break;

            case 3:
            	controller_addEmployee(listaEmpleados);
            break;

            case 4:
                if(employeeQty == 0)
                {
                    printf("No hay Empleados cargados en el sistema, vuelva al menu y agregue uno al menos.\n");
                }
            	controller_editEmployee(listaEmpleados);
			break;

            case 5:
                if(employeeQty == 0)
                {
                    printf("No hay Empleados cargados en el sistema, vuelva al menu y agregue uno al menos.\n");
                }
            	controller_removeEmployee(listaEmpleados);
			break;

            case 6:
                if(employeeQty == 0)
                {
                    printf("No hay Empleados cargados en el sistema, vuelva al menu y agregue uno al menos.\n");
                }
            	employee_showAllEmployee(listaEmpleados);
            break;

            case 7:
                if(employeeQty == 0)
                {
                    printf("No hay Empleados cargados en el sistema, vuelva al menu y agregue uno al menos.\n");
                }
            	controller_sortEmployee(listaEmpleados);
            break;

            case 8:
            	controller_saveAsText("data.csv",listaEmpleados);
			break;

        }
    }while(menuOption != 10);


}

