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
#include "types.h"

#define TAG_FIELD_LENGHT      3
#define TITLE_FIELD_LENGHT   30
#define ARTIST_FIELD_LENGHT  30
#define ALBUM_FIELD_LENGHT   30
#define YEAR_FIELD_LENGHT     4
#define COMMENT_FIELD_LENGHT 30

#define XML_LABEL_TRACK "track"
#define XML_LABEL_NAME "name"
#define XML_LABEL_ARTIST "artist"
#define XML_LABEL_GENRE "genre"


typedef status_t (*Track_printer_t)(const void *, FILE* );

typedef struct{
	       char tag[TAG_FIELD_LENGHT];
   	       char title[TITLE_FIELD_LENGHT]; 
               char artist[ARTIST_FIELD_LENGHT];
               char album[ALBUM_FIELD_LENGHT];
               char year[YEAR_FIELD_LENGHT];
               unsigned int genre;
               char comment[COMMENT_FIELD_LENGHT];
               Track_printer_t printer;
              }ADT_Track_t;

/******************************PROTOTIPOS TDA MP3*************************************/
status_t ADT_Track_new (ADT_Track_t **);
status_t ADT_Track_delete (void **);

status_t ADT_Track_set_title (ADT_Track_t *, const string);
status_t ADT_Track_set_artist (ADT_Track_t *, const string);
status_t ADT_Track_set_genre (ADT_Track_t *, unsigned int);
status_t ADT_Track_set_album (ADT_Track_t *, const string);
status_t ADT_Track_set_year (ADT_Track_t *, const string);
status_t ADT_Track_set_tag (ADT_Track_t *, const string);
status_t ADT_Track_set_comment(ADT_Track_t *, const string);

int ADT_Track_compare_by_title (const void *, const void *);
int ADT_Track_compare_by_artist (const void *, const void *);
int ADT_Track_compare_by_genre (const void *, const void *);

status_t ADT_Track_export_as_CSV (const void *, const void *, FILE *);
status_t ADT_Track_export_as_XML (const void *, const void *, FILE *);

status_t ADT_Track_print (ADT_Track_t *,FILE *);
status_t ADT_Track_set_printer (ADT_Track_t *, Track_printer_t );
/********************************PROTOTIPOS TDA MP3***********************************/

#endif
