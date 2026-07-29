#include "../../header.h"

t_heap* ft_create_heap()
{
    t_heap* heap;

    heap = malloc(sizeof(t_heap));
    if (!heap)
        return(NULL);
    heap -> first = NULL;
    heap -> how_many_waiting = 0;

    return (heap);
}