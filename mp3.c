/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: mp3.c
Descripción: Contiene funciones referidas a archivos mp3.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "mp3.h"
#include "track.h"
#include "vector.h"



/***********Comienzo de función de carga de tracks MP3 en vector**************/
status_t load_track_mp3_on_vector (FILE *fi, ADT_Vector_t *p)
{
	char header[MP3_HEADER_SIZE];
	ADT_Track_t *track;
	status_t st;

	if(fi==NULL || p==NULL)
	   return ERROR_NULL_POINTER;

	if((st=get_mp3_header(fi,header))!=OK)
	   return st;

	if((st=set_track_from_mp3_header(header, &track))!= OK)
	{
           ADT_Track_delete((void*)&track);
	   return st;
	}

	if((st=ADT_Vector_append(p,track))!=OK)
	{
	   ADT_Track_delete((void*)&track);
	   return st;
	}

	return OK;
}
/*************Final de función de carga de tracks MP3 en vector***************/



/******Comienzo de función de obtencion de encabezado de track MP3******/
 status_t get_mp3_header (FILE * f, string header)
{
	size_t length;

	if(f==NULL || header==NULL)
	   return ERROR_NULL_POINTER;

	fseek(f,0,SEEK_END);

	length=ftell(f);

	fseek(f,length-MP3_HEADER_SIZE,SEEK_SET);

	fread(header,sizeof(char),MP3_HEADER_SIZE,f);

	return OK;
}
/********Final de función de obtencion de encabezado de track MP3********/



/************Comienzo de función de seteo de campos de track MP3**************/
status_t set_track_from_mp3_header (const char header[], ADT_Track_t **track)
{
	char buf[MP3_HEADER_SIZE];
	status_t st;
	unsigned int n;

	if (header==NULL || track==NULL)
	    return ERROR_NULL_POINTER;

	if((st=ADT_Track_new(track))!=OK)
           return st;

	memcpy(buf,header+LEXEM_START_TAG,LEXEM_SPAN_TAG);
	buf[LEXEM_SPAN_TAG] = '\0';
	if((st=ADT_Track_set_tag(*track,buf))!=OK)
	   return st;

	memcpy(buf,header+LEXEM_START_TITLE,LEXEM_SPAN_TITLE);
	buf[LEXEM_SPAN_TITLE] = '\0';
	if((st=ADT_Track_set_title(*track,buf))!=OK)
	   return st;

	memcpy(buf,header+LEXEM_START_ARTIST,LEXEM_SPAN_ARTIST);
	buf[LEXEM_SPAN_ARTIST] = '\0';
	if((st=ADT_Track_set_artist(*track,buf))!=OK)
    	   return st;

	memcpy(buf,header+LEXEM_START_ALBUM,LEXEM_SPAN_ALBUM);
	buf[LEXEM_SPAN_ALBUM] = '\0';
	if((st=ADT_Track_set_album(*track,buf))!=OK)
           return st;

	memcpy(buf,header+LEXEM_START_YEAR,LEXEM_SPAN_YEAR);
	buf[LEXEM_SPAN_YEAR] = '\0';
	if((st=ADT_Track_set_year(*track,buf))!=OK)
           return st;

	memcpy(buf,header+LEXEM_START_COMMENT,LEXEM_SPAN_COMMENT);
	buf[LEXEM_SPAN_COMMENT] = '\0';
	if((st=ADT_Track_set_comment(*track,buf)) != OK)
    	   return st;

	memcpy(&n,header+LEXEM_START_GENRE,LEXEM_SPAN_GENRE);
	n=n&MASK_GENRE;
	if((st=ADT_Track_set_genre(*track,n))!=OK)
     	   return st;

	return OK;
}
/************Final de función de seteo de campos de track MP3**************/
