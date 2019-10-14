#include "../include/ft_ssl.h"
#include "../include/output.h"
#include "../include/error.h"

static void validate_command(char **args, int argc)
{
    if (!args || argc < 2)
    {
        putstr("Error: command not found");
        exit(1);
    }
    else if (strcmp(args[1], MD5) && strcmp(args[1], SHA256))
        error_exit(ENOCMD, args[1]);
}

int     main(int argc, char **argv)
{
    t_options   opt;
    t_ft_ssl    *ssl;

    get_options(argc, argv, &opt);
    if ((ssl = create_entries(&opt)) == NULL)
        error_exit(ENOINPUT, "");
    process_data(ssl->entries, ssl->hash);
    print_format(ssl, has_option('r', &opt));
    destroy_ft_ssl(ssl);
    destroy_input_list(opt.input_list);
    return 0;
}
