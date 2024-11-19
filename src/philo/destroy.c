#include "../../include/philo.h"

void    destroy(pthread_mutex_t *forks, int philos_number)
{
    while (philos_number--)
        pthread_mutex_destroy(&forks[philos_number]);
}