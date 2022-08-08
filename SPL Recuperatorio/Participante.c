/*
 * Participante.c
 *
 *  Created on: 08/08/2022
 *      Author: Maru
 */
#include "Participante.h"

/** \brief Guarda los datos de los Participantes en el archivo data.csv (modo texto).
 *
 * \param path char*, La direccion de memoria donde se encuentra el nombre del archivo.
 * \param pArrayList LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
eParticipante* Participante_new(){
    return malloc(sizeof(eParticipante));
}

int Participante_pedirDatos(LinkedList* pArrayList, char* respuesta, int* idMaximo){
    int retorno = -1;

    int id;
	char nombre[51];
	int  edad;
	int idCategoria;
	float score;
	int isEmpty;

    eParticipante* pParticipante;
    eParticipante* auxParticipante;

    auxParticipante = Participante_new();

    if(pArrayList != NULL && auxParticipante != NULL && respuesta != NULL){
    	pParticipante = auxParticipante;

    	id = *idMaximo + 1;
    	*idMaximo = id;

    	PedirNombre("\nIngrese el nombre del Participante: ", nombre, 50);
    	fflush(stdin);

        getNumeroInt(&edad, "\nIngrese la edad del Participante: ", "\nError! Valor ingresado invalido!\n", 0, 150, 0, BUFFER_SIZE);
    	fflush(stdin);

        getNumeroInt(&idCategoria, "\n1 - MENOR\n2 - MAYOR\nIngrese la categoria del Participante: ", "\nError! Valor ingresado invalido!\n", 1, 2, 0, BUFFER_SIZE);
    	fflush(stdin);

    	getNumeroFloat(&score, "\nIngrese el Score del Participante: ", "\nError! Valor ingresado invalido!\n", -2.147.483.647, 2.147.483.647, 0, BUFFER_SIZE);
    	fflush(stdin);

    	Participante_newParametrosCompletosAlta(pParticipante,id,nombre,edad,idCategoria,score);

    	ll_add(pArrayList, pParticipante);

    	getUnCaracter(respuesta, "\nQuiere realizar otra Alta? (s/n): ", "\nError! Valor ingresado invalido!\n", 0, BUFFER_SIZE);
    	fflush(stdin);

        retorno = 0;
    }
    
    return retorno;
}

eParticipante* Participante_newParametrosCompletos(eParticipante* pParticipante, int id, char* nombre, char* edad, char* idCategoria, char* score){
	eParticipante* unParticipante = NULL;
	eParticipante* auxParticipante;

	auxParticipante = (eParticipante*) malloc(sizeof(eParticipante));

	if(pParticipante != NULL &&	nombre != NULL && score != NULL && edad != NULL && idCategoria != NULL){
		unParticipante = auxParticipante;

        Participante_setId(unParticipante, id);
        Participante_setNombre(unParticipante, nombre);
        Participante_setScore(unParticipante, atof(score));        
        Participante_setEdad(unParticipante, atoi(edad));
        Participante_setIdCategoria(unParticipante, atof(idCategoria));
        Participante_setIsEmpty(unParticipante, 0);
	}

	return unParticipante;
}

int Participante_newParametrosCompletosAlta(eParticipante* pParticipante, int id, char* nombre, int edad, int idCategoria, float score){
	int retorno = -1;

	if(pParticipante != NULL){
        Participante_setId(unParticipante, id);
        Participante_setNombre(unParticipante, nombre);
        Participante_setScore(unParticipante, score);        
        Participante_setEdad(unParticipante, edad);
        Participante_setIdCategoria(unParticipante, idCategoria);
        Participante_setIsEmpty(unParticipante, 0);

        retorno = 0;
	}

	return retorno;
}

void Participante_delete(eParticipante* this){
    
    if(this != NULL){
        free(this);
    }
}

int Participante_setId(eParticipante* this, int id){
    int retorno = -1;
    
    if(this != NULL){
        this->id = id;
    }
    return retorno;
}
int Participante_getId(eParticipante* this, int* id){
    int retorno = -1;
    
    if(this != NULL){
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int Participante_setNombre(eParticipante* this, char* nombre){
    int retorno = -1;
    
    if(this != NULL){
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}
int Participante_getNombre(eParticipante* this, char* nombre){
    int retorno = -1;
    
    if(this != NULL){
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}
int Participante_modificarNombre(eParticipante* pParticipante){
    int retorno = -1;
    char nombre[50];
    
    if(pParticipante != NULL){
        PedirNombre("\n\tIngrese el nuevo nombre del Participante: ", nombre, 50);
        fflush(stdin);
        Participante_setNombre(pParticipante, nombre);
        printf("\n\tSe le a modificado el nombre al Participante seleccionado.\n");
        retorno = 0;
    }
    return retorno;
    
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
    int retorno = -1;
    
    if(this != NULL){
        this->tipoPasajero = tipoPasajero;
        retorno = 0;
    }
    return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
    int retorno = -1;
    
    if(this != NULL){
        *tipoPasajero = this->tipoPasajero;
        retorno = 0;
    }
    return retorno;
}
int Passenger_modificarTipoPasajero(Passenger* pPasajero){
    int retorno = -1;
    int tipoPasajero;
    
    if(pPasajero != NULL){
        getNumeroInt(&tipoPasajero, "\n\tIngrese el nuevo tipo de pasajero 'FirstClass'(0), 'ExecutiveClass'(1) o 'EconomyClass'(2): ", "\nError! Valor ingresado invalido!\n", 0, 2, 0, BUFFER_SIZE);
        fflush(stdin);
        Passenger_setTipoPasajero(pPasajero, tipoPasajero);
        printf("\n\tSe le a modificado el Tipo de Pasajero.\n");
        retorno = 0;
    }
    return retorno;
    
}

int Participante_setScore(eParticipante* this, float score){
    int retorno = -1;
    
    if(this != NULL){
        this->score = score;
        retorno = 0;
    }
    return retorno;
}
int Participante_getScore(eParticipante* this, float* score){
    int retorno = -1;
    
    if(this != NULL){
        *score = this->score;
        retorno = 0;
    }
    return retorno;
}
int Participante_modificarScore(eParticipante* pParticipante){
    int retorno = -1;
    float score;
    
    if(pParticipante != NULL){
        getNumeroFloat(&score, "\n\tIngrese el nuevo score: ", "\nError! Valor ingresado invalido!\n", 0, 999999999, 0, BUFFER_SIZE);
        fflush(stdin);
        Participante_setScore(pParticipante, score);
        printf("\n\tSe le a modificado el score al participante seleccionado.\n");
        retorno = 0;
    }
    return retorno;
    
}


int Passenger_setIsEmpty(Passenger* this,int isEmpty){
    int retorno = -1;
    
    if(this != NULL){
        this->isEmpty = isEmpty;
        retorno = 0;
    }
    return retorno;
}
int Passenger_getIsEmpty(Passenger* this,int* isEmpty){
    int retorno = -1;
    
    if(this != NULL){
        *isEmpty = this->isEmpty;
        retorno = 0;
    }
    return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo){
    int retorno = -1;

    if(this != NULL){
        this->estadoVuelo = estadoVuelo;
        retorno = 0;
    }
    return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo){
    int retorno = -1;

    if(this != NULL){
        *estadoVuelo = this->estadoVuelo;
        retorno = 0;
    }
    return retorno;
}
int Passenger_modificarEstadoVuelo(Passenger* pPasajero){
    int retorno = -1;
    int estadoVuelo;
    
    if(pPasajero != NULL){
        getNumeroInt(&estadoVuelo, "\nIngrese el nuevo estado del vuelo 'Aterrizado'(0), 'En Horario'(1) o 'En Vuelo'(2): ", "\nError! Valor ingresado invalido!\n", 0, 2, 0, BUFFER_SIZE);
        fflush(stdin);
        Passenger_setEstadoVuelo(pPasajero, estadoVuelo);
        printf("\n\tSe le a modificado el estado de vuelo al pasajero seleccionado.\n");
        retorno = 0;
    }
    return retorno;
    
}

int Passenger_CompareById(void* pUno, void* pDos){
	int retorno = -2;
	int compara = 0;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		if(unPasajero->id > otroPasajero->id){
			compara = 1;
		}else{
			if(unPasajero->id < otroPasajero->id){
				compara = -1;
			}
		}
		retorno = compara;
	}

	return retorno;
}

int Passenger_CompareByName(void* pUno, void* pDos){
	int retorno = -2;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		retorno = strcmp(unPasajero->nombre, otroPasajero->nombre);// Esto puede devolver -1 o 0 o 1, segun sea la comparacion de las cadenas...
	}

	return retorno;
}

int Passenger_CompareByLastName(void* pUno, void* pDos){
	int retorno = -2;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		retorno = strcmp(unPasajero->apellido, otroPasajero->apellido);// Esto puede devolver -1 o 0 o 1, segun sea la comparacion de las cadenas...
	}

	return retorno;
}

int Passenger_CompareByPrice(void* pUno, void* pDos){
	int retorno = -2;
	int compara = 0;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		if(unPasajero->precio > otroPasajero->precio){
			compara = 1;
		}else{
			if(unPasajero->precio < otroPasajero->precio){
				compara = -1;
			}
		}
		retorno = compara;
	}

	return retorno;
}

int Passenger_CompareByFlyCode(void* pUno, void* pDos){
	int retorno = -2;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		retorno = strcmp(unPasajero->codigoVuelo, otroPasajero->codigoVuelo);// Esto puede devolver -1 o 0 o 1, segun sea la comparacion de las cadenas...
	}

	return retorno;
}

int Passenger_CompareByTypePassenger(void* pUno, void* pDos){
	int retorno = -2;
	int compara = 0;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		if(unPasajero->tipoPasajero > otroPasajero->tipoPasajero){
			compara = 1;
		}else{
			if(unPasajero->tipoPasajero < otroPasajero->tipoPasajero){
				compara = -1;
			}
		}
		retorno = compara;
	}

	return retorno;
}

int Passenger_CompareByStatusFlight(void* pUno, void* pDos){
	int retorno = -2;
	int compara = 0;
	Passenger* unPasajero;
	Passenger* otroPasajero;

	if(pUno != NULL && pDos != NULL){
		unPasajero = (Passenger*) pUno;
		otroPasajero = (Passenger*) pDos;

		if(unPasajero->estadoVuelo > otroPasajero->estadoVuelo){
			compara = 1;
		}else{
			if(unPasajero->estadoVuelo < otroPasajero->estadoVuelo){
				compara = -1;
			}
		}
		retorno = compara;
	}

	return retorno;
}

int Passenger_ListPasajeros(LinkedList* pArrayListPassenger){
    int retorno = -1;
    int tam;
    int auxId;
    char auxNombre[50];
    char auxApellido[50];
    float auxPrecio;
    char auxCodigoVuelo[4];
    int auxTipoPasajero;
    int auxEstadoVuelo;
    int auxIsEmpty;
    char tipoPasajero[50];
    char estadoVuelo[50];
    
    Passenger* pPasajero;

    if(pArrayListPassenger != NULL){
        tam = ll_len(pArrayListPassenger);
        
        
        printf("  id,           name,       lastname,        price,         flycode,               typePassenger,          statusFlight\n\n");
        for(int i = 0; i < tam; i++){
            pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
            
            Passenger_getId(pPasajero, &auxId);
            Passenger_getNombre(pPasajero, auxNombre);
            Passenger_getApellido(pPasajero, auxApellido);
            //Passenger_getPrecio(pPasajero, &auxPrecio);
            auxPrecio = pPasajero->precio;
            Passenger_getCodigoVuelo(pPasajero, auxCodigoVuelo);
            Passenger_getTipoPasajero(pPasajero, &auxTipoPasajero);
            Passenger_getEstadoVuelo(pPasajero, &auxEstadoVuelo);
            Passenger_getIsEmpty(pPasajero, &auxIsEmpty);
            
            if(auxTipoPasajero == 0){
                strcpy(tipoPasajero, "FirstClass");
            }else{
                if(auxTipoPasajero == 1){
                    strcpy(tipoPasajero, "ExecutiveClass");
                }else{
                    if(auxTipoPasajero == 2){
                        strcpy(tipoPasajero, "EconomyClass");
                    }else{
                        strcpy(tipoPasajero, " ");
                    }
                }
            }
                
            if(auxEstadoVuelo == 0){
                strcpy(estadoVuelo, "Aterrizado");
            }else{
                if(auxEstadoVuelo == 1){
                    strcpy(estadoVuelo, "En Horario");
                }else{
                    if(auxEstadoVuelo == 2){
                        strcpy(estadoVuelo, "En Vuelo");
                    }else{
                        strcpy(estadoVuelo, " ");
                    }
                }
            }
            
            if(/*auxIsEmpty != 0*/1){
                printf("%04d,%15s,%15s,   %10.2f,  %14s,             %15s,            %s\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, tipoPasajero, estadoVuelo);
            }
        }
        retorno = 0;
    }
    
    return retorno;
}

