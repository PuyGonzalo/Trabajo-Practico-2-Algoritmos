/****************************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: types.h
Descripción: Contiene tipos enumerativos y datos relacionados a las cadenas.
****************************************************************************/


#ifndef TYPES__H
#define TYPES__H

#include <stdio.h>

typedef enum {
              OK,
              ERROR_NULL_POINTER,
              ERROR_PROG_INVOCATION,
              ERROR_OUT_OF_MEMORY,
	      ERROR_OPEN_INPUT_FILE
             }status_t;


typedef enum{
             CSV,
             XML
            }export_t;

typedef enum{
             NAME,
             ARTIST,
             GENRE
            }sort_t;

typedef char* string;


#endif
