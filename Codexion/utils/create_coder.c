#include "../header.h"


t_coder* ft_create_coder(int nb)
{
    t_coder* coder;

    coder = malloc(sizeof(t_coder));
    if (!coder)
        return (NULL);
    coder->number = nb;
    coder->next = NULL;
    coder->previous = NULL;

    return (coder);
}
