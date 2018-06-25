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
#include <string.h>
#include "types.h"
#include "track.h"
#include "mp3.h"

 status_t get_mp3_header (FILE * f, string header)
{
	size_t length;

	if(f == NULL || header == NULL)
		return ERROR_NULL_POINTER;

	fseek(f, 0, SEEK_END);

	length=ftell(f);

	fseek(f,length-MP3_HEADER_SIZE, SEEK_SET);

	fread(header, sizeof(char), MP3_HEADER_SIZE, f);

	return OK;
}

status_t set_fields_from_mp3_header (const char header[], ADT_Track_t * track)
{
	char buf[MP3_HEADER_SIZE];
	status_t st;

	if (header == NULL || track == NULL)
		return ERROR_NULL_POINTER;


	memcpy(buf,header+LEXEM_START_TAG,LEXEM_SPAN_TAG);
    buf[LEXEM_SPAN_TAG] = '\0';
    if((st=ADT_Track_set_tag(track,buf)) != OK)
    {
    	ADT_Track_delete(track);
    	return st;
    }

    memcpy(buf,header+LEXEM_START_TITLE,LEXEM_SPAN_TITLE);
    buf[LEXEM_SPAN_TITLE] = '\0';
    if((st=ADT_Track_set_title(track,buf)) != OK)
    {
    	ADT_Track_delete(track);
    	return st;
    }

    memcpy(buf,header+LEXEM_START_ARTIST,LEXEM_SPAN_ARTIST);
    buf[LEXEM_SPAN_ARTIST] = '\0';
    if((st=ADT_Track_set_artist(track,buf)) != OK)
    {
    	ADT_Track_delete(track);
    	return st;
    }

    memcpy(buf,header+LEXEM_START_ALBUM,LEXEM_SPAN_ALBUM);
    buf[LEXEM_SPAN_ALBUM] = '\0';
    if((st=ADT_Track_set_album(track,buf)) != OK)
    {
    	ADT_Track_delete(track);
    	return st;
    }

    memcpy(buf,header+LEXEM_START_YEAR,LEXEM_SPAN_YEAR);
    buf[LEXEM_SPAN_YEAR] = '\0';
    if((st=ADT_Track_set_year(track,buf)) != OK)
    {
    	ADT_Track_delete(track);
    	return st;
    }

    memcpy(buf,header+LEXEM_START_COMMENT,LEXEM_SPAN_COMMENT);
    buf[LEXEM_SPAN_COMMENT] = '\0';
    if((st=ADT_Track_set_comment(track,buf)) != OK)
    {
    	ADT_Track_delete(track);
    	return st;
    }

    memcpy(buf,header+LEXEM_START_GENRE,LEXEM_SPAN_GENRE);
    buf[LEXEM_SPAN_GENRE] = '\0';
    if((st=ADT_Track_set_genre(track,buf)) != OK)
    {
    	ADT_Track_delete(track);
    	return st;
    }

    return OK;
}