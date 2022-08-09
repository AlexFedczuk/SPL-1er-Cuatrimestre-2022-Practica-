#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Participante.h"
#include "miBiblioteca.h"
#include "inputFuntions.h"

#define ARCH "MOCK_DATA.csv"
#define ID_ARCH "idMaximo.csv"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Alta de pasajero
     3. Modificar datos de pasajero
     4. Baja de pasajero
     5. Listar pasajeros
     6. Ordenar pasajeros
     7. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     8. Salir

*****************************************************/
int main()
{
	setbuf(stdout, NULL);
    
    int option = 0;
    int banderaLoad = 1;
    int banderaSave = 1;
    int banderaExit = 1;
    int idMaximo;

    idMaximo = GetMaximumID(ID_ARCH);
    LinkedList* listaParticipantes = ll_newLinkedList();

    while(banderaExit == 1){
        mostrarMenu();
        getNumeroInt(&option, "Ingrese una opcion del menu principal: ", "\nError! Valor ingresado invalido!\n", 1, 8, 0, BUFFER_SIZE);
        //fflush(stdin); Si dejo este 'fflush' no deja ingresar a los 'cases'...
        switch(option)
        {
            case 1:
            	if(banderaLoad == 1)
            		banderaLoad = controller_loadFromText(ARCH, listaParticipantes);
                break;
            case 2:
                //controller_addPassenger(listaPasajeros, &idMaximo); 
                break;
            case 3:
            	/*if(ll_len(listaPasajeros) >= 1)
            		controller_editPassenger(listaPasajeros);*/
                break;
            case 4:
            	/*if(ll_len(listaPasajeros) >= 1)
            		controller_removePassenger(listaPasajeros); */
                break;
            case 5:
            	/*if(ll_len(listaPasajeros) >= 1)
            		controller_ListPassenger(listaPasajeros); */
                break;
            case 6:
            	/*if(ll_len(listaPasajeros) >= 1)
            		controller_sortPassenger(listaPasajeros); */
                break;
            case 7:
                banderaSave = controller_saveAsText(ARCH, listaParticipantes);
                break;
            case 8:
            	banderaExit = controller_exit(listaParticipantes, banderaSave, ARCH, ID_ARCH, &idMaximo);
            	break;
            default:
                break;
        }
        fflush(stdin);
    }

    return 0;
}
