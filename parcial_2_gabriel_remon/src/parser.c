#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/pelicula.h"
#define TAM_AUX 128

int parser_peliculaFromText(FILE* pFile, LinkedList* pArrayList)
{
    int retorno=0;
    char idTxt[TAM_AUX];
    char nombrePeliculaTxt[TAM_AUX];
    char generoTxt[TAM_AUX];
    char raitingTxt[TAM_AUX];
    int validacion;
    ePelicula* peliculaNueva;

    if(pFile!=NULL && pArrayList!=NULL)
    {
        do
        {
            validacion=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                              idTxt,
                              nombrePeliculaTxt,
                              generoTxt,
                              raitingTxt
                             );
            if(validacion==4)
            {
                peliculaNueva=pelicula_newParametros(idTxt,nombrePeliculaTxt,generoTxt,raitingTxt);
                if(peliculaNueva!=NULL)
                {
                    ll_add(pArrayList,peliculaNueva);
                    retorno++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }

        }
        while(!feof(pFile));

    }

    return retorno;
}


