#include "../include/util.h"

void    ft_putstr(char *s)
{
    write(1, s, strlen(s));
}

void    ft_putstr_fd(char *s, int fd)
{
    write(fd, s, strlen(s));
}

void    mini_printf(char *fmt, int arg_num, ...)
{
    va_list ap;
    
    va_start(ap, arg_num);
    while (fmt != NULL && *fmt && arg_num)
    {
        if (*fmt == '%')
            putstr(va_arg(ap, char *));
        else
            write (1, fmt, 1);
        fmt++;
    }
    va_end(ap);
}
