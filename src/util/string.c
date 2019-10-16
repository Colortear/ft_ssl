#include "../../include/util.h"

int     ft_strcmp(char *s1, char *s2)
{
    while (*s1 == *s2)
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

size_t  ft_strlen(char *s)
{
    int ret;

    ret = 0;
    while (s[ret])
        ret++;
    return ret;
}

int     ft_strncpy(char *src, char *dest, size_t size)
{
    size_t  i;

    i = 0;
    if (src != NULL)
    {
        while (src[i] && i < size)
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = 0;
    }
    return i;
}
