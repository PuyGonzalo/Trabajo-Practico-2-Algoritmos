/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: mp3.c
Descripción: Contiene funciones referidas a archivos mp3.
************************************************************************/



 status_t get_mp3_header (FILE *f,char *header)
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
