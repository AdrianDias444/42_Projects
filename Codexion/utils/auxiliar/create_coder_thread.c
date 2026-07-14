#include "../../header.h"


void coder_rotine(t_coder* coder)
{
    int left_dongle;
    int right_dongle;

    left_dongle = 1;

    left_dongle = pthread_mutex_lock(coder->left_dongle->mutex);
    right_dongle = pthread_mutex_lock(coder->right_dongle->mutex);



}


int ft_create_coder_thread(t_coder* coder)
{
    pthread_t thread;


    pthread_mutex_init(coder->left_dongle->mutex);
    pthread_mutex_init(coder->right_dongle->mutex);
    pthread_create(thread, NULL, coder_rotine, coder);
}