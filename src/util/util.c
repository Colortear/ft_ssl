#include "../include/util.h"

size_t  strlen(char *s)
{
    int ret;

    ret = 0;
    while (s[ret])
        ret++;
    return ret;
}

void    putstr(char *s)
{
    write(1, s, strlen(s));
}

void    putstr_fd(char *s, int fd)
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

int     strcmp(char *s1, char *s2)
{
    while (*s1 == *s2)
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
