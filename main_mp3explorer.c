/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Reigada, Maximiliano Daniel
Archivo: main_mp3explorer.c
Descripción: Programa principal.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_mp3explorer.h"
#include "utilities.h"
#include "types.h"
#include "vector.h"

extern setup_t setup;

int main (int argc, char *argv[])
{
	status_t st;
        ADT_Vector_t *vector;         

	if((st=validate_arguments(argc,argv,&setup))!=OK)
	   return st;

	if((st=ADT_Vector_new(&vector))!=OK)
          return st;


	return OK;
}


status_t validate_arguments (int argc, char *argv[], setup_t *setup)
{
	size_t i;

        if(argv==NULL || setup==NULL)
           return ERROR_NULL_POINTER;

	if(argc<MIN_ARGS) 
	return ERROR_PROG_INVOCATION;

	for(i=0;i<argc;i++)
        {
	    if(!strcmp(argv[i],CMD_ARG_FORMAT_FLAG)) 
	       break;
        }
   
        if(!strcmp(argv[i+1],CMD_ARG_FORMAT_CSV)) 
            setup->fmt=CSV;

	else if(!strcmp(argv[i+1],CMD_ARG_FORMAT_XML)) 
                setup->fmt=XML;

	else return ERROR_PROG_INVOCATION;


	for(i=0;i<argc;i++)
        {
	    if(!strcmp(argv[i],CMD_ARG_SORT_FLAG)) 
               break;
        }

        if(!strcmp(argv[i+1],CMD_ARG_SORT_BY_NAME)) 
           setup->sort=NAME;

	else if(!strcmp(argv[i+1],CMD_ARG_SORT_BY_ARTIST)) 
                setup->sort=ARTIST;

	else if(!strcmp(argv[i+1],CMD_ARG_SORT_BY_GENRE)) 
                setup->sort=GENRE;

	else return ERROR_PROG_INVOCATION;


        for(i=0;i<argc;i++)
        {
            if(!strcmp(argv[i],CMD_ARG_OUTPUT_PATH_FLAG)) 
               break;
        }

        if(argv[i+1]==NULL) 
           return ERROR_PROG_INVOCATION;

        if((setup->output_path=strdupl(argv[i+1]))==NULL) 
           return ERROR_OUT_OF_MEMORY;

   	return OK;
}
