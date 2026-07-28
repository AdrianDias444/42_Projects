#include "../../header.h"


void ft_compile(t_coder* coder)
{
    long duration;
    
    coder->action = "compile";
    duration = ft_return_time_since_start(coder->start_ms);
    
    pthread_mutex_lock(&coder->simulation->mutex);
    printf("%ld %d is compilling\n", duration, coder->number);
    pthread_mutex_unlock(&coder->simulation->mutex);
    
    
    usleep(coder->time_to_compile * 1000);
    coder->time_of_last_compile = ft_return_time_now();
    coder->number_of_compiles_done +=1;
    coder->action = NULL;
}

void ft_debug(t_coder* coder)
{
    long duration;


    duration = ft_return_time_since_start(coder->start_ms);
    coder->action = "debug";
    
    pthread_mutex_lock(&coder->simulation->mutex);
    printf("%ld %d is debugging\n", duration, coder->number);
    pthread_mutex_unlock(&coder->simulation->mutex);
    
    usleep(coder->time_to_debug * 1000);
    coder->action = NULL;
}

void ft_refactor(t_coder* coder)
{
    long duration;

    
    coder->action = "refactor";
    duration = ft_return_time_since_start(coder->start_ms);
    
    pthread_mutex_lock(&coder->simulation->mutex);
    printf("%ld %d is refactoring\n", duration, coder->number);
    pthread_mutex_unlock(&coder->simulation->mutex);
    
    usleep(coder->time_to_refactor * 1000);
    coder->action = NULL;
}


int ft_wait_dongle_be_free(t_dongle* dongle, t_coder* coder)
{
    long duration;
    
    while (dongle->actual_coder != NULL && coder->run == 1)
        pthread_cond_wait(&dongle->cond, &dongle->mutex);
    if (coder->run == 0)
    {
        pthread_mutex_unlock(&dongle->mutex);
        return(0);
    }
    duration = ft_return_time_since_start(coder->start_ms);
    
    pthread_mutex_lock(&coder->simulation->mutex);
    printf("%ld %d has taken a dongle\n", duration, coder->number);
    pthread_mutex_unlock(&coder->simulation->mutex);    
        
    dongle->actual_coder = coder;
    return(1);
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
    while (coder->number_of_compiles_done < NUMBER_OF_COMPILES_REQUIRED)
    {
        if(coder->run == 0)
            return(NULL);

        pthread_mutex_lock(&first->mutex);
        if(!ft_wait_dongle_be_free(first, coder))
            return(NULL);
        pthread_mutex_unlock(&first->mutex);

        

        pthread_mutex_lock(&second->mutex);
        if(!ft_wait_dongle_be_free(second, coder))
            return(NULL);
        pthread_mutex_unlock(&second->mutex);

        
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
    coder->action = "done";
    return (NULL);
}


void ft_create_coder_thread(t_coder* coder, pthread_t* thread)
{
    pthread_create(thread, NULL, coder_rotine, coder);
}
