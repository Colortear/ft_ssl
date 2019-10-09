#ifndef INPUT_H
# define INPUT_H

# include <fcntl.h>
# include <unistd.h>

char    *read_from_file(char *file_name);
char    *read_stdin(void);

#endif
