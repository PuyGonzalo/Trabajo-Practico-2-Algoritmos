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
#include "track.h"
#include "types.h"
#include "utilities.h"



/**************Comienzo de función de creacion de Track*****************/
status_t ADT_Track_new(ADT_Track_t *track)
{
	if(track==NULL) 
	   return ERROR_NULL_POINTER;

	(*track).title=NULL;
	(*track).artist=NULL;
	(*track).album=NULL;
	(*track).year=NULL;
	(*track).comment=NULL;
	(*track).genre=NULL;

	return OK;
}
/**************Final de función de creacion de Track*****************/



/**************Comienzo de función de destrucción de título de Track*****************/
status_t ADT_Track_destroy_title(ADT_Track_t *track)
{
	if(track==NULL)
           return ERROR_NULL_POINTER;

	if((track->title)!=NULL) 
        {
           free(track->title);
           track->title=NULL;
        }
       
        return OK;
}
/**************Comienzo de función de destrucción de título de Track*****************/



/**************Comienzo de función de destrucción de artista de Track*****************/
status_t ADT_Track_destroy_artist(ADT_Track_t *track)
{
	if(track==NULL) 
	   return ERROR_NULL_POINTER;

	if((track->artist)!=NULL) 
        {
           free(track->artist); 
           track->artist=NULL;
        }

	return OK;
}
/*****************Final de función de destrucción de artista de Track******************/



/**************Comienzo de función de destrucción de género de Track*****************/
status_t ADT_Track_destroy_genre(ADT_Track_t *track)
{
	if(track==NULL) 
	return ERROR_NULL_POINTER;

	if((track->genre)!=NULL) 
        {
	   free(track->genre); 
           track->genre=NULL;
        }
      
        return OK;
}
/**************Final de función de destrucción de género de Track*****************/



/**************Comienzo de función de destrucción de album de Track*****************/
status_t ADT_Track_destroy_album(ADT_Track_t *track)
{
	if(track==NULL) 
	return ERROR_NULL_POINTER;

	if((track->album)!=NULL) 
        {
	   free(track->album); 
           track->album=NULL;
        }
      
        return OK;
}
/**************Final de función de destrucción de album de Track*****************/




/**************Comienzo de función de destrucción de comentario de Track*****************/
status_t ADT_Track_destroy_comment(ADT_Track_t *track)
{
	if(track==NULL) 
	return ERROR_NULL_POINTER;

	if((track->comment)!=NULL) 
        {
	   free(track->comment); 
           track->comment=NULL;
        }
      
        return OK;
}
/**************Final de función de destrucción de comentario de Track*****************/



/**************Comienzo de función de impresión de Track*****************/
status_t ADT_Track_print(ADT_Track_t *track, FILE *fo)
{
	status_t st;

	if(track==NULL || fo==NULL) 
	   return ERROR_NULL_POINTER;

	if((st=track->printer(track,fo))!=OK) 
           return st;

	return OK;
}
/**************Final de función de impresión de Track*****************/



/**************Comienzo de función de seteo de impresión de Track*****************/
status_t ADT_Track_set_printer(ADT_Track_t *track, Track_printer_t pf)
{
	if(track==NULL || pf==NULL) 
           return ERROR_NULL_POINTER;

	track->printer = pf;

	return OK;
}
/**************Final de función de seteo de impresión de Track*****************/



/**********Comienzo de función de seteo de título de Track***********/
status_t ADT_Track_set_title(ADT_Track_t *track, string new_title)
{
	if(track==NULL || new_title==NULL) 
           return ERROR_NULL_POINTER;

	if((track->title=strdupl(new_title))==NULL) 
           return ERROR_OUT_OF_MEMORY;

        return OK;
}
/**********Final de función de seteo de título de Track***********/



/**********Comienzo de función de seteo de artista de Track***********/
status_t ADT_Track_set_artist(ADT_Track_t *track, string new_artist)
{
	if(track==NULL || new_artist==NULL) 
           return ERROR_NULL_POINTER;

	if((track->artist=strdupl(new_artist))==NULL) 
           return ERROR_OUT_OF_MEMORY;

	return OK;
}
/**********Final de función de seteo de artista de Track***********/



