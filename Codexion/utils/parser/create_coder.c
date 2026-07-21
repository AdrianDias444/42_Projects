#include "../../header.h"


t_coder* ft_create_coder(int nb)
{
    t_coder* coder;

    coder = malloc(sizeof(t_coder));
    if (!coder)
        return (NULL);
    coder->number = nb;
    coder->next = NULL;
    coder->previous = NULL;
    coder->action = NULL;
    coder->right_dongle = NULL;
    coder->left_dongle = NULL;
    coder->time_to_compile = 0;
    coder->time_to_debug = 0;
    coder->time_to_refactor = 0;
    coder->run = 1;

    return (coder);
}
