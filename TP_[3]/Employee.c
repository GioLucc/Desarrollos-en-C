#include "Employee.h"

Employee* employee_newAlta()
{
	Employee* aux;

	char nombre[MAX_NAME];
	int sueldo;
	int horas;

	aux = employee_new();

	getStringVerificado("\n\t\t\t\t\t\t\tIngrese su nombre porfavor :) : ",
			"\t\t\t\t\t\tERROR - (RE-Ingrese su nombre por favor) - ERROR : \n",
			nombre);
	sueldo = getValidInt("\n\t\t\t\t\t         Ingrese el pago de su ultimo recibo de sueldo porfavor",
					"\n\n\t\t\t\t      ERROR - (RE-Ingrese su sueldo porfavor) - ERROR\n\n", 1,500000);

	horas = getValidInt("\n\t\t\t\t\t         Ingrese las horas trabajadas en el ultimo mes :) : ",
						"\n\n\t\t\t\t      ERROR - (RE-Ingrese las horas trabajadas en el ultimo mes :) : ) - ERROR\n\n", 1, 500);


	employee_setNombre(aux, nombre);
	employee_setHorasTrabajadas(aux, horas);
	employee_setSueldo(aux, sueldo);

	return aux;
}


Employee* employee_new() // Constructor
{
	Employee* new;

    new = (Employee*) calloc(1,sizeof(Employee)); // Consigue espacio mediante memoria dinamica para la estructura empleado

	return new;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* newEmployee;

	newEmployee = employee_new();

	int id;
	char nombre[MAX_NAME];
	int horastrabajadas;
	int sueldo;

	id = atoi(idStr);
	strcpy(nombre, nombreStr);
	horastrabajadas = atoi(horasTrabajadasStr);
	sueldo = atoi(sueldoStr);

	/// Utilizar el retorno del setter

	employee_setId(newEmployee, id);
	employee_setNombre(newEmployee, nombre);
	employee_setHorasTrabajadas(newEmployee, horastrabajadas);
	employee_setSueldo(newEmployee, sueldo);

	/// if any setter no funcó employee_delete void employee_delete(Employee*);


/*	employee_setId(newEmployee, atoi(idStr));
	employee_setNombre(newEmployee, nombreStr);
	employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
	employee_setSueldo(newEmployee, atoi(sueldoStr));
*/
	return newEmployee;
}

int employee_setId(Employee *this, int id)
{
	if(this != NULL)
	{
		this->id = id;
	}

	return 0;
}

int employee_getId(Employee* this, int* id) // guarda en el segundo parametro el dato del empleado
{
	if(this != NULL && id != NULL)
	{
		*id = this-> id;
	}

	return 1;
}

int employee_setNombre(Employee* this,char* nombre) // agarra el segundo dato y se lo pone al empleado
{
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
	}

	return 1;
}

int employee_getNombre(Employee* this,char* nombre)
{
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre , this->nombre);
	}
	return 1;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
	}

	return 0;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
	}

	return 0;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	if(this != NULL)
	{
		this->sueldo = sueldo;
	}

	return 0;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	if(this != NULL && sueldo != NULL)
	{
		 *sueldo = this->sueldo;
	}

	return 0;
}

int employee_compareByName(void* elemento1 ,void* elemento2)
{
	Employee* empleadoUno;
	Employee* empleadoDos;
	char nombre[MAX_NAME];
	char nombre2[MAX_NAME];
	int comparacion;

	if(elemento1 != NULL && elemento2 != NULL)
	{
		empleadoUno = (Employee*) elemento1;
		empleadoDos = (Employee*) elemento2;

		employee_getNombre(empleadoUno, nombre);
		employee_getNombre(empleadoDos, nombre2);

		comparacion = strcmpi(nombre,nombre2);
	}

	return comparacion;
}

int employee_compareBySueldo(void* elemento1 ,void* elemento2)
{
	Employee* empleadoUno;
	Employee* empleadoDos;
	int sueldo1;
	int sueldo2;
	int comparacion;

	if(elemento1 != NULL && elemento2 != NULL)
	{
		comparacion = 0;

		empleadoUno = (Employee*) elemento1;
		empleadoDos = (Employee*) elemento2;

		employee_getSueldo(empleadoUno, &sueldo1);
		employee_getSueldo(empleadoDos, &sueldo2);

		if(sueldo1 > sueldo2)
		{
			comparacion = 1;
		}
		else
		{
			if(sueldo1 < sueldo2)
			{
				comparacion = -1;
			}
		}
	}

	return comparacion;
}