/**********Comienzo de función de seteo de género de Track***********/
status_t ADT_Track_set_genre(ADT_Track_t *track, string new_genre)
{
	if(track==NULL || new_genre==NULL) 
	   return ERROR_NULL_POINTER;

	if((track->genre=strdupl(new_genre))==NULL) 
           return ERROR_OUT_OF_MEMORY;

	return OK;
}
/**********Final de función de seteo de género de Track***********/



/**********Comienzo de función de seteo de album de Track***********/
status_t ADT_Track_set_album(ADT_Track_t *track, string new_album)
{
	if(track==NULL || new_album==NULL) 
           return ERROR_NULL_POINTER;

	if((track->album=strdupl(new_album))==NULL) 
           return ERROR_OUT_OF_MEMORY;

	return OK;
}
/**********Final de función de seteo de album de Track***********/



/**********Comienzo de función de seteo de año de Track***********/
status_t ADT_Track_set_year(ADT_Track_t *track, string new_year)
{
	if(track==NULL || new_year==NULL) 
           return ERROR_NULL_POINTER;

	if((track->year=strdupl(new_year))==NULL) 
           return ERROR_OUT_OF_MEMORY;

	return OK;
}
/**********Final de función de seteo de año de Track***********/




/**********Comienzo de función de seteo de comentario de Track***********/
status_t ADT_Track_set_comment(ADT_Track_t *track, string new_comment)
{
	if(track==NULL || new_comment==NULL) 
           return ERROR_NULL_POINTER;

	if((track->comment=strdupl(new_comment))==NULL) 
           return ERROR_OUT_OF_MEMORY;

	return OK;
}
/**********Final de función de seteo de comentario de Track***********/



/**********Comienzo de función de obtención de título de Track***********/
status_t ADT_Track_get_title (ADT_Track_t *track, string *s)
{
	if(track==NULL || track->title==NULL) 
	   return ERROR_NULL_POINTER;

	if((*s=strdupl(track->title))==NULL) 
	   return ERROR_OUT_OF_MEMORY;

	return OK;
}
/**********Final de función de obtención de título de Track***********/



/**********Comienzo de función de obtención de artista de Track***********/
status_t ADT_Track_get_artist (ADT_Track_t *track, string *s)
{
	if(track==NULL || track->artist==NULL) 
   	   return ERROR_NULL_POINTER;

	if((*s=strdupl(track->artist))==NULL) 
  	   return ERROR_OUT_OF_MEMORY;

  	return OK;
}
/**********Final de función de obtención de artista de Track***********/



/****************Comienzo de función de obtención de género de Track*****************/
status_t ADT_Track_get_genre (ADT_Track_t *track, string *s,const string *genres_dictionary)
{
	size_t aux;

	if(track==NULL || track->genre==NULL || genres_dictionary==NULL) 
	   return ERROR_NULL_POINTER;

	aux=strtoul(track->genre,NULL,10);  

	if((*s=strdupl(genres_dictionary[aux]))==NULL) 
	   return ERROR_OUT_OF_MEMORY;

	return OK;
}
/*****************Final de función de obtención de género de Track****************/



/**********Comienzo de función de obtención de album de Track***********/
status_t ADT_Track_get_album (ADT_Track_t *track, string *s)
{
	if(track==NULL || track->album==NULL) 
   	   return ERROR_NULL_POINTER;

	if((*s=strdupl(track->album))==NULL) 
  	   return ERROR_OUT_OF_MEMORY;

  	return OK;
}
/**********Final de función de obtención de album de Track***********/



/**********Comienzo de función de obtención de año de Track***********/
status_t ADT_Track_get_year (ADT_Track_t *track, string *s)
{
	if(track==NULL || track->year==NULL) 
   	   return ERROR_NULL_POINTER;

	if((*s=strdupl(track->year))==NULL) 
  	   return ERROR_OUT_OF_MEMORY;

  	return OK;
}
/**********Final de función de obtención de año de Track***********/




/**********Comienzo de función de obtención comentario de Track***********/
status_t ADT_Track_get_comment (ADT_Track_t *track, string *s)
{
	if(track==NULL || track->comment==NULL) 
   	   return ERROR_NULL_POINTER;

	if((*s=strdupl(track->comment))==NULL) 
  	   return ERROR_OUT_OF_MEMORY;

  	return OK;
}
/**********Final de función de obtención de comentario de Track***********/
