#include "header.h"


void* thread_test(void* arg) {
    printf("Created a new thread");
    return NULL;
 }
int main(int argc, char **argv)
{
    pthread_t thread1;
    t_args args;
    
    // pthread_create(&thread1, NULL, thread_test, NULL);
    // pthread_join(thread1, NULL);

    args = ft_parser(argc, argv);
    printf("%d", args.number_of_coders);

    return 0;
}