/*	****************************************************************************************
	Algoritmos y Programación I - 75.02/95.11 - Curso Ing. Martín Cardozo
	Archivo:     mp3reader.c
	Descripcion: Código de ejemplo para mostrar los datos del encabezado de un archivo MP3
	(c) Martín Cardozo
	**************************************************************************************** */


#include <stdio.h>
#include <string.h>


#define MP3_HEADER_SIZE		128


#define LEXEM_START_TAG     0
#define LEXEM_SPAN_TAG      3

#define LEXEM_START_TITLE   3
#define LEXEM_SPAN_TITLE   30

#define LEXEM_START_ARTIST 33
#define LEXEM_SPAN_ARTIST  30

#define LEXEM_START_ALBUM  63
#define LEXEM_SPAN_ALBUM   30

#define LEXEM_START_YEAR   93
#define LEXEM_SPAN_YEAR     4

#define LEXEM_START_COMMENT 97
#define LEXEM_SPAN_COMMENT  30

#define LEXEM_START_GENRE  127
#define LEXEM_SPAN_GENRE     1

typedef enum { OK, ERROR_NULL_POINTER } status_t;


status_t show_mp3_header (const char *, FILE *);

int main (void)
{
    FILE *f;
	size_t length;
    char header[MP3_HEADER_SIZE];


    if ((f = fopen("track.mp3","rb")) == NULL) {
        fprintf(stderr,"%s\n","No se pudo abrir el archivo.");
        return 1;
    }

    fseek(f, 0, SEEK_END);						/* manda el puntero al final del archivo 	*/
    length=ftell(f);							/* da la distancia al comienzo 				*/
    fseek(f,length-MP3_HEADER_SIZE,SEEK_SET);	/* se para en el header MP3 				*/

    fread(header,sizeof(char),MP3_HEADER_SIZE,f);

    show_mp3_header(header,stdout);

    fclose(f);
    return 0;
}





status_t show_mp3_header (const char header[], FILE * fo)
{
    char buf[MP3_HEADER_SIZE];

    if (header == NULL)
       return ERROR_NULL_POINTER;

    memcpy(buf,header+LEXEM_START_TAG,LEXEM_SPAN_TAG);
    buf[LEXEM_SPAN_TAG] = '\0';
    fprintf(fo,"%s%s\n","tag:",buf);

    memcpy(buf,header+LEXEM_START_TITLE,LEXEM_SPAN_TITLE);
    buf[LEXEM_SPAN_TITLE] = '\0';
    fprintf(fo,"%s%s\n","title:",buf);

    memcpy(buf,header+LEXEM_START_ARTIST,LEXEM_SPAN_ARTIST);
    buf[LEXEM_SPAN_ARTIST] = '\0';
    fprintf(fo,"%s%s\n","artist:",buf);

    memcpy(buf,header+LEXEM_START_ALBUM,LEXEM_SPAN_ALBUM);
    buf[LEXEM_SPAN_ALBUM] = '\0';
    fprintf(fo,"%s%s\n","album:",buf);

    memcpy(buf,header+LEXEM_START_YEAR,LEXEM_SPAN_YEAR);
    buf[LEXEM_SPAN_YEAR] = '\0';
    fprintf(fo,"%s%s\n","year:",buf);

    memcpy(buf,header+LEXEM_START_COMMENT,LEXEM_SPAN_COMMENT);
    buf[LEXEM_SPAN_COMMENT] = '\0';
    fprintf(fo,"%s%s\n","comment:",buf);

    memcpy(buf,header+LEXEM_START_GENRE,LEXEM_SPAN_GENRE);
    buf[LEXEM_SPAN_GENRE] = '\0';
    fprintf(fo,"%s%s\n","genre:",buf);

    return OK;
}


