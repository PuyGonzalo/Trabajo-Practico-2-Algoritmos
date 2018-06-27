/*********************************************************
Facultad de Ingeniería
Universidad de Buenos Aires
Algoritmos y programacion I (95.11)
Profesor: Ing. Martín Cardozo
Alumnos: Puy, Gonzalo - Reigada, Maximiliano Daniel
Archivo: vector.c
Descripción: Contiene funciones de manejo de TDA Vector.
*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "types.h"	


/***********************Comienzo de función de creación de vector*********************/
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
/***********************Final de función de creación de vector*************************/



/*****Comienzo de función de destrucción de vector******/
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
/******Final de función de destrucción de vector*******/



/********Comienzo de función de seteo de destructor de vector*********/
status_t ADT_Vector_set_destructor (ADT_Vector_t *p, destructor_t pf)
{
   if(p==NULL || pf==NULL) 
      return ERROR_NULL_POINTER;

   p->destructor=pf;

   return OK;
}
/**********Final de función de seteo de destructor de vector**********/



/********************************Comienzo de función de adjunción de vector********************************/
status_t ADT_Vector_append (ADT_Vector_t *v, void *new_element)
{
   void **aux;
   if(v==NULL) 
      return ERROR_NULL_POINTER;

   if(v->size==v->alloc_size)
   {
      if((aux=(void **)realloc(v->element,(v->alloc_size+ADT_VECTOR_INIT_CHOP)*sizeof(void*)))==NULL)
         return ERROR_OUT_OF_MEMORY;

      v->alloc_size+=ADT_VECTOR_INIT_CHOP;
      v->element=aux;
   }

   v->element[(v->size)++]=new_element;
	
   return OK;
}
/********************************Final de función de adjunción de vector***********************************/



/**************Comienzo de función de ordenamieto de vector*************/
status_t ADT_Vector_sort(ADT_Vector_t *v,compare_t pf)
{
	size_t i;
	size_t j;

	if(v==NULL || pf==NULL)
	   return ERROR_NULL_POINTER;

	for(i=0;i<v->size-1;i++)
    {
	    for(j=0;j<(v->size-1)-i;j++)
	    {
	        if(pf(v->element[j],v->element[j+1])>0)    
                   ADT_Vector_swap_element(&(v->element[j]),&(v->element[j+1]));
        }
    }

	return OK;
}
/**************Final de función de ordenamieto de vector**************/



/*******************Comienzo de función de cambio de elemento de vector*******************/
status_t ADT_Vector_swap_element(void **element_a,void**element_b)
{
	void *aux;
 
 	aux=*element_a;
	*element_a=*element_b;
    *element_b=aux;  

	return OK;
}
/********************Final de función de cambio de elemento de vector********************/



/*********************Comienzo de función de exportado de vector a CSV*******************************/
status_t ADT_Vector_export_as_CSV (const ADT_Vector_t *p, FILE * fo, char delimiter, printer_t pf)
{
	size_t i;
	status_t st;

	if(p==NULL || fo==NULL || pf==NULL)
	   return ERROR_NULL_POINTER;

	for(i=0;i<p->size;i++)
	{
        if((st=pf(p->element[i],&delimiter,fo))!=OK)
		    return st;
	}

	return OK;
}
/**************************Final de función de exportado de vector a CSV*****************************/



/*******************************Comienzo de función de exportado de vector a XML****************************************/
status_t ADT_Vector_export_as_XML(const ADT_Vector_t *p, FILE *fo,const string header,const string footer, printer_t pf)
{
        size_t i;
	status_t st;

	if(p==NULL || fo==NULL)
	   return ERROR_NULL_POINTER;

	fprintf(fo,"%s\n",ADT_VECTOR_XML_HEADER);
	fprintf(fo,"%c%s%c\n",'<',header,'>');

	for(i=0;i<p->size;i++)
	{
        if((st=pf(p->element[i],NULL,fo))!=OK)
	       return st;
	}

	fprintf(fo,"%s%s%c\n","</",footer,'>');

    return OK;
}
/***********************************Final de función de exportado de vector a XML***************************************/
