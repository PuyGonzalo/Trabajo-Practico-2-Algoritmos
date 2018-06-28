/********************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumnos: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: track.c
Descripción: Contiene funciones de manejo de TDA Track.
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "track.h"
#include "types.h"
#include "genres.c"


/**************Comienzo de función de creación de Track***************/
status_t ADT_Track_new(ADT_Track_t **track)
{
	if(track==NULL) 
	   return ERROR_NULL_POINTER;

        if((*track=(ADT_Track_t *)malloc(sizeof(ADT_Track_t)))==NULL) 
           return ERROR_OUT_OF_MEMORY;

	return OK;
}
/**************Final de función de creación de Track*****************/



/******Comiezo de función de destruccion de Track*******/
status_t ADT_Track_delete(void **track)
{

	if(track==NULL)
	   return ERROR_NULL_POINTER; 

	free(*track);
        *track=NULL; 

	return OK;
}
/******Final de función de destruccion de Track*********/



/***********Comienzo de función de seteo de título de Track*************/
status_t ADT_Track_set_title(ADT_Track_t *track, const string new_title)
{
	if(track==NULL || new_title==NULL) 
           return ERROR_NULL_POINTER;

	strcpy(track->title,new_title);
 	track->title[TITLE_FIELD_LENGHT]='\0';
        return OK;
}
/*************Final de función de seteo de título de Track**************/



/**************Comienzo de función de seteo de artista de Track*************/
status_t ADT_Track_set_artist(ADT_Track_t *track, const string new_artist)
{
	if(track==NULL || new_artist==NULL) 
           return ERROR_NULL_POINTER;

	strcpy(track->artist,new_artist);
 	track->artist[ARTIST_FIELD_LENGHT]='\0';
	return OK;
}
/**************Final de función de seteo de artista de Track***************/



/*************Comienzo de función de seteo de género de Track*************/
status_t ADT_Track_set_genre(ADT_Track_t *track, unsigned int new_genre)
{
	if(track==NULL) 
	   return ERROR_NULL_POINTER;

	track->genre=new_genre;

	return OK;
}
/*************Final de función de seteo de género de Track****************/



/*************Comienzo de función de seteo de album de Track**************/
status_t ADT_Track_set_album(ADT_Track_t *track, const string new_album)
{
	if(track==NULL || new_album==NULL) 
           return ERROR_NULL_POINTER;

	strcpy(track->album,new_album);
 	track->album[ALBUM_FIELD_LENGHT]='\0';

	return OK;
}
/**************Final de función de seteo de album de Track****************/



/***************Comienzo de función de seteo de año de Track**************/
status_t ADT_Track_set_year(ADT_Track_t *track, const string new_year)
{
	if(track==NULL || new_year==NULL) 
           return ERROR_NULL_POINTER;

	strcpy(track->year,new_year);
 	track->year[YEAR_FIELD_LENGHT]='\0';

	return OK;
}
/***************Final de función de seteo de año de Track****************/




/**************Comienzo de función de seteo de comentario de Track************/
status_t ADT_Track_set_comment(ADT_Track_t *track, const string new_comment)
{
	if(track==NULL || new_comment==NULL) 
           return ERROR_NULL_POINTER;

	strcpy(track->comment,new_comment);
 	track->comment[COMMENT_FIELD_LENGHT]='\0';

	return OK;
}
/***************Final de función de seteo de comentario de Track*************/




/************Comienzo de función de seteo de tag de Track************/
status_t ADT_Track_set_tag (ADT_Track_t *track, const string new_tag)
{
	if(track==NULL || new_tag==NULL) 
           return ERROR_NULL_POINTER;

	strcpy(track->tag,new_tag);
 	track->tag[TAG_FIELD_LENGHT]='\0';
	return OK;
}
/**************Final de función de seteo de tag de Track************/



