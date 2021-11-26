/*
 *      Author: Gabriel Remon
 */

#ifndef UTN_H_
#define UTN_H_


int utn_minMaxInt(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo);
/** @brief pide un numero entero al usuario y lo valida entre un parametro minimo y maximo. Reintenta hasta conseguir un numero valido
*   @param pResultado int* guarda el numero validado en la pocision del puntero
*   @param pMensaje char* imprime al usuario por string el valor en ese puntero
*   @param pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
*   @param minimo int
*   @param maximo int
*
*   @return int return (-1) si huvo un error - (0) si ok
*/

int utn_minMaxFloat(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo);
/** @brief pide un numero flotante al usuario y lo valida entre un parametro minimo y maximo. Reintenta hasta conseguir un numero valido
*   @param pResultado float* guarda el numero validado en la pocision del puntero
*   @param pMensaje char* imprime al usuario por string el valor en ese puntero
*   @param pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
*   @param minimo int
*   @param maximo int
*
*   @return int return (-1) si huvo un error - (0) si ok
*/

int utn_getCharDos(char* pResultado, char* pMensaje, char* pMensajeError, char criterio1, char criterio2);
/** @brief pide un caracter al usuario y lo valida entre dos caracteres asignados. Reintenta hasta conseguir un caracter valido
*   @param pResultado char* guarda el caracter validado en la pocision del puntero
*   @param pMensaje char* imprime al usuario por string el valor en ese puntero
*   @param pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
*   @param minimo char 1º caracter permitido
*   @param maximo char 2º caracter permitido
*
*   @return int return (-1) si huvo un error - (0) si ok
*/

int utn_getInt(int* pResultado, char* pMensaje, char* pMensajeError);
/** @brief pide un numero entero al usuario y lo valida. Reintenta hasta conseguir un numero valido
*   @param pResultado int* guarda el numero validado en la pocision del puntero
*   @param pMensaje char* imprime al usuario por string el valor en ese puntero
*   @param pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
*
*   @return int return (-1) si huvo un error - (0) si ok
*/

int utn_getFloat(float* pResultado, char* pMensaje, char* pMensajeError);
/** @brief pide un numero flotante al usuario y lo valida. Reintenta hasta conseguir un numero valido
*   @param pResultado float* guarda el numero validado en la pocision del puntero
*   @param pMensaje char* imprime al usuario por string el valor en ese puntero
*   @param pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
*
* retorna int return (-1) si huvo un error - (0) si ok
*/

int utn_getChar(char* pResultado, char* pMensaje, char* pMensajeError);
/** @brief pide un caracter al usuario y lo valida. Reintenta hasta conseguir un caracter valido
*   @param pResultado char* guarda el caracter validado en la pocision del puntero
*   @param pMensaje char* imprime al usuario por string el valor en ese puntero
*   @param pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
*
*   @return int return (-1) si huvo un error - (0) si ok
*/

void utn_clear();
/** @brief Limpia todo el texto que haya en la consola
*/

void utn_stop();
/** @brief Detiene la ejecucion del programa hasta que el usuario precione enter
*/

int utn_ingresoScring(char cadena[],char* pMensaje, char* pMensajeError, int tamPermitido);
/** @brief pide un string al usuario y valida que sea mas chico que el tamaño permitido. Reintenta hasta conseguir un string valido
*   @param cadena[] char destino donde se guardara el string ingresado
*   @param pMensaje char* imprime al usuario por string el valor en ese puntero
*   @param pMensajeError char* imprime al usuario por string el valor en ese puntero si no se ingresa un dato valido
*   @param tamPermitido int tamaño maximo del string ingresado
*
* retorna int return (-1) si huvo un error - (0) si ok
*/

int esPalabra(char vec[], int tam);
/** @brief pide un string por parametro y valida que todos los caracteres sean letras, si lo son tranforma todos a minuscula
*          y luego el primero a mayuscula
*   @param vec[] char
*   @param tam int tamaño maximo del string
*
*   @return int return (1) si todos los caracteres son letras - (0) si no todos son letras
*/


int esNumero(char vec[], int tam);
/** @brief pide un string por parametro y valida que todos los caracteres sean numeros.
*   @param vec[] char
*   @param tam int tamaño maximo del string
*
*   @return int return (1) si todos los caracteres son numeros - (0) si no todos son numeros
*/

int utn_confirmar(char* pResultado, char* pMensaje, char* pMensajeError, char criterio1, char criterio2);

int utn_ordenarFloat(float vec[], int tam, int criterio);
int utn_swapFloat(float* num1, float* num2);
int esNumerica(char bufferIn[]);
int utn_validarNombre(char vec[],int tam);
#endif /* UTN_H_ */
