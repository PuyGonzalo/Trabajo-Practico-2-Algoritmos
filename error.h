/*************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: errors.c
Descripción: Contiene diccionario de errores.
*************************************************************/

#ifndef ERROR__H
#define ERROR__H

#include <stdio.h>
#include "types.h"

status_t print_error (FILE * f, status_t st);

#define MAX_ERRORS  /* FALTA AGREGAR EL NUMERO DE ERRORES FINAL */

#endif
