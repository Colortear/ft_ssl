#include "../include/options.h"

static void    init_t_options(t_options *opt)
{
    int i;

    i = 0;
    while (i < OPT_TABLE_SIZE/sizeof(int))
    {
        opt->opt_takes_arg[i] = 0;
        opt->opt_table[i] = 0;
        opt->args[i] = NULL;
    }
    opt->input_list = NULL;
}

static int     is_valid_option(char *s, char *table)
{
    return s != NULL && s[0] && s[1] && s[0] == '-' && table[s[1]];
}

void    get_options(int argc, char **args, t_options *opt)
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
                args[index] = argv[i];
            take_as_arg = 0;
        }
        else if (is_valid_option(argv[i]))
        {
            index = argv[i][1] % OPT_TABLE_SIZE;
            opt->table[argv[i][1]] = 1;
            if (opt->opt_takes_arg[index])
                take_as_arg = argv[i][1];
        }
        else
            append_input_list_node(create_input_node(argv[i]));
    }
}

int     has_option(char option, t_options *opt)
{
    return opt->opt_table[option % OPT_TABLE_SIZE];
}
