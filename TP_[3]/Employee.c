#include "Employee.h"
#include "Controller.h"

/// @fn Employee employee_newAlta*(int)
/// @brief Mediante esta funcion podemos agregar un nuevo empleado y con los datos obtenidos mediante las funciones establecerlos con los seters.
///
/// @param id
/// @return Un auxiliar de la estructura empleado.
Employee* employee_newAlta(int id)
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
	employee_setId(aux, id);

	return aux;
}

/// @fn Employee employee_new*()
/// @brief Permite reservar espacio en memoria dinamica para los empleados a crear.
///
/// @return una direccion en la memoria dinamica para guardar a los empleados.
Employee* employee_new()
{
	Employee* new;

    new = (Employee*) calloc(1,sizeof(Employee)); // Consigue espacio mediante memoria dinamica para la estructura empleado

	return new;
}

/// @fn Employee employee_newParametros*(char*, char*, char*, char*)
/// @brief Permite establecer los datos de los parametros mediante los seters de cada uno de los datos
///
/// @param idStr
/// @param nombreStr
/// @param horasTrabajadasStr
/// @param sueldoStr
/// @return Un nuevo empleado con todos sus parametros cargados.
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


	return newEmployee;
}

/// @fn void employee_delete(Employee*)
/// @brief Libera el espacio de memoria de el parametro que se le pasa los parentesis.
///
/// @param this
void employee_delete(Employee* this)
{
	free(this);
}

/// @fn int employee_setId(Employee*, int)
/// @brief pasandole el id, mediante el operador flecha se le establece el id recibido por parametros al this.
///
/// @param this
/// @param id
/// @return 0 si se pudo setear el dato y -1 si no.
int employee_setId(Employee *this, int id)
{
	int state;

	state = -1;

	if(this != NULL)
	{
		this->id = id;

		state = 0;
	}

	return state;
}
/// @fn int employee_getId(Employee*, int)
/// @brief pasandole el id, mediante el operador flecha se obtiene el id del empleado el cual está ligado a ese id.
///
/// @param this
/// @param id
/// @return 0 si se pudo obtener el dato y -1 si no.
int employee_getId(Employee* this, int* id)
{
	int state;

	state = -1;

	if(this != NULL && id != NULL)
	{
		*id = this-> id;
		state = 0;
	}

	return state;
}

/// @fn int employee_setNombre(Employee*, char)
/// @brief pasandole el nombre, mediante el operador flecha se le establece el nombre recibido por parametros al this.
///
/// @param this
/// @param id
/// @return 0 si se pudo setear el dato y -1 si no.
int employee_setNombre(Employee* this,char* nombre)
{
	int state;

	state = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		state = 0;
	}

	return state;
}

/// @fn int employee_getNombre(Employee*, int)
/// @brief pasandole el nombre, mediante el operador flecha se obtiene el nombre del empleado cual está ligado el this.
///
/// @param this
/// @param id
/// @return 0 si se pudo obtener el dato y -1 si no.

int employee_getNombre(Employee* this,char* nombre)
{
	int state;

	state = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre , this->nombre);
		state = 0;
	}

	return state;
}

/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @brief pasandole las horas trabajadas, mediante el operador flecha se le establece las horas trabajadas recibido por parametros al this.
///
/// @param this
/// @param id
/// @return 0 si se pudo setear el dato y -1 si no.
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int state;

	state = -1;

	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		state = 0;
	}

	return state;
}

/// @fn int employee_getHorasTrabajadas(Employee*, int*)
/// @brief pasandole las horas trabajadas, mediante el operador flecha se obtiene las horas trabajadas del empleado el cual está ligado a ese id.
///
/// @param this
/// @param horasTrabajadas
/// @return 0 si se pudo obtener el dato y -1 si no.
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int state;

	state = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		state = 0;
	}

	return state;
}

