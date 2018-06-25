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
#include "utilities.h"
#include "types.h"
#include "vector.h"
#include "track.h"
#include "mp3.h"

extern setup_t setup;

int main (int argc, char *argv[])
{
	status_t st;
        ADT_Vector_t *vector; 
	size_t i;
        
	if((st=validate_arguments(argc,argv,&setup))!=OK){ puts("mall");
           return st;}

	if((st=ADT_Vector_new(&vector))!=OK)
           return st;          
      
	if((st=load_vector(vector,argv))!=OK)
	   return st;

	for(i=0;i<argc-CMD_ARG_POS_FIRST_INPUT_FILE;i++)       /*ACA IRIAN ORDENAR E IMPRIMIR*/
	puts(((ADT_Track_t *)(vector->element[i]))->title);	

        if((st=ADT_Vector_delete(&vector))!=OK)
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
            if(!strcmp(argv[i],CMD_ARG_OUTPUT_FILE_FLAG)) 
               break;
        }

        if(argv[i+1]==NULL) 
           return ERROR_PROG_INVOCATION;

        if((setup->output_path=strdupl(argv[i+1]))==NULL) 
           return ERROR_OUT_OF_MEMORY;

   	return OK;
}


status_t load_vector(ADT_Vector_t *vector,char *argv[])
{
	status_t st;
	size_t i;
	FILE* fi;
 
	if(vector==NULL || argv==NULL)
	   return ERROR_NULL_POINTER;

	if((st=ADT_Vector_set_destructor(vector,ADT_Track_delete))!=OK) 
           return st;	 	

	for(i=CMD_ARG_POS_FIRST_INPUT_FILE;argv[i]!=NULL;i++)
	{
	    if((fi=fopen(argv[i],"rb"))==NULL)
	    {
               ADT_Vector_delete(&vector);
	       return ERROR_OPEN_INPUT_FILE;
            }
	
	    if((st=load_track_mp3(fi,vector))!=OK)
            {
               ADT_Vector_delete(&vector);
	       return st;
            }
		
	    fclose(fi);
	}     

 	return OK;
}

