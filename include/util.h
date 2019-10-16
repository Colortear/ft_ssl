#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>
# include <stdarg.h>

int     ft_strncpy(char *src, char *dest, size_t size);
size_t  ft_strlen(char *s);
void    ft_putstr(char *s);
void    ft_putstr_fd(char *s, int fd);
int     ft_strcmp(char *s1, char *s2);
void    mini_printf(char *fmt, int arg_num, ...);

#endif
