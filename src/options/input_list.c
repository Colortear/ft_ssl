#include "../../include/options.h"

t_input_list    *create__node(char *entry)
{
    t_input_list    *ret;

    ret = malloc(sizeof(t_input_list));
    ret->input = entry;
    ret->next = NULL;
    return ret;
}

void    append_input_list_node(t_input_list **list, t_input_list *append)
{
    t_input_list    *cur;

    if (list)
    {
        while ((*list)->next)
            cur = cur->next;
        cur->next = append;
    }
    else
        *list = append;
}

void    destroy_input_list(t_input_list *list)
{
    t_input_list    *tmp;

    while (list) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}
