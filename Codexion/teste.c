#include <stdio.h>
#include <sys/time.h> // gettimeofday()
#include <unistd.h>

int main()
{

    int i = 1;

    struct timeval tv_initial;
    struct timeval tv_final;

    
    gettimeofday(&tv_initial, NULL);
    while (i < 15)
    {
        gettimeofday(&tv_final, NULL);
        long start_ms = tv_initial.tv_sec * 1000 + tv_initial.tv_usec / 1000;
        long now_ms = tv_final.tv_sec * 1000 + tv_final.tv_usec / 1000;
        long difference = now_ms - start_ms;
        printf("Current time of execution is %ld\n", difference);
        i++;
        usleep(1000*1000);
    }
}