#include <stdio.h>
#include "mp3.h"

int main (void)
{
	FILE * f;
	char * header;

	if((f=fopen("Es epico.mp3", "rb"))==NULL)
		return 1;

	get_mp3_header(f, &header);

	printf("%s\n", header );

	fclose(f);

	return 0;
}

 status_t get_mp3_header (FILE * f, char ** header)
{
	size_t length;
	char aux [MP3_HEADER_SIZE];

	if(f == NULL || header == NULL)
		return ERROR_NULL_POINTER;

	fseek(f, 0, SEEK_END);

	length=ftell(f);

	fseek(f,length-MP3_HEADER_SIZE, SEEK_SET);

	fread(aux, sizeof(char), MP3_HEADER_SIZE, f);

	(*header)= aux;

	return OK;
}