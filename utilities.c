/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Reigada, Maximiliano Daniel
Archivo: utilities.c
Descripción: Contiene función de manejo de arreglos.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "utilities.h"

/*************Comienzo de función de clonado de arreglos*************/
string strdupl(const string s)
{
	char *t;
	size_t i;

	if(s==NULL)
	   return NULL;

	if((t=(char*)malloc((strlen(s)+1)*sizeof(char)))==NULL)
           return NULL;

	for (i=0;(t[i]=s[i]);i++);

        return t;
}
/***************Final de función de clonado de arreglos***************/
