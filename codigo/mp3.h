/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumnos: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: mp3.h
Descripción: Contiene datos referidos a funciones de manejo de mp3.
************************************************************************/
#ifndef MP3__H
#define MP3__H

#include <stdio.h>
#include "types.h"
#include "track.h"

#define MP3_HEADER_SIZE	  128

#define LEXEM_START_TAG     0

#define LEXEM_START_TITLE   3

#define LEXEM_START_ARTIST 33

#define LEXEM_START_ALBUM  63

#define LEXEM_START_YEAR   93

#define LEXEM_START_COMMENT 97

#define LEXEM_START_GENRE  127
#define LEXEM_SPAN_GENRE     1


/*********************************PROTOTYPES**********************************/
status_t process_mp3_file (FILE *, ADT_Track_t **);
status_t get_mp3_header (FILE * , char * header);
status_t set_track_from_mp3_header (const string header, ADT_Track_t *track);
/*********************************PROTOTYPES**********************************/

#endif
