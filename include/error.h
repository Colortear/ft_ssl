#ifndef ERROR_H
# define ERROR_H

# define ENOCMD 1
# define ENOINPUT 2

void    error_exit(int error_code, char *display);

#endif
