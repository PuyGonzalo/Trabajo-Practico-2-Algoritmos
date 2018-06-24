#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "types.h"


status_t ADT_Vector_export_as_CSV (const ADT_vector_t * p, FILE * fo, char delimitter, status_t (*pf)(const void *, FILE *, char))
{
	size_t i;
	status_t st;

	if (p == NULL || fo == NULL || pf == NULL)
		return ERROR_NULL_POINTER;

	for (i=0 ; i < size ; i++)
	{
		st= (*pf)(p-> elements[i],delimitter, fo);
		
		if (st != OK)
			return st;
	}

	return OK;
}
