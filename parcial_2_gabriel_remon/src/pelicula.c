#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/pelicula.h"
#include "../inc/utn.h"

ePelicula* pelicula_new()
{
    ePelicula* peliculaAux=NULL;

    peliculaAux=(ePelicula*) malloc(sizeof(ePelicula));

    return peliculaAux;
}

ePelicula* pelicula_newParametros(char* idStr,char* nombrePeliculaStr,char* generoStr,char* raitingStr)
{
    ePelicula* peliculaNuevo=NULL;
    peliculaNuevo=pelicula_new();

    if(peliculaNuevo!=NULL && idStr!=NULL && nombrePeliculaStr!=NULL && generoStr!=NULL && raitingStr!=NULL)
    {

        if(esNumerica(idStr))
        {
            pelicula_setId(peliculaNuevo,atoi(idStr));
        }

        pelicula_setNombrePelicula(peliculaNuevo,nombrePeliculaStr);
        pelicula_setGenero(peliculaNuevo,generoStr);

        pelicula_setRaiting(peliculaNuevo,atoi(raitingStr));

    }

    return peliculaNuevo;
}

void pelicula_delete(ePelicula* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

int pelicula_validarId(LinkedList* lista, int id)
{
    int retorno=-1;
    int idGuardada;
    int peliculaCantidad;
    ePelicula* pelicula;

    if(lista!=NULL)
    {
        peliculaCantidad=ll_len(lista);
        for(int i=0; i<peliculaCantidad; i++)
        {
            pelicula = (ePelicula*) ll_get(lista,i);
            if(pelicula!=NULL)
            {
                pelicula_getId(pelicula,&idGuardada);
                if(idGuardada==id)
                {
                    retorno=i;
                    break;
                }

            }
        }
    }

    return retorno;
}

int pelicula_setId(ePelicula* this,int id)
{
    int retorno=0;

    if(this!=NULL )
    {
        this->id=id;
        retorno=1;
    }

    return retorno;
}

int pelicula_getId(ePelicula* this,int* id)
{
    int retorno=0;

    if(this!=NULL && id!=NULL)
    {
        *id= this->id;
        retorno=1;
    }

    return retorno;
}

int pelicula_setNombrePelicula(ePelicula* this,char* nombrePelicula)
{
    int retorno=0;

    if(this!=NULL && nombrePelicula!=NULL )
    {
        strcpy(this->nombrePelicula,nombrePelicula);
        retorno=1;
    }

    return retorno;
}

int pelicula_getNombrePelicula(ePelicula* this,char* nombrePelicula)
{
    int retorno=0;

    if(this!=NULL && nombrePelicula!=NULL )
    {
        strcpy(nombrePelicula,this->nombrePelicula);
        retorno=1;
    }

    return retorno;
}

int pelicula_setGenero(ePelicula* this,char* genero)
{
    int retorno=0;

    if(this!=NULL && genero!=NULL )
    {
        strcpy(this->genero,genero);
        retorno=1;
    }

    return retorno;
}

int pelicula_getGenero(ePelicula* this,char* genero)
{
    int retorno=0;

    if(this!=NULL && genero!=NULL )
    {
        strcpy(genero,this->genero);
        retorno=1;
    }

    return retorno;
}

int pelicula_setRaiting(ePelicula* this,float raiting)
{
    int retorno=0;

    if(this!=NULL )
    {
        this->raiting=raiting;
        retorno=1;
    }

    return retorno;
}

int pelicula_getRaiting(ePelicula* this,float* raiting)
{
    int retorno=0;

    if(this!=NULL && raiting!=NULL)
    {
        *raiting=this->raiting;
        retorno=1;
    }

    return retorno;
}


void pelicula_printUno(ePelicula* this)
{
    int id;
    char nombrePelicula[128];
    char genero[128];
    float raiting;

    if(this !=NULL)
    {
        pelicula_getId(this,&id);
        pelicula_getNombrePelicula(this,nombrePelicula);
        pelicula_getGenero(this,genero);
        pelicula_getRaiting(this,&raiting);
        printf("ID: %d \nNombrePelicula: %s \nGenero: %s \nRaiting: $%.1f\n\n",
               id,
               nombrePelicula,
               genero,
               raiting
              );
    }
}

void pelicula_printColumna(ePelicula* this)
{
    int idAux;
    char nombrePeliculaAux[128];
    char generoAux[128];
    float raitingAux;

    if(this!=NULL)
    {
        pelicula_getId(this,&idAux);
        pelicula_getNombrePelicula(this,nombrePeliculaAux);
        pelicula_getGenero(this,generoAux);
        pelicula_getRaiting(this,&raitingAux);

        printf("%-6d    %-28s    %-15s     %-5.1f puntos\n",
               idAux,
               nombrePeliculaAux,
               generoAux,
               raitingAux
              );
    }
}

int pelicula_ingresoNombrePelicula(ePelicula* this)
{
    int retorno=0;
    char nombrePelicula[128];
    if(this!=NULL)
    {
        do
        {
            utn_ingresoScring(nombrePelicula,"Ingrese nombre: ", "error\n",64);
        }
        while(utn_validarNombre(nombrePelicula,128));

        pelicula_setNombrePelicula(this,nombrePelicula);
        retorno=1;
    }

    return retorno;
}

int pelicula_ingresoGenero(ePelicula* this)
{
    int retorno=0;
    char genero[128];
    if(this!=NULL)
    {
        do
        {
            utn_ingresoScring(genero,"Ingrese el genero de la pelicula: ", "error\n",128);
        }
        while(utn_validarNombre(genero,128));

        pelicula_setGenero(this,genero);
        retorno=1;
    }

    return retorno;
}


int pelicula_ingresoRaiting(ePelicula* this)
{
    int retorno=0;
    int raiting;

    if(this!=NULL)
    {
        utn_minMaxInt(&raiting,"Ingrese la duracion de la pelicula: ","Error ingrese un numero valido",1,400);
        pelicula_setRaiting(this,raiting);
        retorno=1;
    }

    return retorno;
}


int pelicula_ordenarId(void* primerParametro,void* segundoParametro)
{
    int retorno=0;
    ePelicula* pelicula1;
    ePelicula* pelicula2;
    int a;
    int b;

    if(primerParametro!=NULL && segundoParametro!=NULL)
    {
        pelicula1 = (ePelicula*) primerParametro;
        pelicula2 = (ePelicula*) segundoParametro;
        pelicula_getId(pelicula1,&a);
        pelicula_getId(pelicula2,&b);

        if(a>b)
        {
            retorno=1;
        }
        else
        {
            if(a<b)
            {
                retorno=-1;
            }
        }
    }
    return retorno;
}

int pelicula_ordenarNombrePelicula(void* primerParametro,void* segundoParametro)
{
    int retorno=0;
    ePelicula* pelicula1;
    ePelicula* pelicula2;
    char a[128];
    char b[128];

    if(primerParametro!=NULL && segundoParametro!=NULL)
    {
        pelicula1 = (ePelicula*) primerParametro;
        pelicula2 = (ePelicula*) segundoParametro;
        pelicula_getNombrePelicula(pelicula1,a);
        pelicula_getNombrePelicula(pelicula2,b);
        retorno=strncasecmp(a,b,128);
        if(retorno>0)
        {
            retorno=1;
        }
        else
        {
            if(retorno<0)
            {
                retorno=-1;
            }
        }
    }
    return retorno;
}

int pelicula_ordenarGenero(void* primerParametro,void* segundoParametro)
{
    int retorno=0;
    ePelicula* pelicula1;
    ePelicula* pelicula2;
    char a[128];
    char b[128];

    if(primerParametro!=NULL && segundoParametro!=NULL)
    {
        pelicula1 = (ePelicula*) primerParametro;
        pelicula2 = (ePelicula*) segundoParametro;
        pelicula_getGenero(pelicula1,a);
        pelicula_getGenero(pelicula2,b);
        retorno=strncasecmp(a,b,128);
        if(retorno>0)
        {
            retorno=1;
        }
        else
        {
            if(retorno<0)
            {
                retorno=-1;
            }
        }
    }
    return retorno;
}



int pelicula_ordenarRaiting(void* primerParametro,void* segundoParametro)
{
    int retorno=0;
    ePelicula* pelicula1;
    ePelicula* pelicula2;
    float a;
    float b;

    if(primerParametro!=NULL && segundoParametro!=NULL)
    {
        pelicula1 = (ePelicula*) primerParametro;
        pelicula2 = (ePelicula*) segundoParametro;
        pelicula_getRaiting(pelicula1,&a);
        pelicula_getRaiting(pelicula2,&b);
        if(a>b)
        {
            retorno=1;
        }
        else
        {
            if(a<b)
            {
                retorno=-1;
            }
        }
    }
    return retorno;
}

void* pelicula_generarRaiting(void* entrada)
{
    ePelicula* peliculaAux= (ePelicula*)entrada;
    int min=10;
    int max=100;
    float rating;

    if(peliculaAux!=NULL)
    {
        rating= (float)(rand() %(max-min+1) +min )/10;
        pelicula_setRaiting(peliculaAux,rating);
    }

    return peliculaAux;
}

void* pelicula_generarGenero(void* entrada)
{
    ePelicula* peliculaAux= (ePelicula*)entrada;
    int min=1;
    int max=4;
    int aux;

    if(peliculaAux!=NULL)
    {
        aux=rand() %(max-min+1) +min ;
        switch(aux)
        {
        case 1:
            pelicula_setGenero(peliculaAux,"drama");
            break;
        case 2:
            pelicula_setGenero(peliculaAux,"comedia");
            break;
        case 3:
            pelicula_setGenero(peliculaAux,"accion");
            break;
        case 4:
            pelicula_setGenero(peliculaAux,"terror");
            break;
        }
    }

    return peliculaAux;
}

int pelicula_ordenargeneroRaiting(void* parametro1,void* parametro2)
{
    int retorno=0;
    ePelicula* a= (ePelicula*)parametro1;
    ePelicula* b= (ePelicula*)parametro2;
    int parametroAux;

    if(a!=NULL && b !=NULL)
    {
        parametroAux=strcmp(a->genero,b->genero);
        if(parametroAux > 0 || ( parametroAux==0  &&(a->raiting > b->raiting)))
        {
            retorno=1;
        }
    }

    return retorno;
}

int pelicula_filtrarGeneroTerror(void* this)
{
    int retorno=0;
    ePelicula* peliculaAux=(ePelicula*)this;

    if(peliculaAux!=NULL)
    {
        if(strcmp(peliculaAux->genero,"terror")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int pelicula_filtrarGeneroComedia(void*this)
{
    int retorno=0;
    ePelicula* peliculaAux=(ePelicula*)this;

    if(peliculaAux!=NULL)
    {
        if(strcmp(peliculaAux->genero,"comedia")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int pelicula_filtrarGeneroAccion(void*this)
{
    int retorno=0;
    ePelicula* peliculaAux=(ePelicula*)this;

    if(peliculaAux!=NULL)
    {
        if(strcmp(peliculaAux->genero,"accion")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int pelicula_filtrarGeneroDrama(void*this)
{
    int retorno=0;
    ePelicula* peliculaAux=(ePelicula*)this;

    if(peliculaAux!=NULL)
    {
        if(strcmp(peliculaAux->genero,"drama")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

