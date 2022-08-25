/*
 * Controller.h
 *
 *  Created on: Apr 25, 2022
 *      Author: Alex Yago Fedczuk
 */
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief Carga los datos de las entidades en tema, desde el archivo .csv (modo texto).
 *
 * \param path char*, La direccion de memoria donde se encuentra el nombre del archivo.
 * \param pLista LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Controller_CargaDeArchivo(char* arch, LinkedList* pLista);

/** \brief Ordena (con una funcion criterio) la lista de entidades.
 * \param pLista LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \param bandera int, bandera como criterio si se puede ejecutar este controlador o no.
 * \param pFunc int, La direccion de memoria donde se encuentra la Funcion como criterio.
 * \param order int, El valor de criterio del orden.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Controller_Ordenar(LinkedList* pLista, int bandera, int (*pFunc)(void*), int order);

/** \brief Realiza una lista con las entidades en tema.
 * \param pLista LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \param bandera int, bandera como criterio si se puede ejecutar este controlador o no.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Controller_Listar(LinkedList* pLista, int bandera);


/** \brief Modifica (con una funcion modificadora) la lista de entidades.
 * \param pLista LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \param bandera int, bandera como criterio si se puede ejecutar este controlador o no.
 * \param pFuncUno int, La direccion de memoria donde se encuentra la Funcion que manipula la Linked List.
 * \param pFuncDos int, La direccion de memoria donde se encuentra la Funcion como modificadora.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Controller_Modificar(LinkedList* pLista, int bandera, int (*pFuncUno), int (*pFuncDos));

/** \brief Guarda los datos de las entidades de la linked list en un archivo.
 *
 * \param path char*, La direccion de memoria donde se encuentra el nombre del archivo.
 * \param pLista LinkedList*, La direccion de memoria donde se encuentra la lista.
 * \param bandera int, bandera como criterio si se puede ejecutar este controlador o no.
 * \return Devuelve (-1) si hubo un parametro invalido - 0 si Ok.
 *
 */
int Controller_Guardar(char* arch, LinkedList* pLista, int bandera);

#endif /* CONTROLLER_H_ */
