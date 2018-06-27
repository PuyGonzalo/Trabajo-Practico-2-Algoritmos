/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: mp3explorer.h
Descripción: Contiene datos referidos a funciones de procesamiento de mp3.
************************************************************************/
#ifndef MP3EXPLORER__H
#define MP3EXPLORER__H

#include <stdio.h>
#include "types.h"

#define TRACKS_TAG "tracks"
#define CSV_TRAKS_DELIMITER '|'

/**********************************PROTOTYPES***********************************/
status_t process_mp3_files (char *[]);
/**********************************PROTOTYPES***********************************/

#endif
