#ifndef FT_SSL_H
# define FT_SSL_H

struct s_list {
    char            *input;
    char            *display_name;
    char            *check_sum;
    struct s_list   *next;
};

typedef struct      s_ft_ssl {
    char            *(*hash)(char *input);
    struct s_list   *entries;
}   t_ft_ssl;

t_ft_ssl    *create_entries(const t_options const *opt);
void        destroy_ft_ssl(t_ft_ssl *ssl);

#endif /* FT_SSL_H */
