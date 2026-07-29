#include "../../header.h"

t_dongle* ft_create_dongle()
{
    t_dongle* new_dongle;

    new_dongle = malloc(sizeof(t_dongle));
    if (!new_dongle)
        return (NULL);
    new_dongle -> actual_coder = NULL;
    new_dongle->next = NULL;
    new_dongle->dongle_heap = NULL;
    pthread_mutex_init(&new_dongle->mutex, NULL);
    pthread_cond_init(&new_dongle->cond, NULL);
    return (new_dongle);
}