#include "../../include/philo.h"

void set_forks(pthread_mutex_t *forks, int philos_number)
{
    while (philos_number--)
        pthread_mutex_init(&forks[philos_number], NULL);
}