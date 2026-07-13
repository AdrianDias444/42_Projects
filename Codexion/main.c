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
    
    // pthread_create(&thread1, NULL, thread_test, NULL);
    // pthread_join(thread1, NULL);

    args = ft_parser();
    ft_print_args(args);
    
    circle = ft_handle_circle(args);
    ft_print_circle(circle->first_coder);
    
    ft_create_dongles(circle);
    ft_print_all_dongles(circle->first_coder->right_dongle, circle->first_coder->left_dongle, circle);
    printf("\n");
    ft_print_dongles(circle);
    return 0;
}