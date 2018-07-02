/************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumnos: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: setup.h
Descripción: Contiene datos relacionados a la configuración.
************************************************************/

#ifndef SETUP__H
#define SETUP__H

#include <stdio.h>
#include "types.h"

typedef struct {
                format_t  fmt;
                sort_t    sort;               
                size_t    output_path;
	        size_t    input_path;
               }setup_t;

#endif


