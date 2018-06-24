/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Reigada, Maximiliano Daniel
Archivo: track.c
Descripción: Contiene funciones de manejo de TDA Track.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mp3.h"
#include "types.h"
#include "utilities.h"



/**************Comienzo de función de creacion de Track*****************/
status_t ADT_Track_new(ADT_Track_t **mp3)
{
	if(mp3==NULL) 
	   return ERROR_NULL_POINTER;
	if((*mp3=(ADT_Track_t *)malloc(sizeof(ADT_Track_t)))==NULL) 
           return ERROR_OUT_OF_MEMORY;

	(*mp3)->title=NULL;
	(*mp3)->artist=NULL;
	(*mp3)->album=NULL;
	(*mp3)->year=NULL;
	(*mp3)->tag=NULL;
	(*mp3)->comment=NULL;
	(*mp3)->genre=NULL;

	return OK;
}
/**************Final de función de creacion de Track*****************/



/**************Comienzo de función de destrucción de título de Track*****************/
status_t ADT_Track_destroy_title(ADT_Track_t *mp3)
{
	if(mp3==NULL)
           return ERROR_NULL_POINTER;

	if((mp3->title)!=NULL) 
        {
           free(mp3->title);
           mp3->title=NULL;
        }
       
        return OK;
}
/**************Comienzo de función de destrucción de título de Track*****************/



/**************Comienzo de función de destrucción de artista de Track*****************/
status_t ADT_Track_destroy_artist(ADT_Track_t *mp3)
{
	if(mp3==NULL) 
	   return ERROR_NULL_POINTER;

	if((mp3->artist)!=NULL) 
        {
           free(mp3->artist); 
           mp3->artist=NULL;
        }

	return OK;
}
/*****************Final de función de destrucción de artista de Track******************/



/**************Comienzo de función de destrucción de genero de Track*****************/
status_t ADT_Track_destroy_genre(ADT_Track_t *mp3)
{
	if(mp3==NULL) 
	return ERROR_NULL_POINTER;

	if((mp3->genre)!=NULL) 
        {
	   free(mp3->genre); 
           mp3->genre=NULL;
        }
      
        return OK;
}
/**************Final de función de destrucción de genero de Track*****************/



/**************Comienzo de función de impresión de Track*****************/
status_t ADT_Track_print(ADT_Track_t *mp3, FILE *fo)
{
	status_t st;

	if(mp3==NULL || fo==NULL) 
	   return ERROR_NULL_POINTER;

	if((st=mp3->printer(mp3,fo))!=OK) 
           return st;

	return OK;
}
/**************Final de función de impresión de Track*****************/



/**************Comienzo de función de seteo de impresión de Track*****************/
status_t ADT_Track_set_printer(ADT_Track_t *mp3, MP3_printer_t pf)
{
	if(mp3==NULL || pf==NULL) 
           return ERROR_NULL_POINTER;

	mp3->printer = pf;

	return OK;
}
/**************Final de función de seteo de impresión de Track*****************/




/**********Comienzo de función de seteo de título de Track***********/
status_t ADT_Track_set_title(ADT_Track_t *mp3, string new_title)
{
	if(mp3==NULL || new_title==NULL) 
           return ERROR_NULL_POINTER;

	if((mp3->title=strdupl(new_title))==NULL) 
           return ERROR_OUT_OF_MEMORY;

        return OK;
}
/**********Final de función de seteo de título de Track***********/



/**********Comienzo de función de seteo de artista de Track***********/
status_t ADT_Track_set_artist(ADT_Track_t *mp3, string new_artist)
{
	if(mp3==NULL || new_artist==NULL) 
           return ERROR_NULL_POINTER;

	if((mp3->artist=strdupl(new_artist))==NULL) 
           return ERROR_OUT_OF_MEMORY;

	return OK;
}
/**********Final de función de seteo de artista de Track***********/



/**********Comienzo de función de seteo de género de Track***********/
status_t ADT_Track_set_genre(ADT_Track_t *mp3, string new_genre)
{
	if(mp3==NULL || new_genre==NULL) 
	   return ERROR_NULL_POINTER;

	if((mp3->genre=strdupl(new_genre))==NULL) 
           return ERROR_OUT_OF_MEMORY;

	return OK;
}
/**********Final de función de seteo de género de Track***********/



/**********Comienzo de función de obtención de título de Track***********/
status_t ADT_Track_get_title (ADT_Track_t *mp3, string *s)
{
	if(mp3==NULL || mp3->title==NULL) 
	   return ERROR_NULL_POINTER;

	if((*s=strdupl(mp3->title))==NULL) 
	   return ERROR_OUT_OF_MEMORY;

	return OK;
}
/**********Final de función de obtención de título de Track***********/



/**********Comienzo de función de obtención de artista de Track***********/
status_t ADT_Track_get_artist (ADT_Track_t *mp3, string *s)
{
	if(mp3==NULL || mp3->artist==NULL) 
   	   return ERROR_NULL_POINTER;

	if((*s=strdupl(mp3->artist))==NULL) 
  	   return ERROR_OUT_OF_MEMORY;

  	return OK;
}
/**********Final de función de obtención de artista de Track***********/



/****************Comienzo de función de obtención de artista de Track*****************/
status_t ADT_Track_get_genre (ADT_Track_t *mp3, string *s,const string *genres_dictionary)
{
	size_t aux;

	if(mp3==NULL || mp3->genre==NULL || genres_dictionary==NULL) 
	   return ERROR_NULL_POINTER;

	aux=strtoul(mp3->genre,NULL,10);  

	if((*s=strdupl(genres_dictionary[aux]))==NULL) 
	   return ERROR_OUT_OF_MEMORY;

	return OK;
}
/*****************Final de función de obtención de artista de Track****************/
