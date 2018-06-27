/*************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumnos: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: mp3.c
Descripción: Contiene funciones referidas a archivos mp3.
*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "mp3.h"
#include "track.h"
#include "vector.h"



/*******Comienzo de función de carga de tracks MP3 en vector********/
status_t process_mp3_file (FILE *fi, ADT_Track_t **track)
{
	char header[MP3_HEADER_SIZE];
	status_t st;

	if(fi==NULL || track==NULL)
	   return ERROR_NULL_POINTER;

	if((st=get_mp3_header(fi,header))!=OK)
	   return st;

	if((st=ADT_Track_new(track))!=OK)
           return st;

	if((st=set_track_from_mp3_header(header, *track))!=OK)
	{
           ADT_Track_delete((void*)&track);
	   return st;
	}

	return OK;
}
/*********Final de función de carga de tracks MP3 en vector*********/



/******Comienzo de función de obtencion de encabezado de track MP3*****/
 status_t get_mp3_header (FILE * fi, string header)
{
	size_t length;

	if(fi==NULL || header==NULL)
	   return ERROR_NULL_POINTER;

	fseek(fi,0,SEEK_END);

	length=ftell(fi);

	fseek(fi,length-MP3_HEADER_SIZE,SEEK_SET);

	fread(header,sizeof(char),MP3_HEADER_SIZE,fi);

	return OK;
}
/*******Final de función de obtencion de encabezado de track MP3*******/



/************Comienzo de función de seteo de campos de track MP3**************/
status_t set_track_from_mp3_header (const string header, ADT_Track_t *track)
{
	status_t st;
	char aux[LEXEM_SPAN_GENRE];

	if(header==NULL || track==NULL)
	   return ERROR_NULL_POINTER;

	if((st=ADT_Track_set_tag(track,header+LEXEM_START_TAG))!=OK)
	   return st;

	if((st=ADT_Track_set_title(track,header+LEXEM_START_TITLE))!=OK)
	   return st;

	if((st=ADT_Track_set_artist(track,header+LEXEM_START_ARTIST))!=OK)
    	   return st;

	if((st=ADT_Track_set_album(track,header+LEXEM_START_ALBUM))!=OK)
           return st;

	if((st=ADT_Track_set_year(track,header+LEXEM_START_YEAR))!=OK)
           return st;

	if((st=ADT_Track_set_comment(track,header+LEXEM_START_COMMENT))!=OK)
    	   return st;

	memcpy(aux,header+LEXEM_START_GENRE,LEXEM_SPAN_GENRE);
	if((st=ADT_Track_set_genre(track,aux[0]))!=OK)
     	   return st;

	return OK;
}
/**************Final de función de seteo de campos de track MP3***************/
