#include "header.h"


t_coder* return_last_coder(t_heap* heap)
{
    t_coder* current_coder;
    t_coder* last_coder;

    current_coder = heap->first;
    last_coder = heap->first;
    if (current_coder -> NULL)
        return (NULL);
    while(current_coder)
    {
        last_coder = current_coder;
        current_coder = current_coder -> heap_next;
    }
    return(last_coder);
}



void ft_heap_push_back(t_heap* heap, t_coder* coder_to_push_back)
{
    t_coder* last_coder;

    last_coder = return_last_coder(heap);
    last_coder -> heap_next = coder_to_push_back;
    heap -> how_many_waiting += 1;

}


void ft_remove_from_heap(t_heap* heap, t_coder* coder)
{
    if (heap -> how_many_waiting == 1)
        heap -> first = NULL;
    
    else
    {
        if (heap -> first == coder)
        {
            heap -> first == coder -> heap_next;
            coder -> heap_next = NULL
        }
        else
        {
            heap -> first -> heap_next = NULL;
            heap -> first = coder
        }
    }
    heap -> how_many_waiting -=1;
}