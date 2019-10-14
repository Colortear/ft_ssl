#include "../include/ft_ssl.h"
#include "../include/md5.h"
#include "../include/sha256.h"

char    *(*get_command(t_input_list *list))(char *)
{
    if (list && list->input)
    {
        if (strcmp(list->input, MD5))
            return md5;
        else if (strcmp(list->input, SHA256))
            return sha256;
    }
    return NULL;
}

static void append_to_list(char *input, struct s_list *entries)
{
    struct s_list   *cur;

    cur = entries;
    if (!input)
        return ;
    if (!cur) {
        cur = malloc(sizeof(struct s_list));
        cur->input
    while (cur)
}

t_ft_ssl    *create_entries(t_options *opt)
{
    t_ft_ssl    *ret;
 
    if (!opt->input_list)
        return NULL;
    ret = malloc(sizeof(t_ft_ssl));
    ret->hash = get_command(opt->input_list);
    while ((opt->input_list = opt->input_list->next))
    
}
