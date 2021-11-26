#include "LinkedList.h"

#ifndef epelicula_H_INCLUDED
#define epelicula_H_INCLUDED
typedef struct
{
    int id;
    char nombrePelicula[128];
    char genero[128];
    float raiting;
} ePelicula;


#endif // epelicula_H_INCLUDED

/** \brief reserva espacio en memoria para una estructura "ePelicula"
 *
 * \return ePelicula*
 *
 */
ePelicula* pelicula_new();

/** \brief genera una estructura "ePelicula" con los valores pasados por parametro
 *
 * \param idStr char*
 * \param nombrePeliculaStr char*
 * \param generoStr char*
 * \param raitingStr char*
 * \return ePelicula*
 *
 */
ePelicula* pelicula_newParametros(char* idStr,char* nombrePeliculaStr,char* generoStr,char* raitingStr);

/** \brief libera el espacio en memoria de puntero pasado por parametro
 *
 * \param this ePelicula*
 *
 */
void pelicula_delete(ePelicula* this);

/** \brief imprimer una sola estructura en forma de columna
 *
 * \param this ePelicula*
 *
 */
void pelicula_printUno(ePelicula* this);

/** \brief imprimer una sola estructura en forma de fila
 *
 * \param this ePelicula*
 *
 */
void pelicula_printFila(ePelicula* this);

/** \brief valida que el id pasado por parametro exista en la lista
 *
 * \param id int*
 * \param lista LinkedList*
 * \return int devuelve -1 si huevo error o si no esta-
 *                      la posicion donde esta si lo encuentra
 *
 */
int pelicula_validarId(LinkedList* lista, int id);

/** \brief carga dentro de la estructura el valor pasado como parametro
 *
 * \param id int
 * \param lista LinkedList*
 * \return int devuelve 0 si fillo - 1 si todo ok
 *
 */
int pelicula_setId(ePelicula* this,int id);

/** \brief lee el valor dentro de la estructura y lo devuelve
 *
 * \param id int*
 * \param lista LinkedList*
 * \return int devuelve 0 si fillo - 1 si todo ok
 *
 */
int pelicula_getId(ePelicula* this,int* id);

/** \brief carga dentro de la estructura el valor pasado como parametro
 *
 * \param nombrePelicula char*
 * \param lista LinkedList*
 * \return int devuelve 0 si fillo - 1 si todo ok
 *
 */
int pelicula_setNombrePelicula(ePelicula* this,char* nombrePelicula);

/** \brief lee el valor dentro de la estructura y lo devuelve
 *
 * \param nombrePelicula char*
 * \param lista LinkedList*
 * \return int devuelve 0 si fillo - 1 si todo ok
 *
 */
int pelicula_getNombrePelicula(ePelicula* this,char* nombrePelicula);

/** \brief carga dentro de la estructura el valor pasado como parametro
 *
 * \param genero char*
 * \param lista LinkedList*
 * \return int devuelve 0 si fillo - 1 si todo ok
 *
 */
int pelicula_setGenero(ePelicula* this,char* genero);

/** \brief lee el valor dentro de la estructura y lo devuelve
 *
 * \param genero char*
 * \param lista LinkedList*
 * \return int devuelve 0 si fillo - 1 si todo ok
 *
 */
int pelicula_getGenero(ePelicula* this,char* genero);

/** \brief carga dentro de la estructura el valor pasado como parametro
 *
 * \param raiting float
 * \param lista LinkedList*
 * \return int devuelve 0 si fillo - 1 si todo ok
 *
 */
int pelicula_setRaiting(ePelicula* this,float raiting);

/** \brief lee el valor dentro de la estructura y lo devuelve
 *
 * \param raiting float*
 * \param lista LinkedList*
 * \return int devuelve 0 si fillo - 1 si todo ok
 *
 */
int pelicula_getRaiting(ePelicula* this,float* raiting);

/** \brief carga dentro de la estructura un valor aleatorio float del 1 al 10
 *
 * \param void*
 * \return void* la estructura modificada
 *
 */
void* pelicula_generarRaiting(void*);

/** \brief carga dentro de la estructura un genero aleatorio
 *
 * \param void*
 * \return void* la estructura modificada
 *
 */
void* pelicula_generarGenero(void* entrada);

int pelicula_filtrarGeneroDrama(void*);
int pelicula_filtrarGeneroComedia(void*);
int pelicula_filtrarGeneroAccion(void*);
int pelicula_filtrarGeneroTerror(void*);

int pelicula_ordenargeneroRaiting(void*,void*);

