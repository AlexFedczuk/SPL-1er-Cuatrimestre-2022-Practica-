/*
 * Comic.c
 *
 *  Created on: Aug 11, 2022
 *      Author: Alex Yago Fedczuk
 */
#include "Comic.h"

int Comic_CargarArchivo(FILE* pFile, LinkedList* pList){
	int retorno = -1;

	char id[50];
	char nombre[50];
	char idTipo[50];
	char power[50];
	char resistencia[50];

	eComic* pComic;

	if(pFile != NULL && pList != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,]\n",id,nombre,idTipo,power,resistencia);
		do{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,]\n",id,nombre,idTipo,power,resistencia);

			pComic = Comic_NewComic(id,nombre,idTipo,power,resistencia);

			ll_add(pList, pComic);
		}while(!feof(pFile));

		retorno = 0;
	}

	return retorno;
}

eComic* Comic_NewComic(char* id, char* nombre, char* idTipo, char* auxPower, char* auxResistencia){
	eComic* comic;
	eComic* auxComic;

	auxComic = (eComic*) malloc(sizeof(eComic));

	if(id != NULL && nombre != NULL && idTipo != NULL && auxPower != NULL && auxResistencia != NULL){
		comic = auxComic;

		Comic_setId(comic, atoi(id));
		Comic_setNombre(comic, nombre);
		Comic_setIdTipo(comic, atoi(idTipo));
		Comic_setPower(comic, atof(auxPower));
		Comic_setResistencia(comic, atof(auxResistencia));
	}

	return comic;
}

int Comic_setId(eComic* this, int id){
    int retorno = -1;

    if(this != NULL){
        this->id = id;
    }
    return retorno;
}

int Comic_setNombre(eComic* this, char* nombre){
    int retorno = -1;

    if(this != NULL){
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int Comic_setIdTipo(eComic* this, int idTipo){
    int retorno = -1;

    if(this != NULL){
        this->idTipo = idTipo;
    }
    return retorno;
}

int Comic_setPower(eComic* this, float power){
    int retorno = -1;

    if(this != NULL){
        this->power = power;
        retorno = 0;
    }
    return retorno;
}

int Comic_setResistencia(eComic* this, float resistencia){
    int retorno = -1;

    if(this != NULL){
        this->resistencia = resistencia;
        retorno = 0;
    }
    return retorno;
}

int Comic_getId(eComic* this, int* id){
    int retorno = -1;

    if(this != NULL){
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int Comic_getNombre(eComic* this, char* nombre){
    int retorno = -1;

    if(this != NULL){
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}

int Comic_getIdTipo(eComic* this, int* id){
    int retorno = -1;

    if(this != NULL){
        *id = this->idTipo;
        retorno = 0;
    }
    return retorno;
}

float Comic_getPower(eComic* this, float* power){
	float retorno = -1;

    if(this != NULL){
        *power = this->power;
        retorno = 0;
    }
    return retorno;
}

float Comic_getResistencia(eComic* this, float* resistencia){
	float retorno = -1;

    if(this != NULL){
        *resistencia = this->resistencia;
        retorno = 0;
    }
    return retorno;
}

int Comic_ComperByPower(void* pUno, void* pDos){
	int retorno = -2;
	int compara = 0;
	eComic* elemento1;
	eComic* elemento2;

	if(pUno != NULL && pDos != NULL){
		elemento1 = (eComic*) pUno;
		elemento2 = (eComic*) pDos;

		if(elemento1->power >  elemento2->power){
			compara = 1;
		}else{
			if(elemento1->power <  elemento2->power){
				compara = -1;
			}
		}
		retorno = compara;
	}

	return retorno;
}

int Comic_List(LinkedList* pList){
    int retorno = -1;

    int tam;
    int id;
    char nombre[50];
    int idTipo;
    float power;
    float resistencia;
    char tipo[50];

    eComic* pComic;

    if(pList != NULL){
        tam = ll_len(pList);


        printf("id, nombre, tipo, power, resistencia\n\n");
        for(int i = 0; i < tam; i++){
        	pComic = (eComic*) ll_get(pList, i);

            Comic_getId(pComic, &id);
            Comic_getNombre(pComic, nombre);
            Comic_getIdTipo(pComic, &idTipo);
            Comic_getPower(pComic, &power);
            Comic_getResistencia(pComic, &resistencia);

			Comic_CargarTipo(idTipo, tipo);

            printf("%04d, %15s, %15s, %10.2f, %10.2f\n", id, nombre, tipo , power, auxResistencia);
        }
        retorno = 0;
    }

    return retorno;
}

int Comic_CargarTipo(int id, char* tipo){
	int retorno = -1;

	if(id == 1){
		strcpy(tipo, "cadena");
		retorno = 0;
	}else{
		if(id == 2){
			strcpy(tipo, "cadena");
			retorno = 0;
        }else{
          	strcpy(tipo, " ");
			retorno = 0;
        }
    }

	return retorno;
}

int Comic_DescontarPower(void* this){
	int retorno = -1;

	float power;
	eComic* comic;

	if(this != NULL){
		comic = (eComic*) this;

		Comic_getPower(comic, &power);

		power = (80 * power) / 100;

		Comic_setPower(comic, power);
	}

	return retorno;
}

int Comic_GuardarComics(char* arch, LinkedList* pList){
	int retorno = -1;

	int len;
	int id;
	char nombre[50];
	int idTipo;
	float power;
	float resistencia;

	FILE* pFile;
	eComic* comic;

	if(arch != NULL){
		pFile = fopen(arch, "w");

		if(pFile != NULL){
			len = ll_len(pList);

			fprintf(pFile, "id,nombre,tipo,power,resistencia\n");
			for(int i = 0; i < len; i++){
				comic = (eComic*) ll_get(pList, i);

				Comic_getId(comic, &id);
				Comic_getNombre(comic, nombre);
				Comic_getIdTipo(comic, &idTipo);
				Comic_getPower(comic, &power);
				Comic_getResistencia(comic, &resistencia);

				fprintf(pFile, "%d,%s,%d,%f,%f\n", id,nombre,idTipo,power,resistencia);
			}
		}
		fclose(pFile);

		retorno = 0;
	}

	return retorno;
}
