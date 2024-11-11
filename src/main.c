#include "../include/philo.h"

void    init_args(char **av, t_args *args);

int main(int ac, char **av)
{
    t_args args;
    t_philos philo[PHILO_MAX];
    int i;

    if (!is_valid_input(ac, av))
        return (0);
    init_args(av, &args);
    write(1, "ok", 2);
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