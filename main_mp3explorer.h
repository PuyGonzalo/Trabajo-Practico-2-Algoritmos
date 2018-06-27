/**********************************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: main_mp3explorer.h
Descripción: Contiene datos relacionados a la validacion de argumentos.
*********************************************************************************/

#ifndef MAIN_MP3EXPLORER__H
#define MAIN_MP3EXPLORER__H

#include <stdio.h>
#include "types.h"
#include "setup.h"
#include "vector.h"

#define MIN_ARGS 8

#define CMD_ARG_FORMAT_FLAG "-fmt"
#define CMD_ARG_FORMAT_CSV "csv"
#define CMD_ARG_FORMAT_XML "xml"
#define CMD_ARG_SORT_FLAG "-sort"
#define CMD_ARG_SORT_BY_NAME "name"
#define CMD_ARG_SORT_BY_ARTIST "artist"
#define CMD_ARG_SORT_BY_GENRE "genre"
#define CMD_ARG_OUTPUT_PATH_FLAG "-out"
#define CMD_ARG_POS_FIRST_INPUT_FILE 7

	
/*************************PROTOTYPES***********************/
status_t validate_arguments (int ,char *[],setup_t *);
/*************************PROTOTYPES***********************/
#endif