/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @brief pasandole el sueldo, mediante el operador flecha se le establece el sueldo recibido por parametros al this.
///
/// @param this
/// @param id
/// @return 0 si se pudo setear el dato y -1 si no.
int employee_setSueldo(Employee* this,int sueldo)
{
	int state;

	state = -1;

	if(this != NULL)
	{
		this->sueldo = sueldo;
		state = 0;
	}

	return state;
}

/// @fn int employee_getSueldo(Employee*, int*)
/// @brief pasandole el sueldo, mediante el operador flecha se obtiene el el sueldo al cual está ligado a ese empleado.
///
/// @param this
/// @param sueldo
/// @return 0 si se pudo obtener el dato y -1 si no.
int employee_getSueldo(Employee* this,int* sueldo)
{
	int state;

	state = -1;

	if(this != NULL && sueldo != NULL)
	{
	    *sueldo = this->sueldo;
		state = 0;
	}

		return state;
}

/// @fn int employee_compareByName(void*, void*)
/// @brief compara empleados los nombres de los empleados mediante los punteros void que recibe por parametros con la funcion strcmpi.
///
/// @param elemento1
/// @param elemento2
/// @return 1 0 -1 dependiendo del resultado de la comparación.
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

/// @fn int employee_compareBySueldo(void*, void*)
/// @brief compara empleados los sueldos de los empleados mediante los punteros void que recibe por parametros con la funcion strcmpi.
///
/// @param elemento1
/// @param elemento2
/// @return 1 0 -1 dependiendo del resultado de la comparación.
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

/// @fn int employee_setNombreManually(Employee*)
/// @brief pide ingresar el nombre de un nuevo empleado
///
/// @param this
/// @return -1 si no se pudo y 0 si se pudo
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

/// @fn int employee_setSueldoManually(Employee*)
/// @brief pide ingresar el sueldo de un nuevo empleado
///
/// @param this
/// @return -1 si no se pudo y 0 si se pudo
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

/// @fn int employee_setHorasTrabajadasManually(Employee*)
/// @brief pide ingresar las horas trabajadas de un nuevo empleado
///
/// @param this
/// @return -1 si no se pudo y 0 si se pudo
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

/// @fn int employee_showOneEmployee(Employee*)
/// @brief muestra un empleado obteniendo los datos mediante los geters.
///
/// @param this
/// @return 0 si pudo mostrar el empleado y -1 si no.
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

/// @fn int employee_searchIndexById(LinkedList*, int)
/// @brief busca la existencia de un id dentro del total de los empleado.
///
/// @param listaEmpleados
/// @param idToModify
/// @return 0 si se encontro, -1 si no existe.
int employee_searchIndexById(LinkedList* listaEmpleados, int idToModify)
{
	int state;
	int workersLen;
	Employee* aux;
	int idAux;
	int pos;

	workersLen = ll_len(listaEmpleados);

	state = -1;

	if(listaEmpleados != NULL)
	{
		while(state == -1)
		{
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

			idToModify = getValidInt("\n Seleccione a un cliente de la lista recien vista para (MODIFICAR) || (Eliminar) : \n\t\t\t    ",
			"Ese cliente no existe", 1, workersLen);
		}
	}

	return state;
}

/// @fn int employee_askValidId(LinkedList*)
/// @brief Pide un id para la modificación del mismo
///
/// @param listaEmpleados
/// @return devuelve la posición de ese empleado si es que existe.
int employee_askValidId(LinkedList* listaEmpleados)
{
	int idToModify;
	int pos;
	int workersLen;

	workersLen = ll_len(listaEmpleados);

	if(listaEmpleados != NULL)
	{
		controller_ListEmployee(listaEmpleados);

		idToModify = getValidInt("\n Seleccione a un cliente de la lista recien vista para (MODIFICAR) || (Eliminar) : \n\t\t\t    ",
		"Ese cliente no existe", 1, workersLen);

		pos = employee_searchIndexById(listaEmpleados,idToModify);
	}

	return pos;
}
