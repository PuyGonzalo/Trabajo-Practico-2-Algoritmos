/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: main_mp3explorer.c
Descripción: Programa principal.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_mp3explorer.h"
#include "mp3explorer.h"
#include "types.h"
#include "error.h"


extern setup_t setup;

int main (int argc, char *argv[])
{
	status_t st;
        
	if((st=validate_arguments(argc,argv,&setup))!=OK)
	{
		print_error(stderr,st);
		return st;
	}

	if((st=process_mp3_files(argv,setup))!=OK)
	{
		print_error(stderr,st);
		return st;
	}
	
	return OK;
}


status_t validate_arguments (int argc, char *argv[], setup_t *setup)
{
	size_t i;

        if(argv==NULL || setup==NULL)
           return ERROR_NULL_POINTER;

	if(argc<MIN_ARGS) 
	return ERROR_NUMBER_OF_ARGS;

	for(i=0;i<argc;i++)
        {
	    if(!strcmp(argv[i],CMD_ARG_FORMAT_FLAG)) 
	       break;
        }

	if(i==argc)
	   return ERROR_FORMAT_FLAG;
   
        if(!strcmp(argv[i+1],CMD_ARG_FORMAT_CSV)) 
            setup->fmt=CSV;

	else if(!strcmp(argv[i+1],CMD_ARG_FORMAT_XML)) 
                setup->fmt=XML;

	else return ERROR_INVALID_FORMAT;


	for(i=0;i<argc;i++)
        {
	    if(!strcmp(argv[i],CMD_ARG_SORT_FLAG)) 
               break;
        }

	if(i==argc)
	   return ERROR_SORT_FLAG;

        if(!strcmp(argv[i+1],CMD_ARG_SORT_BY_NAME)) 
           setup->sort=NAME;

	else if(!strcmp(argv[i+1],CMD_ARG_SORT_BY_ARTIST)) 
                setup->sort=ARTIST;

	else if(!strcmp(argv[i+1],CMD_ARG_SORT_BY_GENRE)) 
                setup->sort=GENRE;

	else return ERROR_INVALID_SORT;


        for(i=0;i<argc;i++)
        {
            if(!strcmp(argv[i],CMD_ARG_OUTPUT_PATH_FLAG)) 
               break;
        }

	if(i==argc)
	   return ERROR_OUTPUT_PATH_FLAG;

        if(argv[i+1]==NULL) 
           return ERROR_OUTPUT_PATH;

        setup->output_path=i+1;
	setup->input_path=CMD_ARG_POS_FIRST_INPUT_FILE;

   	return OK;
}
