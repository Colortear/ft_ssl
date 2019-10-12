#include "../include/ft_ssl.h"
#include "../include/output.h"

int     main(int argc, char **argv)
{
    t_options   opt;
    t_ft_ssl    *ssl;

    get_options(argc, argv, &opt);
    ssl = create_entries(&opt);
    process_data(ssl->entries, ssl->hash);
    print_format(ssl, has_option('r', &opt));
    destroy_ft_ssl(ssl);
    destroy_input_list(opt.input_list);
    return 0;
}
