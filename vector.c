/***********************************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumno: Reigada, Maximiliano Daniel
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

	if(((*p)->data=(void **)malloc(ADT_VECTOR_INIT_CHOP*sizeof(void *)))==NULL)
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
            (*p)->destructor((*p)->data[i]); 
            (*p)->data[i]=NULL;
        }

        free((*p)->data);
	(*p)->data=NULL;

        free(*p);
        *p=NULL;

	return OK;
}
/***************Final de función de destrucción de vector*****************/



/**********Comienzo de función de seteo de destructor de vector***********/
status_t ADT_Vector_Set_destructor (ADT_Vector_t *p, destructor_t pf)
{
   if(p==NULL || pf==NULL) 
      return ERROR_NULL_POINTER;

   p->destructor=pf;

   return OK;
}
/***********Final de función de seteo de destructor de vector*************/



/*******************Comienzo de función de adjunción de vector**********************/
status_t ADT_Vector_append (ADT_Vector_t *p, void *new_data)
{
   void **aux;
   if(p==NULL) 
      return ERROR_NULL_POINTER;

   if(p->size==p->alloc_size)
   {
      if((aux=(void **)realloc(p->data,(p->alloc_size+ADT_VECTOR_INIT_CHOP)*sizeof(void*)))==NULL)
         return ERROR_OUT_OF_MEMORY;

      p->alloc_size+=ADT_VECTOR_INIT_CHOP;
      p->data=aux;
   }

   p->data[(p->size)++] = new_data;

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

        return p->data[position];
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
            if((st=v->printer(v->data[i], fo))!=OK) 
               return st;
 
        return OK;
}
/*****************Final de función de impresión de vector*****************/



/****************Comienzo de seteo de impresión de vector*****************/
status_t ADT_Vector_set_printer (ADT_Vector_t *v, Vector_printer_t pf)
{
   if (v==NULL || pf==NULL) 
      return ERROR_NULL_POINTER;

   v->printer=pf;

   return OK;
}
/************Final de función de seteo de impresión de vector*************/
