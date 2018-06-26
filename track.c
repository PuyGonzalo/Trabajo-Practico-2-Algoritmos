/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: track.c
Descripción: Contiene funciones de manejo de TDA Track.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "track.h"
#include "types.h"
#include "genres.c"



/**************Comienzo de función de creacion de Track*****************/
status_t ADT_Track_new(ADT_Track_t **track)
{
	if(track==NULL) 
	   return ERROR_NULL_POINTER;

        if((*track=(ADT_Track_t *)malloc(sizeof(ADT_Track_t)))==NULL) 
           return ERROR_OUT_OF_MEMORY;

	return OK;
}
/**************Final de función de creacion de Track*****************/



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

	strcpy(track->title,new_title);
 	track->title[LENGHT_TITLE-1]='\0';
        return OK;
}
/**********Final de función de seteo de título de Track***********/



/**********Comienzo de función de seteo de artista de Track***********/
status_t ADT_Track_set_artist(ADT_Track_t *track, string new_artist)
{
	if(track==NULL || new_artist==NULL) 
           return ERROR_NULL_POINTER;

	strcpy(track->artist,new_artist);
 	track->artist[LENGHT_ARTIST-1]='\0';
	return OK;
}
/**********Final de función de seteo de artista de Track***********/



/**********Comienzo de función de seteo de género de Track***********/
status_t ADT_Track_set_genre(ADT_Track_t *track, unsigned int new_genre)
{
	if(track==NULL) 
	   return ERROR_NULL_POINTER;

	track->genre=new_genre;

	return OK;
}
/**********Final de función de seteo de género de Track***********/



/**********Comienzo de función de seteo de album de Track***********/
status_t ADT_Track_set_album(ADT_Track_t *track, string new_album)
{
	if(track==NULL || new_album==NULL) 
           return ERROR_NULL_POINTER;

	strcpy(track->album,new_album);
 	track->album[LENGHT_ALBUM-1]='\0';

	return OK;
}
/**********Final de función de seteo de album de Track***********/



/**********Comienzo de función de seteo de año de Track***********/
status_t ADT_Track_set_year(ADT_Track_t *track, string new_year)
{
	if(track==NULL || new_year==NULL) 
           return ERROR_NULL_POINTER;

	strcpy(track->year,new_year);
 	track->year[LENGHT_YEAR-1]='\0';

	return OK;
}
/**********Final de función de seteo de año de Track***********/




/**********Comienzo de función de seteo de comentario de Track***********/
status_t ADT_Track_set_comment(ADT_Track_t *track, string new_comment)
{
	if(track==NULL || new_comment==NULL) 
           return ERROR_NULL_POINTER;

	strcpy(track->comment,new_comment);
 	track->comment[LENGHT_COMMENT-1]='\0';

	return OK;
}
/**********Final de función de seteo de comentario de Track***********/




/**********Comienzo de función de seteo de tag de Track***********/
status_t ADT_Track_set_tag (ADT_Track_t *track, string new_tag)
{
	if(track==NULL || new_tag==NULL) 
           return ERROR_NULL_POINTER;

	strcpy(track->tag,new_tag);
 	track->tag[LENGHT_TAG-1]='\0';
	return OK;
}
/**********Final de función de seteo de tag de Track***********/




/**************Comiezo de función de destruccion de Track************/
status_t ADT_Track_delete(void **track)
{

	if(track==NULL)
	   return ERROR_NULL_POINTER; 

	free(*track);
        track=NULL; 

	return OK;
}
/**************Final de función de destruccion de Track*****************/



/**************Comiezo de función de comparacion de Tracks por título************/
int ADT_Track_compare_by_title (const ADT_Track_t *a, const ADT_Track_t *b)
{
   return strcmp(a->title,b->title);
}
/**************Final de función de comparacion de Tracks por título************/



/**************Comiezo de función de comparacion de Tracks por artista************/
int ADT_Track_compare_by_artist (const ADT_Track_t *a, const ADT_Track_t *b)
{
   return strcmp(a->artist,b->artist);
}
/**************Final de función de comparacion de Tracks por artista************/



/**************Comiezo de función de comparacion de Tracks por género************/
int ADT_Track_compare_by_genre (const ADT_Track_t *a, const ADT_Track_t *b)
{
   return strcmp(genres_dictionary[a->genre],genres_dictionary[b->genre]);
}
/**************Final de función de comparacion de Tracks por género************/
