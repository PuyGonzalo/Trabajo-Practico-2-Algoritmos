/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: vector.c
Descripción: Contiene funciones de manejo de TDA Vector.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "types.h"
#include "vector.h"


/**************Comienzo de función de creacion de vector*****************/
status_t ADT_Vector_new (ADT_Vector_t **p)
{
	if(p==NULL) 
	   return ERROR_NULL_POINTER;

	if((*p=(ADT_Vector_t *)malloc(sizeof(ADT_Vector_t)))==NULL)
           return ERROR_OUT_OF_MEMORY;

	if(((*p)->element=(void **)malloc(ADT_VECTOR_INIT_CHOP*sizeof(void *)))==NULL)
	{
	   free(*p);
	   *p=NULL;
      	   return ERROR_OUT_OF_MEMORY;
	}

	(*p)->alloc_size=ADT_VECTOR_INIT_CHOP;
	(*p)->size = 0;

	return OK;
}
/****************Final de función de creacion de vector*****************/



/*************Comienzo de función de destrucción de vector**************/
status_t ADT_Vector_delete (ADT_Vector_t **p)
{
	size_t i;

	if(p==NULL)
	   return ERROR_NULL_POINTER;

        for(i=0; i<(*p)->size; i++)
        {
            (*p)->destructor(&((*p)->element[i])); 
            (*p)->element[i]=NULL;
        }

        free((*p)->element);
	(*p)->element=NULL;

        free(*p);
        *p=NULL;

	return OK;
}
/***************Final de función de destrucción de vector*****************/



/**********Comienzo de función de seteo de destructor de vector***********/
status_t ADT_Vector_set_destructor (ADT_Vector_t *p, destructor_t pf)
{
   if(p==NULL || pf==NULL) 
      return ERROR_NULL_POINTER;

   p->destructor=pf;

   return OK;
}
/***********Final de función de seteo de destructor de vector*************/



/*******************Comienzo de función de adjunción de vector**********************/
status_t ADT_Vector_append (ADT_Vector_t *p, void *new_element)
{
   void **aux;
   if(p==NULL) 
      return ERROR_NULL_POINTER;

   if(p->size==p->alloc_size)
   {
      if((aux=(void **)realloc(p->element,(p->alloc_size+ADT_VECTOR_INIT_CHOP)*sizeof(void*)))==NULL)
         return ERROR_OUT_OF_MEMORY;

      p->alloc_size+=ADT_VECTOR_INIT_CHOP;
      p->element=aux;
   }

   p->element[(p->size)++]=new_element;

   return OK;
}
/*********************Final de función de adjunción de vector**********************/



/**************Comienzo de función de obtención de elemento***************/
void * ADT_Vector_get_element (const ADT_Vector_t *p, size_t position)
{
	if(p==NULL) 
           return NULL;

	if(position>p->size) 
           return NULL;

        return p->element[position];
}
/***************Final de función de obtención de elemento****************/



/**********Comienzo de función de obtención de tamaño de vector**********/
size_t ADT_Vector_get_size (ADT_Vector_t *p)
{
   return p->size;
}
/*************Final de función de obtención de tamaño de vector**********/



/**************Comienzo de función de impresión de vector****************/
status_t ADT_Vector_Print (ADT_Vector_t *v, FILE *fo)
{
	size_t i;
        status_t st;

	if(v==NULL || fo==NULL) 
	   return ERROR_NULL_POINTER;

        for(i=0;i<v->size;i++)
            if((st=v->printer(v->element[i], fo))!=OK) 
               return st;
 
        return OK;
}
/*****************Final de función de impresión de vector*****************/



/****************Comienzo de función de seteo de impresión de vector*****************/
status_t ADT_Vector_set_printer (ADT_Vector_t *v, Vector_printer_t pf)
{
   if (v==NULL || pf==NULL) 
      return ERROR_NULL_POINTER;

   v->printer=pf;

   return OK;
}
/************Final de función de seteo de impresión de vector*************/


/***************************************Comienzo de función de exportado de vector a CSV**************************************************/
/*status_t ADT_Vector_export_as_CSV (const ADT_Vector_t * p, FILE * fo, char delimitter, status_t (*pf)(const void *, FILE *, char))
{
	size_t i;
	status_t st;

	if (p==NULL || fo==NULL || pf==NULL)
		return ERROR_NULL_POINTER;

	for (i=0;i<p->size;i++)
	{
		if((st=(*pf)(p->element[i],delimitter, fo))!=OK)
	           return st;
	}

	return OK;
}*/
/***************************************Final de función de exportado de vector a CSV**************************************************/

