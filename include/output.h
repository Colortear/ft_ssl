#ifndef OUTPUT_H
# define OUTPUT_H

# include "ft_ssl.h"

void    print_format(t_ft_ssl *to_print, int is_reverse);
void    print_usage(void);
void    print_error(int error_code);

#endif
