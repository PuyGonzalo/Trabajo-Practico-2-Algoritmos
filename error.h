#ifndef ERROR__H
#define ERROR__H

#include <stdio.h>
#include "types.h"

status_t print_error (FILE * f, status_t st);

#define MAX_ERRORS  /* FALTA AGREGAR EL NUMERO DE ERRORES FINAL */

#endif
