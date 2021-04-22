/*******************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumnos: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: track_print.h
Descripción: Contiene datos relacionados a funciones de impresión.
*******************************************************************/

#ifndef TRACK_PRINT__H
#define TRACK_PRINT__H

#include <stdio.h> 
#include "types.h"
#include "vector.h"

#define XML_VERSION_HEADER "<?xml version='1.0' ?>"
#define XML_LABEL_TRACKS "tracks"

/************************PROTOTIPOS***************************/
status_t print_tracks (const ADT_Vector_t *, format_t, FILE *);
status_t print_header_CSV(FILE *);
status_t print_footer_CSV(FILE *);
status_t print_header_XML(FILE *);
status_t print_footer_XML(FILE *);
/************************PROTOTIPOS***************************/
#endif
