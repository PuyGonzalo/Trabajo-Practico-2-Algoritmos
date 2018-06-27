/*************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumnos: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: errors.c
Descripción: Contiene diccionario de errores.
*************************************************************/

#include <stdio.h>
#include "error.h"
#include "types.h"

static char * error_dictionary[MAX_ERRORS]=
{
		"OK",
		"Puntero nulo",
		"Espacio en disco insuficiente",
		"Numero de argumentos invalido",
		"Bandera de formato incorrecta",
	    "Formato invalido",
		"Bandera de criterio de ordenamiento incorrecta",
		"Criterio de ordenamiento incorrecto",
		"Bandera de ruta de salida incorrecta",
		"Ruta de ruta de salida incorrecta",
		"Error memoria",
		"Fallo al abrir archivo de entrada",
		"Fallo al abrir archivo de salida"
};


/***Comienzo de función de impresión de mensaje de error***/
status_t print_error (FILE * f, status_t st)
{
	if(f==NULL)
	   return ERROR_NULL_POINTER;

	fprintf(f,"%s\n",error_dictionary[st]);

	return OK;
}
/****Final de función de impresión de mensaje de error*****/
