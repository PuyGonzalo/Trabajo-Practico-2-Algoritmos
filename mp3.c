#include <stdio.h>
#include "MP3.h"

char * get_mp3_header (FILE * f)
{
	size_t length;
	char header [MP3_HEADER_SIZE];
	
	if( f == NULL)
		return ERROR_NULL_POINTER;

	fseek(f, 0, SEEK_END);

	length=ftell(f);

	fseek(f,length-MP3_HEADER_SIZE, SEEK_SET);

	fread(header, sizeof(char), MP3_HEADER_SIZE, f);

	return header;
}
