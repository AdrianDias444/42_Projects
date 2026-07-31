#include "../../header.h"

t_coder* ft_fifo(t_dongle* dongle)
{
    t_heap* heap;

    heap = dongle -> dongle_heap;
    //printf("fifo\n");
    return (heap->first);
}