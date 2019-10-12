#ifndef OPTIONS_H
# define OPTIONS_H

# include "util.h"

#define OPT_TABLE_SIZE 26

struct s_input_list {
    char                *input;
    struct s_input_list *next;
};

typedef struct s_options {
    int                 opt_takes_arg[OPT_TABLE_SIZE];
    int                 opt_table[OPT_TABLE_SIZE];
    struct s_input_list *args[OPT_TABLE_SIZE];
    struct s_input_list *input_list;
} t_options;

int                 has_option(char option, t_options *opt);
void                get_options(int argc, char **args, t_options *opt);

void                destroy_input_list(struct s_input_list *list);
struct s_input_list *create_input_node(char *entry);
void                append_input_list_node(struct s_input_list **list
                                            struct s_input_list *append);

#endif
