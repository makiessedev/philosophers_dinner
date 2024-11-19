#include "../include/philo.h"

int main(int ac, char **av)
{
    t_args args;
    t_philos *philos;
    pthread_mutex_t *forks;


    if (!is_valid_input(ac, av))
        return (0);
    init_args(av, &args);
    
    philos = malloc(sizeof(t_philos) * args.num_of_philos);
    forks = malloc(sizeof(pthread_mutex_t) * args.num_of_philos);
    
    dinner_init(&philos, &forks, args);
    return (0);
}
