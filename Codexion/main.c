#include "header.h"


void run_single_coder(t_coder* coder)
{
    pthread_t thread;
    
    ft_create_coder_thread(coder, thread);
    pthread_join(thread, NULL);
}



int main()
{
    pthread_t thread1;
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
    run_single_coder(circle->first_coder);
            
    return 0;
}