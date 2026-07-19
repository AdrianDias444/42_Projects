#include "header.h"


void* thread_test(void* arg)
{
    printf("Created a new thread");
    return NULL;
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
    
    pthread_t thread[args.number_of_coders];
    
    
    int i;
    t_coder* current_coder;
    
    current_coder = circle->first_coder;
    
    i = 0;
    while(i < args.number_of_coders)
    {
        current_coder->coder_thread_id = thread[i];
        ft_create_coder_thread(current_coder);
        current_coder = current_coder->next;
        i++;
    }
    i = 0;
    
    while(i < args.number_of_coders)
    {
        pthread_join(thread[i], NULL);
        i++;
    }
    
    
    
    return 0;
}