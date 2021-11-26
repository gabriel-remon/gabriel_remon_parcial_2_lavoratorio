#include "LinkedList.h"

#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED

#endif
/** \brief Carga los datos de los peliculas desde el archivo data.csv (modo texto).
 *         (saltea la primera linea de valores del archivo)
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListpelicula);

/** \brief Guarda los datos de los peliculas en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListpelicula);

/** \brief Listar peliculas
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_peliculaList(LinkedList* pArrayListpelicula);

/** \brief Libera el espacio de memoria de todos los elementos de la lista y todos sus elementos menos el puntero de inicio
 *
 * \param pArrayList LinkedList*
 *
 */
void controller_exit(LinkedList* pArrayListpelicula);
/** \brief Menu de entrad del programa
 *
 */
int menu();

/** \brief Agrega todos los raitings a la lista
 *
 * \param pArrayList LinkedList*
 * \return int 0 si falla- 1 si todo ok
 *
 */
int controller_asignarRaiting(LinkedList*);

/** \brief Agrega todos los generos a la lista
 *
 * \param pArrayList LinkedList*
 * \return int int 0 si falla- 1 si todo ok
 *
 */
int controller_asignarGenero(LinkedList*);

/** \brief Ordena la lista por Genero y luego por Raiting
 *
 * \param pArrayList LinkedList*
 * \return int int 0 si falla- 1 si todo ok
 *
 */
int controller_ordenarpeliculas(LinkedList*);

/** \brief Filtra la lista por genero seleccionado y guarda en archivo dado por el usuario
 *
 * \param pArrayList LinkedList*
 * \return int int 0 si falla- 1 si todo ok
 *
 */
int controller_filtrarGenero(LinkedList*);

/** \brief Menu de la funcion "controller_filtrarGenero"
 *
 */
int menuGenero();


