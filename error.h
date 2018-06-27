/*******************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumnos: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: errors.h
Descripción: Contiene datos relacionados al diccionario de errores.
*******************************************************************/

#ifndef ERROR__H
#define ERROR__H

#include <stdio.h>
#include "types.h"

#define MAX_ERRORS 10


/****************PROTOTIPOS*********************/
status_t print_error (FILE * f, status_t st);
/****************PROTOTIPOS*********************/
#endif
