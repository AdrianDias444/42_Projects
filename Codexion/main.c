#include "header.h"


void run_single_coder(t_coder* coder, pthread_t* thread)
{
    ft_create_coder_thread(coder, thread);
}



int main()
{
    t_circle*	circle;
    t_args*		args;
    struct timeval tv_initial;
    long start_ms;
    t_coder* current_coder;
    t_simulation sim;
    int i;
    
    
    i = 0;
    args = ft_create_args();
    circle = ft_handle_circle(args);
    ft_handle_dongles(circle);

    
    pthread_t thread[args->number_of_coders + 1];
    current_coder = circle->first_coder;
    for (int j = 0; j < args->number_of_coders; j++)
    {
        current_coder->simulation = &sim;
        current_coder = current_coder->next;
    }

    pthread_mutex_init(&sim.mutex, NULL);
    
    current_coder = circle->first_coder;
    ft_create_monitor_thread(circle, &thread[i]);
    i++;
    while(i <= args->number_of_coders)
    {
        run_single_coder(current_coder, &thread[i]);
        current_coder = current_coder->next;
        i++;
    }
    i = 0;
    while(i <= args->number_of_coders)
    {
        pthread_join(thread[i], NULL);
        i++;
    }
    pthread_mutex_destroy(&sim.mutex);
    return 0;
}


