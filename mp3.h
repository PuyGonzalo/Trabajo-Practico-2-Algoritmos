/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: mp3explorer.h
Descripción: Contiene datos referidos a funciones de manejo de mp3.
************************************************************************/
#ifndef MP3EXPLORER__H
#define MP3EXPLORER__H

#include <stdio.h>
#include "types.h"
#include "track.h"
#include "vector.h"

#define MP3_HEADER_SIZE	  128


#define LEXEM_START_TAG     0
#define LEXEM_SPAN_TAG      3

#define LEXEM_START_TITLE   3
#define LEXEM_SPAN_TITLE   30

#define LEXEM_START_ARTIST 33
#define LEXEM_SPAN_ARTIST  30

#define LEXEM_START_ALBUM  63
#define LEXEM_SPAN_ALBUM   30

#define LEXEM_START_YEAR   93
#define LEXEM_SPAN_YEAR     4

#define LEXEM_START_COMMENT 97
#define LEXEM_SPAN_COMMENT  30

#define LEXEM_START_GENRE  127
#define LEXEM_SPAN_GENRE     1

#define MASK_GENRE        0xFF


/**********************************PROTOTYPES***********************************/
status_t get_mp3_header (FILE * f, char * header);
status_t set_track_from_mp3_header (const char header[], ADT_Track_t **track);
status_t load_track_mp3_on_vector (FILE * f, ADT_Vector_t * p);
/**********************************PROTOTYPES***********************************/

#endif
