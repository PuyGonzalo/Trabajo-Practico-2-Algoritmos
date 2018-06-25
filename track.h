/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Reigada, Maximiliano Daniel
Archivo: track.h
Descripción: Contiene prototipos de primitivas y TDA Track.
************************************************************************/


#ifndef TRACK__H
#define TRACK__H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "utilities.h"

typedef status_t (*Track_printer_t)(const void *, FILE* );

typedef struct{
   	       string title; 
               string artist;
               string album;
               string year;
               string genre;
               string comment;
               string tag;
               Track_printer_t printer;
              }ADT_Track_t;

/******************************PROTOTIPOS TDA MP3*************************************/
status_t ADT_Track_new (ADT_Track_t *);
status_t ADT_Track_delete (ADT_Track_t *);

status_t ADT_Track_destroy (ADT_Track_t *);
status_t ADT_Track_destroy_artist (ADT_Track_t *);
status_t ADT_Track_destroy_genre (ADT_Track_t *);
status_t ADT_Track_destroy_album (ADT_Track_t *);
status_t ADT_Track_destroy_year (ADT_Track_t *);
status_t ADT_Track_destroy_comment (ADT_Track_t *);
status_t ADT_Track_destroy_tag (ADT_Track_t *);


status_t ADT_Track_print (ADT_Track_t *,FILE *);
status_t ADT_Track_set_printer (ADT_Track_t *, Track_printer_t );

status_t ADT_Track_set_title (ADT_Track_t *, string);
status_t ADT_Track_set_artist (ADT_Track_t *, string);
status_t ADT_Track_set_genre (ADT_Track_t *, string);
status_t ADT_Track_set_album (ADT_Track_t *, string);
status_t ADT_Track_set_year (ADT_Track_t *, string);
status_t ADT_Track_set_comment (ADT_Track_t *, string);
status_t ADT_Track_set_tag (ADT_Track_t *, string);


status_t ADT_Track_get_title (ADT_Track_t *, string *);
status_t ADT_Track_get_artist (ADT_Track_t *, string *);
status_t ADT_Track_get_genre (ADT_Track_t *, string *s,const string *genres_dictionary);
status_t ADT_Track_get_album (ADT_Track_t *, string *);
status_t ADT_Track_get_year (ADT_Track_t *, string *);
status_t ADT_Track_get_comment (ADT_Track_t *, string *);
status_t ADT_Track_get_tag (ADT_Track_t *, string *);
/********************************PROTOTIPOS TDA MP3***********************************/

#endif
