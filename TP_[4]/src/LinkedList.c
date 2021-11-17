#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList)); // Malloc busca un espacio de memoria para THIS del tamaño de la struct linked list
    												 // con this manipularemos la estructura linked list
    												 // Puede devolver NULL si no encuentra
    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (auxNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxNode = NULL;;
	int len;

	if(this != NULL) // No le puede llegar por parametro un indice mayor que los nodos existentes
	{
		len = ll_len(this);

		if(nodeIndex < len && nodeIndex > -1)
		{
			auxNode = this->pFirstNode; // El nodo aux obtiene la posicion de memoria de el primer nodo de la lista.

			for(int i = 0; i < nodeIndex; i++)
			{
				auxNode = auxNode->pNextNode; // Consecutivamente un nodo empezaria a mirar al siguiente
			}

		}
	}
	return auxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int state;
	int len;
	Node* PNode; /// <-- Creación de Nuevo nodo
	Node* antNodo; /// <-- Auxiliar de nodo para atajár y descubrir el nodo anterior en caso "Push".

    state = -1;

    if(this != NULL)
    {
		len = ll_len(this);

    	if(nodeIndex > -1 && nodeIndex <= len)
    	{
    		PNode = (Node*)malloc(sizeof(Node)); /// <-- Buscamos espacio en DM para nuestro nuevo Nodo.

    		if(PNode != NULL) /// <-- Si se encontró DM [Enter Sandman].
    		{
    			PNode->pElement = pElement; /// <-- Asignamos la "carga" de los parametros al nuevo Nodo.

				if(nodeIndex == 0) /// <-- Si el indice que le llega es 0 [Enter Sandman]
				{
					PNode->pNextNode = this->pFirstNode; /// <-- Apuntamos el nuevo Node a la LL para no perder la referencia.
					this->pFirstNode = PNode; /// <-- Hacemos que la Linked List Apunte al Nuevo Node.
				}
				else
				{
					antNodo = getNode(this, nodeIndex-1); /// <-- Obtengo el Nodo Anterior al que quiero agregar.
					PNode->pNextNode = antNodo->pNextNode; /// <-- Apunto el NextNode de PNode a donde apuntaba el Nodo Anterior.
					antNodo->pNextNode = PNode; /// <-- antNodo Obtiene hacia donde mira PNode.
				}
    		}
    		this->size++;
			state = 0;
    	}
    }

    return state;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna (-1) Error: si el puntero a la lista es NULL
                       ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int state;
    int len;

    state = -1;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(addNode (this, len, pElement) == 0) /// Creame un nodo de esta lista, en esta pos
    	{	 	 	 	 	 	 	 	 	  ///y con el elemento de mis params.
        	state = 0;
    	}
    }

    return state;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux;
    Node* auxNode;
    int len;

    returnAux = NULL;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(len > -1 && index < len)
    	{
			auxNode = getNode(this, index);

			if(auxNode != NULL)
			{
				returnAux = auxNode->pElement;
			}
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux;
	Node* auxNode;
	int len;

    returnAux = -1;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(index > -1 && index <= len)
    	{
    		auxNode = getNode(this, index);

    		if(auxNode != NULL)
    		{
    			auxNode->pElement = pElement;
    			returnAux = 0;
    		}
    	}
    }

    return returnAux;

}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux;
    Node* auxNode;
    Node* remove;
    int len;

    returnAux = -1;

    if(this != NULL)
    {
		len = ll_len(this);

		if(index > -1 && index < len)
		{
			remove = getNode(this,index);
			if(index == 0)
			{
				this->pFirstNode = remove->pNextNode;
			}
			else
			{
				auxNode = getNode(this, index-1);

				if(auxNode != NULL)
				{
					auxNode->pNextNode = remove->pNextNode;
				}
			}
			free(remove);
			this->size--;
			returnAux = 0;
		}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* auxNode;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(len > -1)
    	{
        	for(int i = 0; i < len; i++)
        	{
        		auxNode = getNode(this, len);
        		free(auxNode);
        		this->size--;
        	}

        	returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_clear(this) == 0)
    	{
			returnAux = 0;
    	}

    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux;
    Node* auxNode;

    returnAux = -1;

    if(this != NULL)
    {
    	for(int i = 0; i < ll_len(this); i++)
    	{
    		auxNode = getNode(this, i);

    		if(auxNode != NULL)
    		{
        		if(auxNode->pElement == pElement)
        		{
        			returnAux = i;
        			break;
        		}
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(this->size > 0)
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		if(this->size == 0)
    		{
    			returnAux = 1;
    		}
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux;
    int len;

    returnAux = -1;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(index > -1 && index <= len)
    	{
    		addNode(this, index, pElement);
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux;
    Node* auxNode;
    int len;

    returnAux = NULL;

    	if(this != NULL)
    	{
    		len = ll_len(this);

    		if(index > -1 && index <= len)
    		{
    			auxNode = getNode(this, index);

    			if(auxNode != NULL)
    			{
        			returnAux = auxNode->pElement;
        			ll_remove(this, index);
    			}
    		}
    	}
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux;
    Node* auxNode;

    returnAux = -1;

    if(this != NULL)
    {
    	int len = ll_len(this);

		returnAux = 0;

		for(int i = 0; i < len; i++)
		{
			auxNode = getNode(this, i);

			if(auxNode != NULL)
			{
				if(auxNode->pElement == pElement)
				{
					returnAux = 1;
					break;
				}
			}
		}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux;
    int lenThis1;
    void* auxPElement;
    int containsReturn;

    returnAux = -1;

    if(this != NULL && this2 != NULL)
    {
		returnAux = 1;
    	lenThis1 = ll_len(this);

    	if(lenThis1 > 0)
    	{
    		for(int i = 0; i < lenThis1; i++)
			{
    			auxPElement = ll_get(this2, i);
    			containsReturn = ll_contains(this,auxPElement);

    			if(containsReturn == 0)
    			{
    				returnAux = 0;
    				break;
    			}
			}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

