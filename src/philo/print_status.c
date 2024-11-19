#include "../../include/philo.h"

void print_status(char *msg, t_philos *philos)
{
    pthread_mutex_lock(&philos->args->printf_mutex);
    printf("%lli %i %s\n", current_time(philos->start_simulation), philos->id, msg);
    pthread_mutex_unlock(&philos->args->printf_mutex);
}