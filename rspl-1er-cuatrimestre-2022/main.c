/*
 ============================================================================
 Name        : SPL.c
 Author      : Alex Yago Fedczuk
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "Comic.h"
#include "LinkedList.h"
#include "miBiblioteca.h"
#include "inputFuntions.h"

int main(void){
	setbuf(stdout, NULL);

	char arch[51] = "datos_RSP_1F_M2.csv";
	char archNuevo[51] = "mapeado.csv";
	int opcionMenu;
	int resultado = 1;
	int bandera = 1;
	
	LinkedList* pLista;
	
	pLista = ll_newLinkedList();

	do{
	        mostrarMenu();
	        getNumeroInt(&opcionMenu, "Ingrese una opcion del menu principal: ", "\nError! Valor ingresado invalido!\n", 1, 6, 0, BUFFER_SIZE);
	        
	        switch(opcionMenu){
	            case 1:
	                bandera = Controller_CargaDeArchivo(arch, pLista);
	                break;
	            case 2:
	            	Controller_Ordenar(pLista, bandera, Comic_ComperByPower, 1);
	            	break;
	            case 3:
	            	Controller_Listar(pLista, bandera);
	                break;
	            case 4:
					Controller_Modificar(pLista, bandera, ll_map, Comic_DescontarPower);/* Habria que probar si funcionaria en un caso real. */
	                break;
	            case 5:
					Controller_Guardar(archNuevo, lista, bandera);
	                break;
	            default:
	                system("pause");
	                system("cls");// No reconoce la funcion en el GDB, porque no lo "admite" la consola.
	            	break;
	        }
	    }while(opcionMenu != 6);

	return 0;
}
