#ifndef FT_SSL_H
# define FT_SSL_H

# include "options.h"

# define REVERSE

struct s_list {
    char            *input;
    char            *display_name;
    char            *processed_data;
    struct s_list   *next;
};

typedef struct      s_ft_ssl {
    char            *(*hash)(char *input);
    struct s_list   *entries;
}   t_ft_ssl;

t_ft_ssl    *create_entries(t_options *opt);
void        destroy_ft_ssl(t_ft_ssl *ssl);
void        process_data(struct s_list *list, char *(*hash)(char *input));

#endif /* FT_SSL_H */
