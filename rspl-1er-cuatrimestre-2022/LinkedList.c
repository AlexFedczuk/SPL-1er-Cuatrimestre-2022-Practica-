#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../inc/LinkedList.h"
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex, void* pElement);

LinkedList* ll_newLinkedList(void){
    LinkedList* this;

	this = (LinkedList*) malloc(sizeof(void*));

    if(this != NULL){
    	this->pFirstNode = NULL;
    	this->size = 0;
    }

    return this;
}

int ll_len(LinkedList* this){
    int retorno = -1;

    if(this != NULL){
    	retorno = this->size;
    }

    return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                          (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex){
	Node* pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
		pNode = this->pFirstNode;	// Asigno el primer nodo.

		for(int i = 0; i < nodeIndex; i++){	//	Mientras el indice sea menor al nodo buscado.		
			pNode = pNode->pNextNode;
		}
	}

    return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex){
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
static int addNode(LinkedList* this, int nodeIndex, void* pElement){
    int retorno = -1;

	int len;
    Node* pNode = NULL;
    Node* auxNode = NULL;

    len = ll_len(this);

	if(this != NULL && len >= 0 && nodeIndex >= 0 && nodeIndex <= len){

		pNode = (Node*) malloc(sizeof(Node));

		if(pNode != NULL){
			pNode->pElement = pElement;
			pNode->pNextNode = NULL;

			if(!nodeIndex){
				pNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pNode;
			}else{
				auxNode = getNode(this, nodeIndex - 1);

				if(auxNode != NULL){
					pNode->pNextNode = auxNode->pNextNode;
					auxNode->pNextNode = pNode;
				}
			}

			this->size++;
			retorno = 0;
		}
	}

    return retorno;
}

int test_addNode(LinkedList* this, int nodeIndex, void* pElement){
    return addNode(this, nodeIndex, pElement);
}

int ll_add(LinkedList* this, void* pElement){
    int retorno = -1;

    if(this != NULL){
    	retorno = addNode(this, ll_len(this), pElement);
    }

    return retorno;
}

void* ll_get(LinkedList* this, int index){
    void* retorno = NULL;
    Node* pNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){
    	pNode = getNode(this, index);

    	if(pNode != NULL){
    		retorno = pNode->pElement;
    	}
    }

    return retorno;
}

int ll_set(LinkedList* this, int index, void* pElement){
    int retorno = -1;
    Node* pNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this, index);

    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;
    		retorno = 0;
    	}
    }

    return retorno;
}

int ll_remove(LinkedList* this, int index){
    int retorno = -1;
    Node* pNode = NULL;
    Node* auxNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){
    	pNode = getNode(this, index);

    	if(pNode != NULL){
			if(index == 0){
				this->pFirstNode = pNode->pNextNode;
			}else{
				auxNode = getNode(this, index-1);

				if(auxNode != NULL){
					auxNode->pNextNode = pNode->pNextNode;
				}
			}

			free(pNode);

			this->size--;
			retorno = 0;
    	}
    }

    return retorno;
}

int ll_clear(LinkedList* this){
    int retorno = -1;
    int len;

    if(this != NULL){
    	len = ll_len(this);

    	while(len > 0){
			ll_remove(this, len - 1);
			len--;
    	}

    	retorno = 0;
    }

    return retorno;
}

int ll_deleteLinkedList(LinkedList* this){
    int retorno = -1;

    if(this != NULL){
    	if(ll_clear(this) == 0){
			free(this);
			retorno = 0;
    	}
    }

    return retorno;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno = -1;
    int len;
    Node* pNode = NULL;

    if(this != NULL){
    	len = ll_len(this);

    	while(len > 0){
    		pNode = getNode(this, len - 1);

    		if(pNode != NULL){
    			if(pNode->pElement == pElement){
    				retorno = len - 1;
    				break;
    			}
    		}
    		len--;
    	}
    }

    return retorno;
}

int ll_isEmpty(LinkedList* this){
    int retorno = -1;

    if(this != NULL){
		retorno = 1;

    	if(ll_len(this) > 0){
    		retorno = 0;
    	}
    }

    return retorno;
}

int ll_push(LinkedList* this, int index, void* pElement){
    int retorno = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this)){
		retorno = addNode(this, index, pElement);
    }

    return retorno;
}

void* ll_pop(LinkedList* this, int index){
    void* retorno = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){
    	retorno = ll_get(this, index);
		ll_remove(this, index);
    }

    return retorno;
}

int ll_contains(LinkedList* this, void* pElement){
    int retorno = -1;

    if(this != NULL){
		retorno = 1;

    	if(ll_indexOf(this, pElement) == -1){
			retorno = 0;
    	}
    }

    return retorno;
}

int ll_containsAll(LinkedList* this, LinkedList* this2){
    int retorno = -1;
    void* pElement = NULL;

    if(this != NULL && this2 != NULL){
		retorno = 1;

    	for(int i = 0; i < ll_len(this2); i++){
    		pElement = ll_get(this2, i);

			if(ll_contains(this, pElement) == 0){
				retorno = 0;
				break;
			}
    	}
    }

    return retorno;
}

LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement = NULL;

    if(this != NULL && (from >= 0 && from <= ll_len(this)) && (to >= 0 && to <= ll_len(this)) && from <= to){
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL){
    		for(int i = from; i < to; i++){
    			pElement = ll_get(this, i);

    			if(pElement != NULL){
					ll_add(cloneArray, pElement);
    			}
    		}
    	}
    }

    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this){
    LinkedList* cloneArray = NULL;

    if(this != NULL){
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* , void*), int order){
    int retorno = -1;
    int len;
    void* pElement1 = NULL;
    void* pElement2 = NULL;
	int funtionResult;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	len = ll_len(this);

		for(int i = 0; i < len - 1; i++){
			for(int j = i + 1; j < len; j++){
				pElement1 = ll_get(this, i);
				pElement2 = ll_get(this, j);

				funtionResult = pFunc(pElement1, pElement2);

				if( (funtionResult < 0 && order == 0) || (funtionResult > 0 && order == 1)){
					ll_set(this, i, pElement2);
					ll_set(this, j, pElement1);
				}
			}
		}

		retorno = 0;
    }

    return retorno;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*)){
    int len;
    void* pElement = NULL;
	int funtionResult;
	LinkedList* nuevaLista;

    if(this != NULL && pFunc != NULL)
    {
    	nuevaLista = ll_newLinkedList();
    	len = ll_len(this);

		for(int i = 0; i < len; i++){
			pElement = ll_get(this, i);

			funtionResult = pFunc(pElement);
			if(funtionResult == 1){
				ll_add(nuevaLista, pElement);
			}
		}
    }

    return nuevaLista;
}


int ll_map(LinkedList* this, int(*pFunc)(void*)){
    int retorno = -1;

    int len;
    void* pElement = NULL;

    if(this != NULL && pFunc != NULL)
    {
    	len = ll_len(this);


			for(int i = 0; i < len; i++){
				pElement = ll_get(this, i);

				pFunc(pElement);
			}

		retorno = 0;
    }

    return retorno;
}
