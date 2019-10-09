#include "../ft_ssl.h"
#include "../options.h"

int     main(int argc, char **argv)
{
    t_options   opt;
    t_ft_ssl    *ssl;

    get_options(argc, argv, &opt);
    ssl = create_entries(&opt);
    print_format(&ssl, has_option('r'));
    return 0;
}
