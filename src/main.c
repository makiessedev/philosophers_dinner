#include "../include/philo.h"

int main(int ac, char **av)
{
    t_args args;
    t_philos philos[PHILOS_MAX];
    pthread_mutex_t forks[PHILOS_MAX];

    if (!is_valid_input(ac, av))
        return (0);
    init_args(av, &args);
    dinner_init(&philos, &forks, args);
    return (0);
}
