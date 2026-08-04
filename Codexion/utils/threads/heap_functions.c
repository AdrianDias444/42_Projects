/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:19:54 by adrian            #+#    #+#             */
/*   Updated: 2026/08/04 13:19:55 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// Dangerous Function
t_coder* return_last_coder(t_heap* heap)
{
    t_coder* current_coder;
    t_coder* last_coder;

    current_coder = heap->first;
    last_coder = heap->first;


    if (current_coder == NULL)
        return (NULL);
    while(current_coder)
    {
        last_coder = current_coder;
        current_coder = current_coder -> heap_next;
    }

    return(last_coder);
}

// Dangerous Function
t_coder* return_first_coder(t_heap* heap)
{
    if (!heap -> first)
        return(NULL);
    return (heap->first);
}



void ft_print_dongle_heap(pthread_mutex_t* mutex, t_dongle* dongle)
{
    
    t_coder* first_coder;
    t_coder* second_coder;
    pthread_mutex_lock(&dongle->dongle_heap->mutex);
    first_coder = return_first_coder(dongle->dongle_heap);
    second_coder = return_last_coder(dongle->dongle_heap);
    pthread_mutex_lock(mutex);
    if(first_coder)
        printf("Dongle: %c | First Coder in heap is %d\n", dongle->name, first_coder->number);
    if(second_coder)
        printf("Dongle: %c | Second Coder in heap is %d\n", dongle->name, second_coder->number);
    pthread_mutex_unlock(mutex);
    pthread_mutex_unlock(&dongle->dongle_heap->mutex);
}


// Dangerous Function
int ft_is_coder_in_heap(t_heap* heap, t_coder* coder)
{
    if (!heap->first)
        return (0);
    else
    {
        if (coder == heap->first)
            return (1);
        if (coder == heap->first->heap_next)
            return (1);
        return (0);
    }
}





void ft_heap_push_back(t_heap* heap, t_coder* coder_to_push_back)
{
    t_coder* last_coder;

    pthread_mutex_lock(&heap->mutex);
    last_coder = return_last_coder(heap);
    if (ft_is_coder_in_heap(heap, coder_to_push_back) == 1)
    {
        pthread_mutex_unlock(&heap->mutex);
        return ;
    }
    if (last_coder)
        last_coder -> heap_next = coder_to_push_back;
    else
        heap->first = coder_to_push_back;
    heap -> how_many_waiting += 1;
    pthread_mutex_unlock(&heap->mutex);
}


void ft_remove_from_heap(t_heap* heap, t_coder* coder)
{
    pthread_mutex_lock(&heap->mutex);
    if(!heap->first)
    {
        pthread_mutex_unlock(&heap->mutex);
        return ;
    }

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
            heap -> first -> heap_next = NULL;

    }
    heap -> how_many_waiting -=1;
    pthread_mutex_unlock(&heap->mutex);
}