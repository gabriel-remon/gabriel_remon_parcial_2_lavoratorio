#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/pelicula.h"
#define TAM_AUX 128

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListePelucla LinkedList*
 * \return int
 *
 */
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

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListePelucla LinkedList*
 * \return int
 *
 */
int parser_peliculaFromBinary(FILE* pFile, LinkedList* pArrayList)
{
    int retorno=0;
    int validacion;
    ePelicula* peliculaNueva;

    if(pFile!=NULL && pArrayList!=NULL)
    {
        do
        {
            peliculaNueva=pelicula_new();
            if(peliculaNueva!=NULL)
            {
                validacion=fread(peliculaNueva,sizeof(ePelicula),1,pFile);

                if(validacion==1)
                {
                    ll_add(pArrayList,peliculaNueva);
                }

            }

        }
        while(!feof(pFile));
    }

    return retorno;
}
