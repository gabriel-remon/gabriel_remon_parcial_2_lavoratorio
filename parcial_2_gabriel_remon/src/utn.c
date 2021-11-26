/*
 *      Author: Gabriel Remon
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "../inc/utn.h"


static int getItn(int* pResultado);
// int esNumerica(char bufferIn[]);
static int myGets(char bufferIn[], int tam);

static int getItn(int* pResultado)
{
    int retorno=0;
    char bufferIn[4026];

    if(pResultado!=NULL)
    {
        if(myGets(bufferIn, sizeof(bufferIn))&&esNumerica(bufferIn))
        {
            retorno=1;
            *pResultado=atoi(bufferIn);
        }
    }

    return retorno;
}

int esNumerica(char bufferIn[])
{
    int retorno=1;
    int i=0;

    if(bufferIn!=NULL)
    {
        if(bufferIn[0]=='-')
        {
            i=1;
        }
        for(; bufferIn[i]!='\0'; i++)
        {
            if(bufferIn[i]<'0'|| bufferIn[i]>'9')
            {
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}

static int myGets(char bufferIn[], int tam)
{
    int retorno=0;

    if(bufferIn!=NULL && tam>0)
    {
        __fpurge(stdin);
        fgets(bufferIn, tam, stdin);

        bufferIn[strlen(bufferIn)-1]='\0';
        retorno=1;
    }

    return retorno;
}


int utn_minMaxInt(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo)
{
    int retorno = -1;
    int bufferIn;
    int error;

    if(pResultado != NULL && pMensaje!= NULL && pMensajeError!= NULL && minimo<maximo)
    {
        while(1)
        {
            printf("%s ", pMensaje);
            error = getItn(&bufferIn);
            if(bufferIn>=minimo && bufferIn<=maximo && error == 1)
            {
                *pResultado = bufferIn;
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s ", pMensajeError);
            }
        }
    }
    return retorno;
}

int utn_minMaxFloat(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo)
{
    int retorno = -1;
    float bufferIn;
    int error;

    if(pResultado != NULL && pMensaje!= NULL && pMensajeError!= NULL && minimo<maximo)
    {
        while(1)
        {
            printf("%s ", pMensaje);
            __fpurge(stdin);
            error = scanf("%f", &bufferIn);
            if(bufferIn>=minimo && bufferIn<=maximo && error == 1)
            {
                *pResultado = bufferIn;
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s ", pMensajeError);
            }
        }
    }
    return retorno;
}

int utn_getCharDos(char* pResultado, char* pMensaje, char* pMensajeError, char criterio1, char criterio2)
{
    int retorno = -1;
    char bufferIn;
    int error;

    if(pResultado != NULL && pMensaje!= NULL && pMensajeError!= NULL)
    {
        do
        {
            printf("%s ", pMensaje);
            __fpurge(stdin);
            error = scanf("%c", &bufferIn);
            if(error == 1 && (bufferIn == criterio1 ||bufferIn == criterio2))
            {
                *pResultado = bufferIn;
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s ", pMensajeError);
            }
        }
        while(1);
    }
    return retorno;
}



int utn_getInt(int* pResultado, char* pMensaje, char* pMensajeError)
{
    int retorno = -1;
    int bufferIn;
    int error;

    if(pResultado != NULL && pMensaje!= NULL && pMensajeError!= NULL)
    {
        do
        {
            printf("%s ", pMensaje);
            error = getItn(&bufferIn);
            if(error == 1)
            {
                *pResultado = bufferIn;
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s ", pMensajeError);
            }
        }
        while(1);
    }
    return retorno;
}


int utn_getFloat(float* pResultado, char* pMensaje, char* pMensajeError)
{
    int retorno = -1;
    float bufferIn;
    int error;

    if(pResultado != NULL && pMensaje!= NULL && pMensajeError!= NULL)
    {
        do
        {
            printf("%s ", pMensaje);
            __fpurge(stdin);
            error = scanf("%f", &bufferIn);
            if(error == 1)
            {
                *pResultado = bufferIn;
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s ", pMensajeError);
            }
        }
        while(1);
    }
    return retorno;
}

int utn_getChar(char* pResultado, char* pMensaje, char* pMensajeError)
{
    int retorno = -1;
    char bufferIn;
    int error;

    if(pResultado != NULL && pMensaje!= NULL && pMensajeError!= NULL)
    {
        do
        {
            printf("%s ", pMensaje);
            __fpurge(stdin);
            error = scanf("%c", &bufferIn);
            if(error == 1)
            {
                *pResultado = bufferIn;
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s ", pMensajeError);
            }
        }
        while(1);
    }
    return retorno;
}

void utn_clear()
{
    system("@cls||clear");
}

void utn_stop()
{
    printf("\n\nPrecione Enter para continuar");
    __fpurge(stdin);
    getchar();
}

int utn_ingresoScring(char cadena[],char* pMensaje, char*pMensajeError, int tamPermitido)
{
    int retorno = -1;
    char bufferIn[1000];
    int error;

    if(cadena != NULL && pMensaje!= NULL && pMensajeError!= NULL && tamPermitido<=sizeof(bufferIn) && tamPermitido>0)
    {
        do
        {
            printf("%s ", pMensaje);
            error = myGets(bufferIn, sizeof(bufferIn));

            if(error == 1 && strlen(bufferIn)<=tamPermitido )
            {
                strcpy(cadena, bufferIn);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s ", pMensajeError);
            }
        }
        while(1);
    }
    return retorno;
}

int esPalabra(char vec[], int tam)
{
    int retorno=1;
    //int flagLetra=1;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; (i<tam && (vec[i])!='\0'); i++)
        {
            if((((vec[i])>='A' && (vec[i])<='Z') || ((vec[i])>='a' && (vec[i])<='z') ))
            {
                //  printf("\nIngrese solo letras\n");
                retorno=0;
                break;
            }

        }

    }

    return retorno;
}

int esNumero(char vec[], int tam)
{
    int retorno=1;


    if(vec!=NULL && tam>0)
    {
        for(int i=0; (i<tam && (vec[i])!='\0'); i++)
        {
            if(vec[i]<'0'|| vec[i]>'9')
            {
                //printf("\nIngrese solo numeros\n");
                retorno=0;
                break;
            }
        }

    }

    return retorno;
}

int utn_confirmar(char* pResultado, char* pMensaje, char* pMensajeError, char criterio1, char criterio2)
{
    int retorno = -1;
    char bufferIn;
    int error;

    if(pResultado != NULL && pMensaje!= NULL && pMensajeError!= NULL)
    {
        do
        {
            printf("%s ", pMensaje);
            __fpurge(stdin);
            error = scanf("%c", &bufferIn);
            bufferIn=toupper(bufferIn);
            criterio1= toupper(criterio1);
            criterio2= toupper(criterio2);
            if(error == 1 && (bufferIn == criterio1 ||bufferIn == criterio2))
            {
                *pResultado = bufferIn;
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s ", pMensajeError);
            }
        }
        while(1);
    }
    return retorno;
}

int utn_ordenarFloat(float vec[], int tam, int criterio)
{
    int retorno=-1;
    if(vec!=NULL && tam>0 && (criterio ==1 || criterio ==0))
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j< tam; j++ )
            {
                if((vec[i] > vec[j] && criterio) || (vec[i] < vec[j] && !criterio))
                {
                    utn_swapFloat(&vec[i], &vec[j]);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int utn_swapFloat(float* num1, float* num2)
{
    int retorno=-1;
    float aux;
    if(num1!=NULL && num2!=NULL)
    {
        aux=*num1;
        *num1=*num2;
        *num2=aux;
        retorno=0;
    }
    return retorno;
}

int utn_validarNombre(char vec[],int tam)
{
    int retorno=1;
    int flagLetra=1;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; (i<tam && (vec[i])!='\0'); i++)
        {
            if(!((vec[i])>='A' && (vec[i])<='Z') && !((vec[i])>='a' && (vec[i])<='z') && !(vec[i]==32) )
            {
                printf("Ingrese solo letras\n");
                flagLetra=0;
                break;
            }
            if(vec[i]>='A' && vec[i]<='Z')
            {
                vec[i]=vec[i]+32;
            }
        }
        if(flagLetra)
        {
            if(vec[0]>='a' && vec[0]<='z')
            {
                vec[0]=vec[0]-32;
            }
            retorno=0;
        }
    }

    return retorno;
}
