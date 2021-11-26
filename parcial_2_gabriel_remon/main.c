#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc/LinkedList.h"
#include "inc/utn.h"
#include "inc/pelicula.h"
#include "inc/parser.h"
#include "inc/Controller.h"
#include "time.h"
#define TAM 128


int main()
{
    srand(time(NULL));
    LinkedList* lista;
    char salir='N';
    char nombreArchivo[TAM];
    int flagGeneros=0;
    int flagRating=0;

    lista=ll_newLinkedList();
    if(lista==NULL)
    {
        printf("No hay espacio en memoria para iniciar el programa\n\n");
        exit(1);
    }
    do
    {
        switch(menu())
        {
        case 1:
            utn_ingresoScring(nombreArchivo,"Ingrese el nombre del archivo (sin el .csv): ","Error\n",TAM);
            if(controller_loadFromText(nombreArchivo,lista))
            {
                flagGeneros=0;
                flagRating=0;
            }
            break;

        case 2:
            controller_peliculaList(lista);
            break;

        case 3:
            controller_asignarRaiting(lista);
            flagRating=1;
            break;

        case 4:
            controller_asignarGenero(lista);
            flagGeneros=1;
            break;

        case 5:
            if(flagGeneros)
            {
                controller_filtrarGenero(lista);
            }
            else
            {
                printf("Primero genere los generos");
            }
            break;

        case 6:
            if(flagGeneros && flagRating)
            {
                controller_ordenarpeliculas(lista);
            }
            else
            {
                printf("primero genere los ratings y los generos");
            }
            break;

        case 7:
            utn_ingresoScring(nombreArchivo,"Ingrese el nombre como se guardara el archivo (sin el .csv)","Error\n",TAM);
            controller_saveAsText(nombreArchivo,lista);
            break;

        case 8:
            utn_confirmar(&salir,"Esta seguro que desea salir?(Y/N)","Error ingrese (Y/N)",'Y','N');
            break;

        }

        utn_stop();
        utn_clear();
    }
    while(salir=='N');

    controller_exit(lista);
    ll_deleteLinkedList(lista);

    return 0;
}




























