#include "../../include/philo.h"

void    init_args(char **av, t_args *args)
{
    args->num_of_philos = ft_atoi(av[1]);
    args->time_to_die = ft_atoi(av[2]);
    args->time_to_eat = ft_atoi(av[3]);
    args->time_to_sleep = ft_atoi(av[4]);
    if (av[5])
        args->time_each_philo_must_eat = ft_atoi(av[5]);
    else
        args->time_each_philo_must_eat = -1;
    pthread_mutex_init(&args->printf_mutex, NULL);
}