#include "../include/util.h"

size_t  strlen(char *s)
{
    int ret;

    ret = 0;
    while (s++)
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
