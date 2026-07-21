#include "../../header.h"


void ft_compile(t_coder* coder)
{
    long duration;
    
    duration = ft_return_time_since_start(coder->start_ms);
    coder->action = "compile";
    printf("%ld %d is compilling\n", duration, coder->number);
    usleep(coder->time_to_compile * 1000);
}

void ft_debug(t_coder* coder)
{
    long duration;


    duration = ft_return_time_since_start(coder->start_ms);
    coder->action = "debug";
    printf("%ld %d is debugging\n", duration, coder->number);
    usleep(coder->time_to_debug * 1000);
}

void ft_refactor(t_coder* coder)
{
    long duration;

    
    duration = ft_return_time_since_start(coder->start_ms);;
    coder->action = "refactor";
    printf("%ld %d is refactoring\n", duration, coder->number);
    usleep(coder->time_to_refactor * 1000);
}

void* coder_rotine(void* arg)
{
    t_dongle* left_dongle;
    t_dongle* right_dongle;
    t_dongle* first;
    t_dongle* second;
    t_coder* coder;
    long duration;
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
        if(coder->run == 0)
        {
            printf("Thread %d Stopped\n", coder->number);
            return(NULL);
        }
        pthread_mutex_lock(&first->mutex);
        while(!(first->actual_coder == NULL))
            pthread_cond_wait(&first->cond, &first->mutex);
        duration = ft_return_time_since_start(coder->start_ms);
        printf("%ld %d has taken a dongle\n", duration, coder->number);        
        first->actual_coder = coder;
        pthread_mutex_unlock(&first->mutex);

        
        if(coder->run == 0)
        {
            printf("Thread %d Stopped\n", coder->number);
            return(NULL);
        }
        pthread_mutex_lock(&second->mutex);
        while(!(second->actual_coder == NULL))
            pthread_cond_wait(&second->cond, &second->mutex);
        duration = ft_return_time_since_start(coder->start_ms);
        printf("%ld %d has taken a dongle\n", duration, coder->number);        
        second->actual_coder = coder;
        pthread_mutex_unlock(&second->mutex);

        if(coder->run == 0)
        {
            printf("Thread %d Stopped\n", coder->number);
            return(NULL);
        }
        
        ft_compile(coder);

        if(coder->run == 0)
        {
            printf("Thread %d Stopped\n", coder->number);
            return(NULL);
        }
        pthread_mutex_lock(&first->mutex);
        first->actual_coder = NULL;
        pthread_cond_signal(&first->cond);
        pthread_mutex_unlock(&first->mutex);

        if(coder->run == 0)
        {
            printf("Thread %d Stopped\n", coder->number);
            return(NULL);
        }
        
        pthread_mutex_lock(&second->mutex);
        second->actual_coder = NULL;
        pthread_cond_signal(&second->cond);
        pthread_mutex_unlock(&second->mutex);

        if(coder->run == 0)
        {
            printf("Thread %d Stopped\n", coder->number);
            return(NULL);
        }
        
        ft_debug(coder);
        if(coder->run == 0)
        {
            printf("Thread %d Stopped\n", coder->number);
            return(NULL);
        }
        ft_refactor(coder);
        
        if(coder->run == 0)
        {
            printf("Thread %d Stopped\n", coder->number);
            return(NULL);
        }
    }
    return (NULL);
}


void ft_create_coder_thread(t_coder* coder, pthread_t* thread)
{
    pthread_create(thread, NULL, coder_rotine, coder);
}
