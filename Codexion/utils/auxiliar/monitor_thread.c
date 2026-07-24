#include "../../header.h"

void ft_stop(t_coder* coder)
{
    int i;
    
    i = 0;
    while(i < NUMBER_OF_CODERS)
    {
        coder->run = 0;
        pthread_cond_broadcast(&coder->right_dongle->cond);
        pthread_cond_broadcast(&coder->left_dongle->cond);
        coder = coder->next;
        i++;
    }
}

void *ft_monitor_routine(void *arg)
{
    t_circle *circle = (t_circle *)arg;
    t_coder  *coder;
    long      duration;
    int       i;

    while (1)
    {
        coder = circle->first_coder;
        i = 0;
        while (i < circle->number_of_coders)
        {
            if (ft_return_time_now() - coder->time_of_last_compile > coder->time_to_burnout)
            {
                duration = ft_return_time_since_start(coder->start_ms);
                pthread_mutex_lock(&coder->simulation->mutex);
                printf("%ld %d burned out\n", duration, coder->number);
                pthread_mutex_unlock(&coder->simulation->mutex);
                ft_stop(coder);
                return (NULL);
            }
            coder = coder->next;
            i++;
        }
        usleep(1000);
    }
    return (NULL);
}


void ft_create_monitor_thread(t_circle* circle, pthread_t* thread)
{
    pthread_create(thread, NULL, ft_monitor_routine, circle);    
}
