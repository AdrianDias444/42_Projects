#include "../../header.h"


t_coder* return_last_coder(t_heap* heap)
{
    t_coder* current_coder;
    t_coder* last_coder;

    current_coder = heap->first;
    last_coder = heap->first;
    if (current_coder == NULL)
        return (NULL);
    printf("Vou retornar");
    while(current_coder)
    {
        last_coder = current_coder;
        current_coder = current_coder -> heap_next;
    }
    printf("Vou retornar");
    return(last_coder);
}

t_coder* return_first_coder(t_heap* heap)
{
    if (!heap -> first)
        return(NULL);
    return (heap->first);
}



void ft_print_current_dongle_heap(pthread_mutex_t mutex, t_dongle* dongle)
{
    
    t_coder* first_coder;
    t_coder* second_coder;
    
    pthread_mutex_lock(&mutex);
    first_coder = return_first_coder(dongle->dongle_heap);
    second_coder = return_last_coder(dongle->dongle_heap);
    //printf("Cheguei %d\n", first_coder->number);
    if(first_coder)
        printf("Dongle: %c | First Coder in heap is %d\n", dongle->name, first_coder->number);
    if(second_coder)
        printf("Dongle: %c | Second Coder in heap is %d\n", dongle->name, second_coder->number);
    pthread_mutex_unlock(&mutex);
}


void ft_heap_push_back(t_heap* heap, t_coder* coder_to_push_back)
{
    t_coder* last_coder;

    last_coder = return_last_coder(heap);
    if (last_coder)
    {
        printf("Entrou\n");
        last_coder -> heap_next = coder_to_push_back;
        return ;
    }
    heap->first = coder_to_push_back;
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
            heap -> first = coder -> heap_next;
            coder -> heap_next = NULL;
        }
        else
        {
            heap -> first -> heap_next = NULL;
            heap -> first = coder;
        }
    }
    heap -> how_many_waiting -=1;
}