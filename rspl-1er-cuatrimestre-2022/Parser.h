/*
 * Parser.h
 *
 *  Created on: Apr 25, 2022
 *      Author: Alex Yago Fedczuk
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Llama una funcion que Parsea los datos de un archivo de forma texto.
 * \param pFile FILE*, La direccion de memoria del archivo.
 * \param pList LinkedList*, la direccion de memoria de la linked list.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int parser_FromText(FILE* pFile, LinkedList* pList);

/** \brief LLama una funcion que pasa los datos de una linked list a un archivo modo texto.
 * \param pList LinkedList*, la direccion de memoria de la linked list.
 * \param arch char*, El nombre del archivo.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int parser_ToText(LinkedList* pList, char* arch);

#endif /* PARSER_H_ */
