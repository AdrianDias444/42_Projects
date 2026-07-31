#include "../../header.h"


t_coder* ft_edf(t_dongle* dongle)
{
    t_heap* heap;
    t_coder* first_coder;
    t_coder* second_coder;

    heap = dongle->dongle_heap;
    first_coder = heap->first;
    second_coder = first_coder->heap_next;

    //printf("edf\n");
    if (!second_coder)
        return (first_coder);
    if (first_coder -> time_of_last_compile < second_coder -> time_of_last_compile)
        return (first_coder);
    return (second_coder);
}