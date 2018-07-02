/******************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumnos: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: mp3explorer.c
Descripción: Contiene función de procesamiento de archivos mp3.
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "vector.h"
#include "track.h"
#include "mp3explorer.h"
#include "mp3.h"
#include "setup.h"
#include "track_print.h"

extern int (*compare[MAX_COMPARE])(const void*, const void*);

status_t process_mp3_files (string files[], setup_t setup)
{
	status_t st;
	size_t i;
	FILE* fi;
	FILE* fo;
 	ADT_Vector_t *vector;
	ADT_Track_t *track;	

	if(files==NULL)
	   return ERROR_NULL_POINTER;

	if((st=ADT_Vector_new(&vector))!=OK)
           return st;   

	if((st=ADT_Vector_set_destructor(vector,ADT_Track_delete))!=OK) 
           return st;	 		

	for(i=setup.input_path;files[i]!=NULL;i++)
	{
	    if((fi=fopen(files[i],"rb"))==NULL)
	    {
	       ADT_Vector_delete(&vector);
	       return ERROR_OPEN_INPUT_FILE;
            }
	
	    if((st=process_mp3_file(fi,&track))!=OK)
            {
	       ADT_Vector_delete(&vector);
	       fclose(fi);
               return st;
            }
	
 	    fclose(fi);
	
  	    if((st=ADT_Vector_append(vector,track))!=OK)
	    {
	       ADT_Vector_delete(&vector);
	       ADT_Track_delete((void*)&track);
	       return st;
	    }

	}     

	
	if((st=ADT_Vector_sort(vector,compare[setup.sort]))!=OK)
        {   
            ADT_Vector_delete(&vector);
            return st;
        }
	
 
	if((fo=fopen(files[setup.output_path],"wt"))==NULL)
	{
	   ADT_Vector_delete(&vector);
	   return ERROR_OPEN_INPUT_FILE;
	}

	if((st=print_tracks(vector,setup.fmt,fo))!=OK)
	{
 	   fclose(fo);
	   remove(files[setup.output_path]);
	   ADT_Vector_delete(&vector);	
	   return st;
	}	

	if(fclose(fo)==EOF)
	{
           ADT_Vector_delete(&vector);	
	   return ERROR_DISK_SPACE;
	}

        if((st=ADT_Vector_delete(&vector))!=OK)
           return st;

 	return OK;
}
