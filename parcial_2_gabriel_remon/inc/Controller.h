#include "LinkedList.h"

#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED

#endif

int controller_loadFromText(char* path, LinkedList* pArrayListpelicula);
int controller_loadFromBinary(char* path, LinkedList* pArrayListpelicula);

int controller_saveAsText(char* path, LinkedList* pArrayListpelicula);
int controller_saveAsBinary(char* path, LinkedList* pArrayListpelicula);

int controller_peliculaList(LinkedList* pArrayListpelicula);
void controller_exit(LinkedList* pArrayListpelicula);
int menu();

int controller_asignarRaiting(LinkedList*);
int controller_asignarGenero(LinkedList*);

int controller_ordenarpeliculas(LinkedList*);
int controller_filtrarGenero(LinkedList*);
int menuGenero();


