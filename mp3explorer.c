/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: mp3explorer.c
Descripción: Contiene funcion de procesamiento de archivos mp3.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "vector.h"
#include "track.h"
#include "mp3explorer.h"
#include "mp3.h"
#include "setup.h"


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

	
	switch(setup.sort)
 	{
	      case NAME:   	 if((st=ADT_Vector_sort(vector,ADT_Track_compare_by_title))!=OK)
				 {   
                                    ADT_Vector_delete(&vector);
				    return st;
				 }break;
		
	      case ARTIST:       if((st=ADT_Vector_sort(vector,ADT_Track_compare_by_artist))!=OK)
				 {   
                                    ADT_Vector_delete(&vector);
				    return st;
				 }break;

	      case GENRE:        if((st=ADT_Vector_sort(vector,ADT_Track_compare_by_genre))!=OK)
				 {   
                                    ADT_Vector_delete(&vector);
				    return st;
				 }break;
	}
 
	if((fo=fopen(files[setup.output_path],"wt"))==NULL)
	{
	   ADT_Vector_delete(&vector);
	   return ERROR_OPEN_INPUT_FILE;
	}

        switch(setup.fmt)  
	{
	       case CSV:        if((st=ADT_Vector_export_as_CSV(vector, fo, CSV_TRAKS_DELIMITER, ADT_Track_export_as_CSV))!=OK)
				{
 	                           fclose(fo);
				   remove(files[setup.output_path]);
	 			   ADT_Vector_delete(&vector);	
				   return st;
				}break;	

	       case XML:        if((st=ADT_Vector_export_as_XML(vector, fo,TRACKS_TAG,TRACKS_TAG, ADT_Track_export_as_XML))!=OK)
				{
 	                           fclose(fo);
				   remove(files[setup.output_path]);
	 			   ADT_Vector_delete(&vector);	
				   return st;
				}break;

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
