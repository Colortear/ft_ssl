#include <stdlib.h>

#include "../../include/input.h"
#include "../../include/util.h"

static t_input  *new_input(char *input, int size)
{
    t_input  *new_node;

    new_node = malloc(sizeof(t_input));
    new_node->input = malloc(sizeof(char) * (size+1));
    new_node->size = size;
    new_node->next = NULL;
    return new_node;
}

static char     *str_from_list(t_input *list, size_t total_size)
{
    char    *ret;
    char    *iter;
    t_input *tmp;
    
    ret = malloc(sizeof(char) * (total_size+1));
    iter = ret;
    while (list)
    {
        tmp = list;
        ft_strncpy(tmp->input, iter, tmp->size);
        iter += tmp->size;
        list = list->next;
        free(tmp->input);
        free(tmp);
    }
    ret[total_size] = 0;
    return ret;
}

static char     *read_in(int fd)
{
    char    buf[BUF_SIZE];
    t_input *root;
    t_input *cur;
    size_t  bytes;
    size_t  total;

    root = NULL;
    total = 0;
    while ((bytes = read(fd, buf, BUF_SIZE)))
    {
        total += bytes;
        if (!root)
        {
            root = new_input(buf, bytes);
            cur = root;
        }
        else
        {
            cur->next = new_input(buf, bytes);
            cur = cur->next;
        }
    }
    return str_from_list(root, total);
}

char            *read_stdin(void)
{
    return read_in(STDIN_FILENO);
}

char            *read_from_file(char *file_name)
{
    int fd;

    if (!(fd = open(file_name, O_RDONLY)))
        return NULL;
    return read_in(fd);
}
