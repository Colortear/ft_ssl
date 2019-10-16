#include <stdlib.h>

#include "../../include/error.h"
#include "../../include/util.h"

void    error_exit(int error_code, char *display)
{
    if (error_code == ENOCMD)
        print_invalid_cmd(display);
    exit(error_code);
}

void    print_invalid_cmd(char display)
{
    mini_printf("ft_ssl: Error: '%' is an invalid command.\n\n\
            Standard commands:\n\nMessage Digest Commands:\n\
            md5\nsha256\n\nCipher commands:\n", display);
}
