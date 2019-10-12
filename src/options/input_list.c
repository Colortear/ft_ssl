#include "../../include/options.h"

struct s_input_list *create_input_node(char *entry)
{
    struct s_input_list *ret;

    ret = malloc(sizeof(struct s_input_list));
    ret->input = entry;
    ret->next = NULL;
    return ret;
}

void    append_input_list_node(
        struct s_input_list **list,
        struct s_input_list *append)
{
    if (list)
    {
        while (list->next)
            cur = cur->next;
        cur->next = append;
    }
    else
        *list = append;
}

void    destroy_input_list(struct s_list_input *list)
{
    struct s_list_input *tmp;

    while (list) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}
