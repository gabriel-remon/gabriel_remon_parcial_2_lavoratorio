#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Controller.h"
#include "../inc/LinkedList.h"
#include "../inc/pelicula.h"
#include "../inc/parser.h"
#include "../inc/utn.h"


int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    int retorno=0;
    FILE* archivo;
    char vacio[128];
    char nombreArchivo[128];
    if(path!=NULL && pArrayList!=NULL)
    {
        controller_exit(pArrayList);
        strcat(nombreArchivo,path);
        strcat(nombreArchivo,".csv");
        archivo=fopen(nombreArchivo,"r");
        utn_clear();

        if(archivo!=NULL)
        {
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",vacio,vacio,vacio,vacio);
            parser_peliculaFromText(archivo,pArrayList);

            retorno=1;
            printf("archivo cargado con exito");
            fclose(archivo);
        }
        else
        {
            printf("Archivo no encontrado");
        }

    }
    return retorno;

}

int controller_peliculaList(LinkedList* pArrayList)
{
    int retorno=-1;
    int peliculaCantidad;
    ePelicula* pelicula;


    if(pArrayList!=NULL )
    {
        if(!ll_isEmpty(pArrayList))
        {
            peliculaCantidad=ll_len(pArrayList);
            printf("id        Nombre de la pelicula           genero              Rating\n\n");
            for(int i=0; i<peliculaCantidad; i++)
            {
                pelicula=(ePelicula*) ll_get(pArrayList,i);
                pelicula_printFila(pelicula);
            }
        }
        else
        {
            printf("La lista esta vacia");
        }
    }


    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    int retorno=-1;
    char nombreArchivo[128]= {};
    int peliculaCantidad;
    ePelicula* pelicula;
    FILE* archivo;

    int idAux;
    char nombrePeliculaAux[128];
    char generoAux[128];
    float raitingAux;

    char comfirmar;

    if(path!=NULL && !ll_isEmpty(pArrayList))
    {
        strcat(nombreArchivo,path);
        strcat(nombreArchivo,".csv");

        archivo=fopen(nombreArchivo,"r");
        utn_clear();

        if(archivo==NULL)
        {
            goto guardar;
        }
        else
        {
            fclose(archivo);
            utn_confirmar(&comfirmar,"\nSe encontro un archivo con ese nombre. Desea sobre escrivirlo? (Y/N): ","Error ingrese 'Y' o 'N'",'Y','N');
            if(comfirmar=='Y')
            {
guardar:
                archivo=fopen(nombreArchivo,"w");
                fprintf(archivo,"id_peli,titulo,genero,rating\n");
                peliculaCantidad=ll_len(pArrayList);
                for(int i=0; i<peliculaCantidad; i++)
                {
                    pelicula=(ePelicula*) ll_get(pArrayList,i);
                    if(pelicula!=NULL)
                    {
                        pelicula_getId(pelicula,&idAux);
                        pelicula_getNombrePelicula(pelicula,nombrePeliculaAux);
                        pelicula_getGenero(pelicula,generoAux);
                        pelicula_getRaiting(pelicula,&raitingAux);

                        fprintf(archivo,"%d,%s,%s,%.1f\n",
                                idAux,
                                nombrePeliculaAux,
                                generoAux,
                                raitingAux
                               );
                    }
                }
                printf("Archivo guardado con exito\n");
                fclose(archivo);
            }
        }

    }
    else
    {
        printf("Primero deve de dar de alta un empleado");
    }

    return retorno;
}

void controller_exit(LinkedList* pArrayList)
{
    int peliculaCantidad;
    ePelicula* pelicula;

    if(pArrayList!=NULL)
    {
        peliculaCantidad=ll_len(pArrayList);
        for(int i=0; i<peliculaCantidad; i++)
        {
            pelicula=(ePelicula*) ll_get(pArrayList,i);
            if(pelicula!=NULL)
            {
                pelicula_delete(pelicula);
            }
        }
        ll_clear(pArrayList);
    }

}

int menu()
{
    int retorno;

    printf("-----------------registro de pelicula---------------\n\n");

    printf("1- CARGAR ARCHIVO      \n");
    printf("2- IMPRIMIR LISTA      \n");
    printf("3- ASIGNAR RAITING     \n");
    printf("4- ASIGNAR GENERO      \n");
    printf("5- FILTRAR POR GENERO  \n");
    printf("6- ORDENAR PELICULAS   \n");
    printf("7-GUARDAR PELICULAS  \n\n");

    printf("8-SALIR              \n\n");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 8",1,8);
    utn_clear();
    return retorno;
}

int controller_asignarRaiting(LinkedList* this)
{
    int retorno=0;
    LinkedList* listaAux;

    if(!ll_isEmpty(this))
    {
        listaAux=ll_newLinkedList();
        if(listaAux!=NULL)
        {
            listaAux=ll_map(this,pelicula_generarRaiting);
            ll_deleteLinkedList(listaAux);
            printf("Raiting asignados con exito");
            retorno=1;
        }
    }
    else
    {
        printf("La lista esta vacia, cargue un archivo");
    }

    return retorno;
}

int controller_asignarGenero(LinkedList* this)
{
    int retorno=0;
    LinkedList* listaAux;

    if(this!=NULL)
    {
        listaAux=ll_newLinkedList();
        if(listaAux!=NULL)
        {
            listaAux=ll_map(this,pelicula_generarGenero);
            ll_deleteLinkedList(listaAux);
            printf("Generos asignados con exito");
            retorno=1;
        }
    }

    return retorno;

}

int controller_ordenarpeliculas(LinkedList* this)
{
    int retorno=0;

    if(this!=NULL)
    {
        ll_sort(this,pelicula_ordenargeneroRaiting,1);
        controller_peliculaList(this);
        retorno=1;
    }

    return retorno;
}


int controller_filtrarGenero(LinkedList* this)
{
    int retorno=0;
    LinkedList* listaAux;
    char nombreArchivo[128];

    if(this!=NULL)
    {
        switch(menuGenero())
        {
        case 1:
            listaAux=ll_filter(this,pelicula_filtrarGeneroDrama);
            break;

        case 2:
            listaAux=ll_filter(this,pelicula_filtrarGeneroComedia);
            break;

        case 3:
            listaAux=ll_filter(this,pelicula_filtrarGeneroAccion);
            break;

        case 4:
            listaAux=ll_filter(this,pelicula_filtrarGeneroTerror);
            break;
        }

        if(!ll_isEmpty(listaAux))
        {
            utn_ingresoScring(nombreArchivo,"Ingrese el nombre como se guardara el archivo (sin el .csv): ","Error\n",128);
            controller_saveAsText(nombreArchivo,listaAux);
        }
        else
        {
            printf("No se encontraron datos del tipo seleccionado\n");
        }
        ll_deleteLinkedList(listaAux);
        retorno=1;
    }

    return retorno;
}

int menuGenero()
{
    int retorno;

    printf("-----------------FILTRAR POR GENERO---------------\n\n");

    printf("1- FILTRAR POR DRAMA       \n");
    printf("2- FILTRAR POR COMEDIA     \n");
    printf("3- FILTRAR POR ACCION      \n");
    printf("4- FILTRAR POR TERROR      \n");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 4",1,4);
    utn_clear();
    return retorno;
}

