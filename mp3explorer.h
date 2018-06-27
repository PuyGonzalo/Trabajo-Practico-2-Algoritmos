/*************************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumnos: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: mp3explorer.h
Descripción: Contiene datos referidos a funciones de procesamiento de mp3.
**************************************************************************/
#ifndef MP3EXPLORER__H
#define MP3EXPLORER__H

#include <stdio.h>
#include "types.h"
#include "setup.h"

#define TRACKS_TAG "tracks"
#define CSV_TRAKS_DELIMITER '|'

/*****************PROTOTIPOS********************/
status_t process_mp3_files (string[], setup_t);
/****************PROTOTIPOS*********************/

#endif
