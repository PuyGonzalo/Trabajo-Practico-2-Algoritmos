/****************************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumnos: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: types.h
Descripción: Contiene tipos enumerativos y datos relacionados a las cadenas.
****************************************************************************/


#ifndef TYPES__H
#define TYPES__H

#include <stdio.h>

typedef enum 
{
    OK=0,
    ERROR_NULL_POINTER=1,
    ERROR_DISK_SPACE=2,
    ERROR_NUMBER_OF_ARGS=3,
    ERROR_FORMAT_FLAG=4,
    ERROR_INVALID_FORMAT=5,
    ERROR_SORT_FLAG=6,
    ERROR_INVALID_SORT=7,
    ERROR_OUTPUT_PATH_FLAG=8,
    ERROR_OUTPUT_PATH=9,
    ERROR_OUT_OF_MEMORY=10,
    ERROR_OPEN_INPUT_FILE=11,
    ERROR_OPEN_OUTPUT_FILE=12
}status_t;


typedef enum
{
    CSV,
    XML
}export_t;

typedef enum
{
    NAME,
    ARTIST,
    GENRE
}sort_t;

typedef char* string;

#endif
