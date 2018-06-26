/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: track.h
Descripción: Contiene prototipos de primitivas y TDA Track.
************************************************************************/


#ifndef TRACK__H
#define TRACK__H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define LENGHT_TAG      3
#define LENGHT_TITLE   30
#define LENGHT_ARTIST  30
#define LENGHT_ALBUM   30
#define LENGHT_YEAR     4
#define LENGHT_COMMENT 30

typedef status_t (*Track_printer_t)(const void *, FILE* );

typedef struct{
	       char tag[LENGHT_TAG];
   	       char title[LENGHT_TITLE]; 
               char artist[LENGHT_ARTIST];
               char album[LENGHT_ALBUM];
               char year[LENGHT_YEAR];
               unsigned int genre;
               char comment[LENGHT_COMMENT];
               Track_printer_t printer;
              }ADT_Track_t;

/******************************PROTOTIPOS TDA MP3*************************************/
status_t ADT_Track_new (ADT_Track_t **);
status_t ADT_Track_delete (void **);

status_t ADT_Track_print (ADT_Track_t *,FILE *);
status_t ADT_Track_set_printer (ADT_Track_t *, Track_printer_t );

status_t ADT_Track_set_title (ADT_Track_t *, string);
status_t ADT_Track_set_artist (ADT_Track_t *, string);
status_t ADT_Track_set_genre (ADT_Track_t *, unsigned int);
status_t ADT_Track_set_album (ADT_Track_t *, string);
status_t ADT_Track_set_year (ADT_Track_t *, string);
status_t ADT_Track_set_tag (ADT_Track_t *, string);
status_t ADT_Track_set_comment(ADT_Track_t *, string);

int ADT_Track_compare_by_title (const ADT_Track_t *a, const ADT_Track_t *b);
int ADT_Track_compare_by_artist (const ADT_Track_t *a, const ADT_Track_t *b);
int ADT_Track_compare_by_genre (const ADT_Track_t *a, const ADT_Track_t *b);
status_t ADT_Track_export_as_CSV (const void * pv, char delimitter, FILE * fo);
/********************************PROTOTIPOS TDA MP3***********************************/

#endif
