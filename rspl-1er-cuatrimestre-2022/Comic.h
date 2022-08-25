/*
 * Comic.h
 *
 *  Created on: Aug 11, 2022
 *      Author: Alex Yago Fedczuk
 */
#ifndef COMIC_H_
#define COMIC_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct{
	int id;
	char nombre[50];
	int idTipo;
	float power;
	float resistencia;
}eComic;

/** \brief Se encarga de cargar en la lista las entidades guardadas en el archivo.
 *
 * \param FILE* pFile, el puntero con la direccion de memori del archivo.
 * \param LinkedList* pList, el puntero con la "linked list".
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Comic_CargarArchivo(FILE* pFile, LinkedList* pList);

/** \brief Se encarga de cargar a la lista las entidades de un archivo.
 *
 * \param char* id,
 * \param char* nombre,
 * \param char* idTipo,
 * \param char* auxPower,
 * \param char* auxResistencia,
 * \return Devuelve (NULL) si hubo un parametro invalido - Un puntero con la entidad con sus datos cargados si Ok.
 *
 */
eComic* Comic_NewComic(char* id, char* nombre, char* idTipo, char* auxPower, char* auxResistencia);

/** \brief Se encarga de "setear" el ID.
 *
 * \param this, la direccion de memoriaal elemento.
 * \param int id, el ID del elemento.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Comic_setId(eComic* this, int id);

/** \brief Se encarga de "setear" el Nombre.
 *
 * \param this, la direccion de memoria elemento.
 * \param int Nombre, el Nombre del elemento.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Comic_setNombre(eComic* this, char* nombre);

/** \brief Se encarga de "setear" el ID TIPO.
 *
 * \param this, la direccion de memoria elemento.
 * \param int ID TIPO, el ID TIPO del elemento.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Comic_setIdTipo(eComic* this, int idTipo);

/** \brief Se encarga de "setear" el POWER
 *
 * \param this, la direccion de memoria elemento.
 * \param int POWER, el POWER del elemento.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Comic_setPower(eComic* this, float power);

/** \brief Se encarga de "setear" el RESISTENCIA.
 *
 * \param this, la direccion de memoria elemento.
 * \param int RESISTENCIA, el RESISTENCIA del elemento.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Comic_setResistencia(eComic* this, float resistencia);

/** \brief Compara entre dos elementos un valor en comun y de eso devuelve un valor, como resultado.
 *
 * \param void* pUno, la direccion de memoria un elemento.
 * \param void* pDos, la direccion de memoria un elemento.
 * \return Devuelve (-2) si hubo un parametro invalido - (1) o (-1) si Ok.
 *
 */
int Comic_ComperByPower(void* pUno, void* pDos);

/** \brief Genera un listado con los datos de las entidades.
 *
 * \param LinkedList* pList, el puntero con la "linked list".
 * \return Devuelve (-1) si hubo un parametro invalido - (0) si Ok.
 *
 */
int Comic_List(LinkedList* pList);

/** \brief Setea una variable tipo string axuliar.
 *
 * \param int id,
 * \param char* tipo, la variable a ser seteada.
 * \return Devuelve (-1) si hubo un parametro invalido - (0) si Ok.
 *
 */
int Comic_CargarTipo(int id, char* tipo);

/** \brief Descuenta el valor de un dato guardado en un elemnto.
 *
 * \param void* this, la direccion de memoria un elemento.
 * \return Devuelve (-1) si hubo un parametro invalido - (0) si Ok.
 *
 */
int Comic_DescontarPower(void* this);

/** \brief Genera un nuevo archivo guardando en el mismo los datos que se encuentran en la linked list.
 *
 * \param char* arch, el nombre del nuevo archivo a generar.
 * \param LinkedList* pList, el puntero con la "linked list".
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Comic_GuardarComics(char* arch, LinkedList* pList);

#endif /* COMIC_H_ */
