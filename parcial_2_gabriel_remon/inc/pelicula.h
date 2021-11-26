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
ePelicula* pelicula_new();

ePelicula* pelicula_newParametros(char* idStr,char* nombrePeliculaStr,char* generoStr,char* raitingStr);//char* raiting2Str ,char* raiting3Str)
void pelicula_delete(ePelicula* this);
void pelicula_printUno(ePelicula* this);
void pelicula_printColumna(ePelicula* this);

int pelicula_validarId(LinkedList* lista, int id);
int pelicula_setId(ePelicula* this,int id);
int pelicula_getId(ePelicula* this,int* id);
///////////////////////////////////////////
int pelicula_setNombrePelicula(ePelicula* this,char* nombrePelicula);
int pelicula_getNombrePelicula(ePelicula* this,char* nombrePelicula);
int pelicula_ingresoNombrePelicula(ePelicula* this);
////////////////////////////////////////////
int pelicula_setGenero(ePelicula* this,char* genero);
int pelicula_getGenero(ePelicula* this,char* genero);
int pelicula_ingresoGenero(ePelicula* this);
////////////////////////////////////////////
int pelicula_setRaiting(ePelicula* this,float raiting);
int pelicula_getRaiting(ePelicula* this,float* raiting);
int pelicula_ingresoRaiting(ePelicula* this);
//////////////////////////////////////////////

int pelicula_ordenarId(void* primerParametro,void* segundoParametro);
int pelicula_ordenarNombrePelicula(void* primerParametro,void* segundoParametro);
int pelicula_ordenarGenero(void* primerParametro,void* segundoParametro);
int pelicula_ordenarRaiting(void* primerParametro,void* segundoParametro);

void* pelicula_generarRaiting(void*);
void* pelicula_generarGenero(void* entrada);

int pelicula_filtrarGeneroDrama(void*);
int pelicula_filtrarGeneroComedia(void*);
int pelicula_filtrarGeneroAccion(void*);
int pelicula_filtrarGeneroTerror(void*);

int pelicula_ordenargeneroRaiting(void*,void*);

