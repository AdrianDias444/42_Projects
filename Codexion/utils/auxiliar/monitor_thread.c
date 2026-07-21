#include "../../header.h"

void ft_stop(t_coder* coder)
{
    t_coder* current_coder;
    
    current_coder = coder;
    
    while(current_coder->run == 1)
    {
        current_coder->run = 0;
        current_coder = current_coder->next;
    }
}

void* ft_monitor_routine(void* arg)
{
    t_circle* circle;
    t_coder* coder;
    
    circle = (t_circle*) arg;
    coder = circle->first_coder;
    
    while(1)
    {
        printf("adsffd");
        if(ft_return_time_now() - coder->time_of_last_compile > coder->time_to_compile)
        {
            ft_stop(coder);
            break;
        }
        coder = coder->next;    
    }
    return(NULL);
}


pthread_t ft_create_monitor_thread(t_circle* circle)
{
    pthread_t tid;
    
    pthread_create(&tid, NULL, ft_monitor_routine, circle);
    pthread_join(tid, NULL);
        
    return(tid);
}