#include "../../include/philo.h"

void set_philos(t_philos *philos, pthread_mutex_t *forks, t_args *args)
{
    int i;
    int num_of_philos;

    num_of_philos = args->num_of_philos;
    i = -1;
    while(++i < num_of_philos)
    {
        philos[i].id = i + 1;
        philos[i].left_fork = &forks[i];
        philos[i].time_each_philo_must_eat = args->time_each_philo_must_eat;
        if (i == 0)
            philos[i].right_fork = &forks[args->num_of_philos - 1];
        else
            philos[i].right_fork = &forks[i - 1];
        philos[i].args = args;
        pthread_create(&philos[i].thread, NULL, &simulation, &philos[i]);
    }
    i = -1;
    while (++i < num_of_philos)
        pthread_join(philos[i].thread, NULL);
}