int Passenger_CalcularMaximoID(LinkedList* pArrayListPassenger){
    int retorno = -1;
    int len;
    int idMax;
    int auxId;
    int auxIsEmpty;
    Passenger* pPasajero;
    
    if(pArrayListPassenger != NULL){
        len = ll_len(pArrayListPassenger);
        
        for(int i = 0; i < len; i++){
            pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
            
            Passenger_getId(pPasajero, &auxId);
            Passenger_getIsEmpty(pPasajero, &auxIsEmpty);
            if(/*auxIsEmpty == 0*/1){
                if(i == 0 || idMax < auxId){
                    idMax = auxId;
                }
            }
        }
        retorno = idMax + 1;
    }
    return retorno;
}

int Passenger_getIndicePasajero(LinkedList* pArrayListPassenger, int* indice, char* mensaje){
	int retorno = -1;
	int idIngresado, len, auxId;
	Passenger* pPasajero;

	if(pArrayListPassenger != NULL && indice != NULL && mensaje != NULL){
		len = ll_len(pArrayListPassenger);
		getNumeroInt(&idIngresado, mensaje, "\nError! Valor ingresado invalido!\n", 1, len, 0, BUFFER_SIZE);

		for(int i = 0; i < len; i++){
			pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_getId(pPasajero, &auxId);
			if(auxId == idIngresado){
				retorno = 0;
				break;
			}
		}
		*indice = ll_indexOf(pArrayListPassenger, pPasajero);
	}

	return retorno;
}

