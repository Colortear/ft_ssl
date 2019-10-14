#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>
# include <stdarg.h>

size_t  ft_strlen(char *s);
void    putstr(char *s);
void    putstr_fd(char *s, int fd);
int     strcmp(char *s1, char *s2);
void    mini_printf(char *fmt, int arg_num, ...);

#endif
