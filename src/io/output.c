#include "../include/output.h"

void    print_usage(void)
{
    ft_putstr("usage: ft_ssl command [command opt] [command args]");
}

void    print_format(t_ft_ssl *to_print, int is_reverse)
{
    if (to_print->to_display)
        ft_putstring(to_print->to_display);
    while
