#include "../include/philo.h"

void    dinner_init(t_philos *philos, pthread_mutex_t *forks, t_args *args)
{
    set_forks(forks, args->num_of_philos);
    set_philos(philos, forks, args);
    destroy(forks, args->num_of_philos);
}
