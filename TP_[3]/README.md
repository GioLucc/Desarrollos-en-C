[Volver](../README.md)
# Trabajo Práctico número 3
## 1. Enunciado
Una empresa requiere una aplicación que le permita administrar su nomina de empleados, para lo cual se deberá desarrollar una solución implementando la biblioteca `LinkedList`. Se deberá modelar la entidad que representa un empleado con todos sus datos asociados de tal manera que la misma permita interactuar con las estructuras de datos almacenadas en los archivos.

### El programa deberá tener el siguiente menú de opciones:
 1. Cargar los datos de los empleados desde el archivo `data.csv` (modo texto).
 1. Cargar los datos de los empleados desde el archivo `data.csv` (modo binario).
 1. Alta de empleado
 1. Modificar datos de empleado
 1. Baja de empleado
 1. Listar empleados
 1. Ordenar empleados
 1. Guardar los datos de los empleados en el archivo `data.csv` (modo texto).
 1. Guardar los datos de los empleados en el archivo `data.csv` (modo binario).
 1. Salir

## 2. Biblioteca `LinkedList`
Las funciones de la biblioteca `LinkedList` que deben utilizarse como mínimo son las siguientes:
```c
LinkedList* ll_newLinkedList(void);
```
> Crea y retorna un nuevo `LinkedList`. Es el constructor, ya que en él crearemos la estructura y daremos valores iniciales a los campos.

```c
void ll_deleteLinkedList(LinkedList* self);
```
> Elimina el `LinkedList`.

```c
void ll_add(LinkedList* self, void* element);
```
> Agrega un elemento al final de `LinkedList`.

```c
void ll_remove(LinkedList* self,  int index);
```
> Elimina un elemento en `LinkedList`, en el índice especificado.

```c
void* ll_get(LinkedList* self,  int index);
```
> Retorna un puntero al elemento que se encuentra en el índice especificado.

```c
int ll_len(LinkedList* self);
```
> Retorna el tamaño del `LinkedList`.

## 3. Cómo realizar y entregar el trabajo práctico
El trabajo práctico deberá ser entregado en el repositorio de GIT correspondiente al TP3 de la materia.

El mismo consistirá en el proyecto de `Code::Blocks` con el programa funcionando y comentado, respetando las reglas de estilo de la cátedra. La compilación no deberá arrojar mensajes de `error` ni de `warnings`.

El proyecto deberá contar con la biblioteca `LinkedList` la cual se proveerá como una biblioteca estática, y se deberá hacer uso de dichas funciones para resolver la lógica del programa.

### 3.1. Objetivo
El objetivo del siguiente trabajo es que el alumno sea capaz de demostrar que puede integrar los conocimientos aprendidos durante la cursada en un caso real. Los conocimientos necesarios para la realización del TP son los siguientes:
* Manejo de punteros.
* Manejo de LinkedList.
* Manejo de estructuras.
* Manejo de memoria dinámica.
