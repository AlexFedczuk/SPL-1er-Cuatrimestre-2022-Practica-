#include "Parser.h"

int parser_FromText(FILE* pFile, LinkedList* pList)
{
    int retorno = -1;
    
    if(pFile != NULL && pList != NULL){
    	Comic_CargarArchivo(pFile, pList);
        retorno = 0;
    }
    return retorno;
}

int parser_ToText(LinkedList* pList, char* arch)
{
    int retorno = -1;

    if(pList != NULL && arch != NULL){
        Comic_GuardarComics(arch, pList);
    }else{
        printf("\nERROR! Hubo un problema con el Parser.\n");
    }
    return retorno;
}
