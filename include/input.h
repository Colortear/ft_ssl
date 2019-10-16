#ifndef INPUT_H
# define INPUT_H

# include <fcntl.h>
# include <unistd.h>

# define BUF_SIZE 1024

typedef struct      s_input
{
    char            *input;
    int             size;
    struct s_input  *next;
}                   t_input;

char    *read_from_file(char *file_name);
char    *read_stdin(void);

#endif
