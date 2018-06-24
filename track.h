/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Reigada, Maximiliano Daniel
Archivo: track.h
Descripción: Contiene prototipos de primitivas y TDA Track.
************************************************************************/


#ifndef MP3__H
#define MP3__H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "utilities.h"

typedef status_t (*MP3_printer_t)(const void *, FILE* );

typedef struct{
   	       string title; 
               string artist;
               string album;
               string year;
               string genre;
               string tag;
               string comment;
               MP3_printer_t printer;
              }ADT_Track_t;

/******************************PROTOTIPOS TDA MP3*************************************/
status_t ADT_Track_new (ADT_Track_t **);
status_t ADT_Track_destroy_title (ADT_Track_t *);
status_t ADT_Track_destroy_artist (ADT_Track_t *);
status_t ADT_Track_destroy_genre (ADT_Track_t *);
status_t ADT_Track_print (ADT_Track_t *,FILE *);
status_t ADT_Track_set_printer (ADT_Track_t *, MP3_printer_t );
status_t ADT_Track_set_title (ADT_Track_t *, string);
status_t ADT_Track_set_artist (ADT_Track_t *, string);
status_t ADT_Track_set_genre (ADT_Track_t *, string);
status_t ADT_Track_get_title (ADT_Track_t *, string *);
status_t ADT_Track_get_artist (ADT_Track_t *, string *);
status_t ADT_Track_get_genre (ADT_Track_t *mp3, string *s,const string *genres_dictionary);
/********************************PROTOTIPOS TDA MP3***********************************/

#endif