/*******Comiezo de función de comparación de Tracks por título*******/
int ADT_Track_compare_by_title (const void *pv1, const void *pv2)
{
   ADT_Track_t *track_1 =(ADT_Track_t *)pv1;    
   ADT_Track_t *track_2 =(ADT_Track_t *)pv2;

   return strcmp(track_1->title,track_2->title);
}
/*******Final de función de comparación de Tracks por título*********/



/******Comienzo de función de comparación de Tracks por artista******/
int ADT_Track_compare_by_artist (const void *pv1, const void *pv2)
{
   ADT_Track_t *track_1 =(ADT_Track_t *)pv1;    
   ADT_Track_t *track_2 =(ADT_Track_t *)pv2;    

   return strcmp(track_1->artist,track_2->artist);
}
/*******Final de función de comparación de Tracks por artista*******/



/****************Comienzo de función de comparación de Tracks por género*****************/
int ADT_Track_compare_by_genre (const void *pv1, const void *pv2)
{
   ADT_Track_t *track_1 =(ADT_Track_t *)pv1;    
   ADT_Track_t *track_2 =(ADT_Track_t *)pv2;

   return strcmp(genres_dictionary[track_1->genre],genres_dictionary[track_2->genre]);
}
/****************Final de función de comparación de Tracks por género******************/



/*********************Comienzo de función de exportado de Tracks a CSV*****************/
status_t ADT_Track_export_as_CSV (const void * pv, const void *delimitter, FILE * fo)
{
	ADT_Track_t *track=(ADT_Track_t *)pv;

	if(fo==NULL || pv==NULL)
	   return ERROR_NULL_POINTER;

	fprintf(fo,"%s",track->title);
	fprintf(fo,"%c",*((char *)delimitter));
	fprintf(fo,"%s",track->artist);
	fprintf(fo,"%c",*((char *)delimitter));
	fprintf(fo,"%s\n",genres_dictionary[track->genre]);

	return OK;
}
/**********************Final de función de exportado de Tracks a CSV******************/



/******************Comiezo de función de exportado de Tracks a XML****************/
status_t ADT_Track_export_as_XML (const void * pv,const void *context, FILE * fo)
{
	ADT_Track_t *track=(ADT_Track_t *)pv;

	if(fo==NULL || pv==NULL)
	   return ERROR_NULL_POINTER;

	fprintf(fo,"\t%c%s%c\n",'<',XML_LABEL_TRACK,'>');

	fprintf(fo,"\t\t%c%s%c",'<',XML_LABEL_NAME,'>');
	fprintf(fo,"%s",track->title);
	fprintf(fo,"%s%s%c\n","</",XML_LABEL_NAME,'>');

	fprintf(fo,"\t\t%c%s%c",'<',XML_LABEL_ARTIST,'>');
	fprintf(fo,"%s",track->artist);
	fprintf(fo,"%s%s%c\n","</",XML_LABEL_ARTIST,'>');


	fprintf(fo,"\t\t%c%s%c",'<',XML_LABEL_GENRE,'>');
	fprintf(fo,"%s",genres_dictionary[track->genre]);
	fprintf(fo,"%s%s%c\n","</",XML_LABEL_GENRE,'>');

	fprintf(fo,"\t%s%s%c\n","</",XML_LABEL_TRACK,'>');

	return OK;
}
/******************Final de función de exportado de Tracks a XML****************/



/***Las siguientes funciones no fueron implementadas en el programa****/


/******Comienzo de función de impresión de Track**********/
status_t ADT_Track_print(ADT_Track_t *track, FILE *fo)
{
	status_t st;

	if(track==NULL || fo==NULL) 
	   return ERROR_NULL_POINTER;

	if((st=track->printer(track,fo))!=OK) 
           return st;

	return OK;
}
/********Final de función de impresión de Track**********/



/********Comienzo de función de seteo de impresión de Track*************/
status_t ADT_Track_set_printer(ADT_Track_t *track, Track_printer_t pf)
{
	if(track==NULL || pf==NULL) 
           return ERROR_NULL_POINTER;

	track->printer = pf;

	return OK;
}
/********Final de función de seteo de impresión de Track****************/
