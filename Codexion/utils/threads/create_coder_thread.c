#include "../../header.h"


void ft_compile(t_coder* coder)
{
    long duration;
    
    pthread_mutex_lock(&coder->mutex_coder);
    coder->action = "compile";
    duration = ft_return_time_since_start(coder->start_ms);
    
    pthread_mutex_lock(&coder->simulation->mutex);
    printf("%ld %d is compilling\n", duration, coder->number);
    pthread_mutex_unlock(&coder->simulation->mutex);
    
    
    usleep(coder->time_to_compile * 1000);
    coder->time_of_last_compile = ft_return_time_now();
    coder->number_of_compiles_done +=1;
    coder->action = NULL;
    pthread_mutex_unlock(&coder->mutex_coder);
}

void ft_debug(t_coder* coder)
{
    long duration;

    pthread_mutex_lock(&coder->mutex_coder);
    duration = ft_return_time_since_start(coder->start_ms);
    coder->action = "debug";
    
    pthread_mutex_lock(&coder->simulation->mutex);
    printf("%ld %d is debugging\n", duration, coder->number);
    pthread_mutex_unlock(&coder->simulation->mutex);
    
    usleep(coder->time_to_debug * 1000);
    coder->action = NULL;

    pthread_mutex_unlock(&coder->mutex_coder);
}

void ft_refactor(t_coder* coder)
{
    long duration;

    pthread_mutex_lock(&coder->mutex_coder);
    
    coder->action = "refactor";
    duration = ft_return_time_since_start(coder->start_ms);
    
    pthread_mutex_lock(&coder->simulation->mutex);
    printf("%ld %d is refactoring\n", duration, coder->number);
    pthread_mutex_unlock(&coder->simulation->mutex);
    
    usleep(coder->time_to_refactor * 1000);
    coder->action = NULL;

    pthread_mutex_unlock(&coder->mutex_coder);
}


t_coder* ft_choose_coder_from_heap(t_dongle* dongle)
{
    t_coder* coder_chosen;

    pthread_mutex_lock(&dongle->dongle_heap->mutex);
    if (strcmp(SCHEDULER, "fifo") == 0)
        coder_chosen = ft_fifo(dongle);
    if (strcmp(SCHEDULER, "edf") == 0)
        coder_chosen = ft_edf(dongle);
    pthread_mutex_unlock(&dongle->dongle_heap->mutex);
    return(coder_chosen);
}




int ft_wait_dongle_be_free(t_dongle* dongle, t_coder* coder)
{
    long duration;
    int run_status;

    pthread_mutex_lock(&coder->mutex_coder);
    run_status = coder->run;
    pthread_mutex_unlock(&coder->mutex_coder);

    ft_heap_push_back(dongle->dongle_heap, coder);
    pthread_mutex_lock(&dongle->mutex);
    
    while (dongle->actual_coder != NULL && run_status == 1 && ft_choose_coder_from_heap(dongle) != coder)
        pthread_cond_wait(&dongle->cond, &dongle->mutex);
    
    if (run_status == 0)
    {
        ft_remove_from_heap(dongle->dongle_heap, coder);
        pthread_cond_signal(&dongle->cond);
        pthread_mutex_unlock(&dongle->mutex);
        return(0);
    }
    
    duration = ft_return_time_since_start(coder->start_ms);
    
    pthread_mutex_lock(&coder->simulation->mutex);
    printf("%ld %d has taken a dongle\n", duration, coder->number);
    pthread_mutex_unlock(&coder->simulation->mutex);    
        
    dongle->actual_coder = coder;
    pthread_mutex_unlock(&dongle->mutex);
    return(1);
}


void* check_thread_state(t_coder* coder)
{
    pthread_mutex_lock(&coder->mutex_coder);
    if(coder->run == 0)
    {
        pthread_mutex_unlock(&coder->mutex_coder);
        return(NULL);
    }
    if(coder->number_of_compiles_done >= NUMBER_OF_COMPILES_REQUIRED)
    {
        pthread_mutex_unlock(&coder->mutex_coder);
        return(NULL);
    }
    pthread_mutex_unlock(&coder->mutex_coder);
    return(coder);
}



void* coder_rotine(void* arg)
{
    t_dongle* left_dongle;
    t_dongle* right_dongle;
    t_dongle* first;
    t_dongle* second;
    t_coder* coder;
    coder = (t_coder *) arg;

    left_dongle = coder->left_dongle;
    right_dongle = coder->right_dongle;
    first = left_dongle;
    second = right_dongle;

    if (first->name > second->name)
    {
        first = right_dongle;
        second = left_dongle;
    }
    while (1)
    {

        if(!check_thread_state(coder))
            break;
        
        if(!ft_wait_dongle_be_free(first, coder))
            return(NULL);
        ft_remove_from_heap(first->dongle_heap, coder);


        ft_print_current_dongle_heap(&coder->simulation->mutex, first);


        if(!ft_wait_dongle_be_free(second, coder))
            return(NULL);
        ft_remove_from_heap(second->dongle_heap, coder);


        ft_print_current_dongle_heap(&coder->simulation->mutex, second);

        ft_compile(coder);

        pthread_mutex_lock(&first->mutex);
        first->actual_coder = NULL;
        pthread_cond_signal(&first->cond);
        usleep(first->dongle_cooldown * 1000);
        pthread_mutex_unlock(&first->mutex);

        pthread_mutex_lock(&second->mutex);
        second->actual_coder = NULL;
        pthread_cond_signal(&second->cond);
        pthread_mutex_unlock(&second->mutex);

        ft_debug(coder);
        ft_refactor(coder);
    }
    pthread_mutex_lock(&coder->mutex_coder);
    coder->action = "done";
    pthread_mutex_unlock(&coder->mutex_coder);
    return (NULL);
}


void ft_create_coder_thread(t_coder* coder, pthread_t* thread)
{
    pthread_create(thread, NULL, coder_rotine, coder);
}
