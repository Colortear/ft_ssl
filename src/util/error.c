#include <stdlib.h>

#include "../../include/error.h"
#include "../../include/util.h"

void    error_exit(int error_code, char *display)
{
    if (error_code == ENOCMD)
        mini_printf("Error: % is not a valid command.", 1, display);
    exit(error_code);
}