int employee_setNombreManually(Employee* this)
{
	int state;
	char nombre[MAX_NAME];

	state = -1;

	if (this != NULL)
	{
		getStringVerificado("\n\t\t\t\t\t\t\tIngrese su nombre porfavor :) : ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese su nombre por favor) - ERROR : \n",
		nombre);

		employee_setNombre(this, nombre);
		state = 0;
	}

		return state;
}

int employee_setSueldoManually(Employee* this)
{
	int state;
	int sueldo;

	state = -1;

	if (this != NULL)
	{
		sueldo = getValidInt("\n\t\t\t\t\t         Ingrese el pago de su ultimo recibo de sueldo porfavor: ",
		"\n\n\t\t\t\t      ERROR - (RE-Ingrese su sueldo porfavor) - ERROR: \n\n", 1,500000);

		employee_setSueldo(this, sueldo);
		state = 0;
	}

		return state;
}

int employee_setHorasTrabajadasManually(Employee* this)
{
	int state;
	int horasTrabajadas;

	state = -1;

	if (this != NULL)
	{
		horasTrabajadas = getValidInt("\n\t\t\t\t\t         Ingrese las horas trabajadas en el ultimo mes :) : ",
		"\n\n\t\t\t\t      ERROR - (RE-Ingrese las horas trabajadas en el ultimo mes :) ) - ERROR: \n\n", 1, 500);


		employee_setHorasTrabajadas(this, horasTrabajadas);
		state = 0;
	}

		return state;
}
//llevar los show a controller list
int employee_showOneEmployee(Employee* this)
{
	int state;
	int id;
	char nombre[MAX_NAME];
	int horas;
	int sueldo;

	state = -1;
	if(this != NULL)
	{
		employee_getHorasTrabajadas(this, &horas);
		employee_getId(this, &id);
		employee_getSueldo(this, &sueldo);
		employee_getNombre(this, nombre);

		printf("\t\t\t\t\t\t|%4i  |%12s   | %10i         | %9i   |\n",id,nombre,horas,sueldo);
		state = 0;
	}


	return state;
}

int employee_showAllEmployee(LinkedList* listaEmpleados)
{
	int state;
	Employee* aux;
	int employeesLen;

	state = -1;

	printf("\n\n\t\t\t\t\t\t| ID   |      Nombre   |  Horas Trabajadas  |    Salario  |\n");

	if(listaEmpleados != NULL)
	{
		employeesLen = ll_len(listaEmpleados);
		for(int i = 0; i < employeesLen ; i++)
		{
		aux = ll_get(listaEmpleados,i);
			employee_showOneEmployee(aux);

		    state = 0;
		}
	}
	  return state;
}

int employee_searchIndexById(LinkedList* listaEmpleados, int id)
{
	int state;
	int workersLen;
	Employee* aux;
	int idAux;

	if(listaEmpleados != NULL)
	{
		workersLen = ll_len(listaEmpleados); //// Le paso la linked list, para saber el total cargados at the moment

		for(int i = 0; i < workersLen; i++)
		{
			aux = ll_get(listaEmpleados, i);

			employee_getId(aux, &idAux);

			if(idAux == id)
			{
				state = i;
				break;
			}
		}

	}

		return state;
}
/// llevar al controlador
int employee_askValidId(LinkedList* listaEmpleados)
{
	int state;
	int workersLen;
	Employee* aux;
	int idToModify;
	int idAux;
	int pos;

	state = -1;

	if(listaEmpleados != NULL)
	{
		workersLen = ll_len(listaEmpleados);

		while(state == -1)
		{
			employee_showAllEmployee(listaEmpleados);

			idToModify = getValidInt("\n Seleccione a un cliente de la lista recien vista para (MODIFICAR) || (Eliminar) : \n\t\t\t    ",
			"Ese cliente no existe", 1, 9999);

			for(int i = 0; i < workersLen; i++)
			{
				aux = ll_get(listaEmpleados, i);

				employee_getId(aux, &idAux);

				if(idAux == idToModify)
				{
					pos = i;
					state = 0;
					return pos;
					break;
				}
			}
			printf("\nNo existe ningun empleado con esa ID, ingreselo nuevamente!\n\n");
		}
	}

	return state;
}





































