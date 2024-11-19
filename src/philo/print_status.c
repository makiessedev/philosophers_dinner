#include "../../include/philo.h"

void print_status(char *msg, t_philos *philos)
{
    pthread_mutex_lock(&philos->args->printf_mutex);
    if (!philos->args->is_philo_died)
        printf("%lli %i %s\n", current_time(philos->start_simulation), philos->id, msg);
    pthread_mutex_unlock(&philos->args->printf_mutex);
}