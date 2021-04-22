/********************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumnos: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: track_print.c
Descripción: Contiene funciones de impresión de Tracks.
********************************************************/

#include <stdio.h>
#include "track_print.h"
#include "types.h"
#include "track.h"
#include "vector.h"


extern status_t (*track_export[MAX_EXPORT])(const void *, FILE *);



status_t (*print_header_pf[MAX_EXPORT])(FILE *)= {
						  print_header_CSV,
						  print_header_XML 							
						 };

status_t (*print_footer_pf[MAX_EXPORT])(FILE *)= { 
						  print_footer_CSV,
						  print_footer_XML 							
					         };

/**************Comienzo de función de impresión de tracks*****************/
status_t print_tracks (const ADT_Vector_t *vector, format_t fmt, FILE *fo)
{
	status_t st;

  	if(vector==NULL || fo==NULL)
	   return ERROR_NULL_POINTER;

	if((st=print_header_pf[fmt](fo))!=OK)
	    return st;
	 
	if((st=ADT_Vector_export(vector,fo,track_export[fmt]))!=OK) 
  	    return st;

	if((st=print_footer_pf[fmt](fo))!=OK)
	    return st;

	return OK;
}
/**************Final de función de impresión de tracks*****************/



/**************Comienzo de función de impresión de header en CSV*****************/
status_t print_header_CSV(FILE *fo)
{
 	if(fo==NULL)
	   return ERROR_NULL_POINTER;

	return OK;
}
/**************Final de función de impresión de header en CSV*****************/



/**************Comienzo de función de impresión de footer en CSV*****************/
status_t print_footer_CSV(FILE *fo)
{
 	if(fo==NULL)
	   return ERROR_NULL_POINTER;

	return OK;
}
/**************Final de función de impresión de footer en CSV*****************/



/**************Comienzo de función de impresión de header en XML*****************/
status_t print_header_XML(FILE *fo)
{
 	if(fo==NULL)
	   return ERROR_NULL_POINTER;

	fprintf(fo,"%s\n",XML_VERSION_HEADER);

	fprintf(fo,"%c%s%c\n",'<',XML_LABEL_TRACKS,'>');

	return OK;
}
/**************Final de función de impresión de header en XML*****************/


/**************Comienzo de función de impresión de footer en XML*****************/
status_t print_footer_XML(FILE *fo)
{
 	if(fo==NULL)
	   return ERROR_NULL_POINTER;

	fprintf(fo,"%s%s%c\n","</",XML_LABEL_TRACKS,'>');

	return OK;
}
/**************Final de función de impresión de header en XML*****************/
