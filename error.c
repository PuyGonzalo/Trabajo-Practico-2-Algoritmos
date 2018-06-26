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
		"Bandera de ordenamiento incorrecta",
		"Ruta de archivo de salida incorrecta",
		"Error memoria",
		"Fallo al abrir archivo de entrada",
		"Fallo al abrir archivo de salida",
};

status_t print_error (FILE * f, status_t st)
{
	if(stream == NULL)
		return ERROR_NULL_POINTER;

	fprintf(f, "%s\n", error_dictionary[st]);

	return OK;
}