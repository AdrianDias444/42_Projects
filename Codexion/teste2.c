#include <pthread.h>
#include <stdio.h>


void* aux(void* arg)
{
    printf("%s\n", arg);
    
    return(NULL);
}

int main()
{
    pthread_t thread[5];
    char* str = "testing";
    
    
    int i = 0;
    while(i < 5)
    {
        pthread_create(&thread[i], NULL, aux, str);
        printf("TID is |%lu|\n", thread[i]);
        i++;    
    }
    i = 0;
    while(i < 5)
    {
        pthread_join(thread[i], NULL);
        i++;
    } 
}