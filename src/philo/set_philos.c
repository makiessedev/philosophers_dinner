#include "../../include/philo.h"

void set_philos(t_philos *philos, pthread_mutex_t *forks)
{
    int i;
    int num_of_philos;

    i = -1;
    num_of_philos = philos->args.num_of_philos;
    while(++i < num_of_philos)
    {
        init_args(&philos[i].args, &philos->args);
        philos[i].id = i + 1;
        philos[i].left_fork = &forks[i];
        if (i == 0)
            philos[i].right_fork = &forks[philos->args.num_of_philos - 1];
        else
            philos[i].right_fork = &forks[i - 1];
    }
}