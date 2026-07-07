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
    printf("\n");
    printf("Number of coders: %d\n", args.number_of_coders);
    printf("Time to burnout: %d\n", args.time_to_burnout);
    printf("Time to compile: %d\n", args.time_to_compile);
    printf("Time to debug: %d\n", args.time_to_debug);
    printf("Time to refactor: %d\n", args.time_to_refactor);
    printf("Number of compiles: %d\n", args.number_of_compiles_required);
    printf("Dongle Cooldown: %d\n", args.dongle_cooldown);
    printf("Scheduler: %s\n", args.scheduler);
    return 0;
}