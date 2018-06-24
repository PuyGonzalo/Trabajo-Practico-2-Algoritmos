/****************************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Reigada, Maximiliano Daniel
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
              ERROR_OUT_OF_MEMORY
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
