/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//Publicas
LinkedList* ll_newLinkedList(void); // CREA LA LISTA EN MEMORIA // AGREGA LA LOCOMOTORA
int ll_add(LinkedList* this, void* pElement);// CREA Y AGREGA UN NODO CON EL SIGUIENTE
void* ll_get(LinkedList* this, int index);// DEVUELVE LA DIREC MEM DE LO QUE ESTÁ GESTIONANDO HAY QUE CASTEARLO
int ll_set(LinkedList* this, int index,void* pElement); // hace que un nodo apunte a lugar
int ll_push(LinkedList* this, int index, void* pElement);// CREA NODO Y LO ENGANCHA CON OTRO, REMPLAZA UN DATO DE LUGAR, METE UNO EN EL MEDIO
int ll_remove(LinkedList* this,int index);// REMUEVE UN NODO
void* ll_pop(LinkedList* this,int index);// Saca el elemento del indice y lo devuelve mediante puntero void
int ll_len(LinkedList* this); // Desengancha nodos de la linked list
int ll_deleteLinkedList(LinkedList* this);// desengancha los nodos y destruye la locomotora "LL"
int ll_indexOf(LinkedList* this, void* pElement);// le paso un elemento y me dice en que indice está
int ll_isEmpty(LinkedList* this);// HAY VAGONES ENGANCHADOS? UNO 0
int ll_contains(LinkedList* this, void* pElement);// SI YO LE PASO UNA DIRECCION DE MEMORIA ME DICE SI ESTÁ O NO CONTAINS LLAMA A INDEXOF
int ll_containsAll(LinkedList* this,LinkedList* this2);// SI UNA LISTA ESTÁ CONTENIDA EN OTRA
LinkedList* ll_subList(LinkedList* this,int from,int to); // DEVUELVE DE UNA LISTA DESDE UNA **POSICION** "TOOOO" OTRA POSICION
LinkedList* ll_clone(LinkedList* this);// COPIA LA LISTA CON SU ORDEN
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);// CON LA FUNCION SE LE PASA EL CRITERIO DE ORDENAMIENTO



Node* test_getNode(LinkedList* this, int nodeIndex); //
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);//
int ll_clear(LinkedList* this);//
