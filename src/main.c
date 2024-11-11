#include "../include/philo.h"

void    init_args(char **av, t_args *args);

int main(int ac, char **av)
{
    t_args args;
    t_philos philo[atoi(av[1])];
    int i;

    init_args(av, &args);
    i = -1;
    while (++i < args.num_of_philos)
    {
        &philo->id = i;
        if(pthread_create(&philo[i].thread, NULL, &routine, &philo->id) != 0)
            return (printf("Error on create pthread"), 1);
    }
    i = -1;
    while (++i < args.num_of_philos)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (printf("Error on join thread"), 1);
    }
    return (0);
}

void    init_args(char **av, t_args *args)
{
    args->num_of_philos = atoi(av[1]);
    args->time_to_die = atoi(av[2]);
    args->time_to_eat = atoi(av[3]);
    args->time_to_sleep = atoi(av[4]);
    if (av[5])
        args->time_each_philo_must_eat = atoi(av[5]);
}