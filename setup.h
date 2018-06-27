/*********************************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: setup.h
Descripción: Contiene datos relacionados a las estructuras utilizadas.
**********************************************************************************/

#ifndef SETUP__H
#define SETUP__H

#include <stdio.h>
#include "types.h"

typedef struct {
                export_t  fmt;
                sort_t   sort;               
                string   output_path;
               }setup_t;

#endif
