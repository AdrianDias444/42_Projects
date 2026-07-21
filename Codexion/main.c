#include "header.h"


void run_single_coder(t_coder* coder, pthread_t* thread)
{
    ft_create_coder_thread(coder, thread);
}



int main()
{
    t_circle* circle;
    t_args args;
    struct timeval tv_initial;
    long start_ms;

    
    gettimeofday(&tv_initial, NULL);
    start_ms = tv_initial.tv_sec * 1000 + tv_initial.tv_usec / 1000;
    
    
    args = ft_parser();
    
    args.start_ms = start_ms;
    
    circle = ft_handle_circle(args);
    
    ft_create_dongles(circle);
    printf("\n");
    pthread_t thread[args.number_of_coders];
    t_coder* current_coder;
    int i;
    
    i = 0;
    current_coder = circle->first_coder;
    while(i < args.number_of_coders)
    {
        run_single_coder(current_coder, &thread[i]);
        current_coder = current_coder->next;
        i++;
    }
    i = 0;
    while(i < args.number_of_coders)
    {
        pthread_join(thread[i], NULL);
        i++;
    }
    ft_create_monitor_thread(circle);

            
    return 0;
}
