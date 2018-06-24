/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Reigada, Maximiliano Daniel
Archivo: vector.h
Descripción: Contiene prototipos de primitivas y TDA Vector.
************************************************************************/


#ifndef VECTOR__H
#define VECTOR__H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define ADT_VECTOR_INIT_CHOP 30

typedef status_t (*Vector_printer_t)(const void *, FILE *);
typedef void (*destructor_t)(void *);

typedef struct{
               void **data;
               size_t size; 
               size_t alloc_size;
               destructor_t destructor;
               Vector_printer_t printer;
              }ADT_Vector_t;

/*********************PROTOTIPOS TDA VECTOR***********************/
status_t ADT_Vector_new (ADT_Vector_t **);
status_t ADT_Vector_delete (ADT_Vector_t **);
status_t ADT_Vector_set_destructor (ADT_Vector_t *, destructor_t);
status_t ADT_Vector_append (ADT_Vector_t *, void *);
void * ADT_Vector_get_element (const ADT_Vector_t *, size_t);
size_t ADT_Vector_get_size (ADT_Vector_t *);
status_t ADT_Vector_Print (ADT_Vector_t *, FILE *);
status_t ADT_Vector_set_printer (ADT_Vector_t *, Vector_printer_t);
/*********************PROTOTIPOS TDA VECTOR***********************/

#endif
