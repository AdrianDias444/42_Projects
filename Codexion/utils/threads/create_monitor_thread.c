#include "../../header.h"

void ft_stop(t_coder* coder)
{
    int i;
    
    i = 0;
    while(i < NUMBER_OF_CODERS)
    {
        pthread_mutex_lock(&coder->mutex_coder);
        coder->run = 0;
        pthread_cond_signal(&coder->right_dongle->cond);
        pthread_cond_signal(&coder->left_dongle->cond);
        pthread_mutex_unlock(&coder->mutex_coder);
        coder = coder->next;
        i++;
    }
}


int ft_all_coders_finish(t_circle* circle)
{
    t_coder* current_coder;

    
    current_coder = circle->first_coder;
    
    while(current_coder != circle->first_coder->previous)
    {
        pthread_mutex_lock(&current_coder->mutex_coder);
        if (current_coder-> number_of_compiles_done < NUMBER_OF_COMPILES_REQUIRED)
        {
            pthread_mutex_unlock(&current_coder->mutex_coder);
            return(1);
        }
        pthread_mutex_unlock(&current_coder->mutex_coder);
        current_coder = current_coder->next;
    }
    pthread_mutex_lock(&current_coder->mutex_coder);
    if (current_coder-> number_of_compiles_done < NUMBER_OF_COMPILES_REQUIRED)
    {
        pthread_mutex_unlock(&current_coder->mutex_coder);
        return(1);
    }

    if (current_coder->action && strcmp(current_coder->action, "done") != 0)
    {
        pthread_mutex_unlock(&current_coder->mutex_coder);
        return(1);
    }
    // Podemos estar a verificar a coder->action depois de um debug()
    if (!current_coder->action)
    {
        pthread_mutex_unlock(&current_coder->mutex_coder);            
        return(1);
    }
    pthread_mutex_unlock(&current_coder->mutex_coder);
    return(0);
}




void *ft_monitor_routine(void *arg)
{
    t_circle *circle = (t_circle *)arg;
    t_coder  *coder;
    long      duration;
    int       i;
    long time_since_compile;


    while (ft_all_coders_finish(circle))
    {
        coder = circle->first_coder;
        i = 0;
        while (i < circle->number_of_coders)
        {
            pthread_mutex_lock(&coder->mutex_coder);
            time_since_compile = ft_return_time_now() - coder->time_of_last_compile;
            if (time_since_compile > coder->time_to_burnout)
            {
                if(coder->action && strcmp(coder->action, "compile") != 0)
                {
                    if(coder->number_of_compiles_done < circle->number_of_compiles_required)
                    {
                        duration = ft_return_time_since_start(coder->start_ms);
                        pthread_mutex_lock(&coder->simulation->mutex);
                        printf("%ld %d burned out\n", duration, coder->number);
                        pthread_mutex_unlock(&coder->simulation->mutex);
                        pthread_mutex_unlock(&coder->mutex_coder);
                        ft_stop(coder);
                        return (NULL);
                    }
                }
            }
            pthread_mutex_unlock(&coder->mutex_coder);
            coder = coder->next;
            i++;
        }
        //usleep(2000);
    }
    pthread_mutex_lock(&coder->simulation->mutex);
    printf("Simulation done\n");
    pthread_mutex_unlock(&coder->simulation->mutex);
    return (NULL);
}


void ft_create_monitor_thread(t_circle* circle, pthread_t* thread)
{
    pthread_create(thread, NULL, ft_monitor_routine, circle);    
}