int Passenger_modificarPasajero(LinkedList* pArrayListPassenger, int indice){
	int retorno = -1;
	int opcion;
	Passenger* pPasajero;
	
	if(pArrayListPassenger != NULL){
	    pPasajero = ll_get(pArrayListPassenger, indice);
	    if(pPasajero != NULL){
	        do{
	            mostrarMenuModificacion();
        	    getNumeroInt(&opcion, "\tIngrese una opcion del menu de modificacion: ", "\nError! Valor ingresado invalido!\n", 1, 7, 0, BUFFER_SIZE);
        	    fflush(stdin);
        	    
        	    switch(opcion)
        	    {
        	        case 1:
        	            Passenger_modificarNombre(pPasajero);
            	        break;
        	        case 2:
            	        Passenger_modificarApellido(pPasajero);
            	        break;
        	        case 3:
            	        Passenger_modificarPrecio(pPasajero);
            	        break;
        	        case 4:
            	        Passenger_modificarTipoPasajero(pPasajero);
            	        break;
        	        case 5:
            	        Passenger_modificarCodigoVuelo(pPasajero);
            	        break;
        	        case 6:
            	        Passenger_modificarEstadoVuelo(pPasajero);
            	        break;
        	        default:
        	            printf("\n\tSaliendo del menu de modificacion.\n");
        	            break;
        	    }
	        }while(opcion != 7);
    	    retorno = 0;
	    }
	}

	return retorno;
}
