#include "../include/ft_ssl.h"
#include "../include/md5.h"
#include "../include/sha256.h"
#include "../include/input.h"

char    *(*get_command(t_input_list *list))(char *)
{
    if (list && list->input)
    {
        if (ft_strcmp(list->input, MD5))
            return md5;
        else if (ft_strcmp(list->input, SHA256))
            return sha256;
    }
    return NULL;
}

static void append_to_list(char *input, struct s_list **entries, int type)
{
    struct s_list   *cur;
    struct s_list   *to_append;

    cur = *entries;
    if (!input)
        return ;
    to_append = malloc(sizeof(struct s_list));
    to_append->type = type;
    to_append->should_free = type == STRING_INPUT;
    to_append->input = input;
    to_append->next = NULL;
    if (!cur)
       *entries = to_append;
    else {
        while (cur->next)
            cur = cur->next;
        cur->next = to_append;
    }
}

t_ft_ssl    *create_entries(t_options *opt)
{
    t_ft_ssl    *ret;
 
    if (!opt->input_list)
        return NULL;
    ret = malloc(sizeof(t_ft_ssl));
    ret->hash = get_command(opt->input_list);
    ret->to_display = NULL;
    if (!opt->opt_table[P])
        append_to_list(read_stdin(), &ret->entries, STDIN_INPUT);
    else
        ret->to_display = read_stdin();
    append_to_list(opt->args[STRING]->input, &ret->entries, STRING_INPUT);
    while ((opt->input_list = opt->input_list->next))
        append_to_list(read_from_file(opt->input_list->input),
                &ret->entries, FILE_INPUT);
}

void        destroy_ft_ssl(t_ft_ssl *ssl)
{
    struct s_list   *entries;
    struct s_list   *tmp;

    entries = ssl->entries;
    while (entries && entries->next)
    {
        free(entries->display_name);
        free(entries->processed_data);
        if (entries->should_free)
            free(entries->input);
        tmp = entries;
        ssl->entries = ssl->entries->next;
        free(tmp);
    }
}
