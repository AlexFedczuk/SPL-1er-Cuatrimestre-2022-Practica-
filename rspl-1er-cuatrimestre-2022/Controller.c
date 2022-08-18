#include "Controller.h"

int Controller_CargaDeArchivo(char* arch, LinkedList* pList){
    int retorno = -1;
    FILE* pFile;
    
    if(arch != NULL && pList != NULL){
        pFile = fopen(arch, "r");

        if(pFile != NULL){
            Parser_FromText(pFile, pList);
        }
        
        retorno = 0;
    }else{
        printf("\nERROR! Hubo un problema para cargar los datos del archivo: %s\n", arch);
    }
    
    return retorno;
}

int Controller_Ordenar(LinkedList* pList, int bandera, int (*pFunc)(void*), int order){
    int retorno = -1;

    if(pList != NULL && pFunc != NULL){
        if(bandera == 0){
            ll_sort(pList, pFunc, order);
            retorno = 0;
        }else{
            printf("\nBandera No es igual a cero (0).\n");
        }
        
    }else{
        printf("\nERROR! Hubo un problema para ordenar la lista.\n");
    }

    return retorno;
}

int Controller_Listar(LinkedList* pList, int bandera){
    int retorno = -1;

    if(pList != NULL){
        if(bandera == 0){
            Comic_List(pList);
            retorno = 0;
        }else{
            printf("\nBandera No es igual a cero (0).\n");
        }
    }else{
        printf("\nERROR! Hubo un problema para generar una lista.\n");
    }

    return retorno;
}

int Controller_Modificar(LinkedList* pList, int bandera, int (*pFuncUno), int (*pFuncDos)){
    int retorno = -1;
    int len;

    if(pList != NULL && pFuncUno != NULL && pFuncDos != NULL){
        if(bandera == 0){
            len = ll_len(pList);
            
            for(int i = 0; i < len; i++){
                pFuncUno(pList, pFuncDos);
            }

            retorno = 0;
        }else{
            printf("\nBandera No es igual a cero (0).\n");
        }
        
    }else{
        printf("\nERROR! Hubo un problema para ingresar a la opcion 'Modificar'.\n");
    }

    return retorno;
}

int Controller_Guardar(char* arch, LinkedList* pList, int bandera){
    int retorno = -1;

    FILE* pFile;

    if(arch != NULL && pList != NULL){
        if(bandera == 0){
            pFile = fopen(arch, "w");

            if(pFile != NULL){
                Parser_ToText(pFile, pArrayListPassenger);
            }

            fclose(pFile);

            printf("\nSe a guardado el archivo como texto.\n");

            retorno = 0;
        }else{
            printf("\nBandera No es igual a cero (0).\n");
        }
    }else{
        printf("\nERROR! Hubo un problema e el controlador de 'Guardar'.\n");
    }

    return retorno;
}
