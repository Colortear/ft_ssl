#include "../include/ft_ssl.h"

static void     init_t_options(t_options *opt)
{
    int i;

    i = 0;
    while (i < OPT_TABLE_SIZE/sizeof(int))
    {
        opt->opt_takes_arg[i] = 0;
        opt->opt_table[i] = 0;
        opt->args[i] = NULL;
    }
    opt->opt_takes_arg[STRING] = 1;
    opt->input_list = NULL;
}

static int      is_valid_option(char *s, int *table)
{
    return s != NULL && s[0] && s[1] && s[0] == '-';
}

void            add_options(char *s, int *table)
{
    while (*s)
        table[*s % 26] = 1;
}


void            get_options(int argc, char **args, t_options *opt)
{
    int i;
    int take_as_arg;
    int index;

    i = 0;
    take_as_arg = 0;
    init_t_options(opt);
    while (i < argc)
    {
        if (take_as_arg)
        {
            if (!args[index])
                append_input_list_node(&opt->args[index], create_node(args[i]));
            take_as_arg = 0;
        }
        else if (is_valid_option(args[i], opt->opt_table))
        {
            index = args[i][1] % OPT_TABLE_SIZE;
            add_options(args[i], opt->opt_table);
            if (opt->opt_takes_arg[index])
                take_as_arg = args[i][1];
        }
        else
            append_input_list_node(&opt->input_list, create_node(args[i]));
    }
}

int             has_option(char option, t_options *opt)
{
    return opt->opt_table[option];
}
