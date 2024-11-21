#include "../../include/philo.h"

void *simulation(void *arg)
{
    t_philos *philo;
    
    philo = (t_philos *)arg;
    philo->init_die = get_time();
    philo->start_simulation = get_time();

    if (philo->args->num_of_philos == 1)
    {
        pthread_mutex_lock(philo->left_fork);
        print_status("has token a fork", philo);

        usleep(philo->args->time_to_die * 1000);
        print_status("died", philo);

        pthread_mutex_unlock(philo->left_fork);
        return (NULL);
    }

    while (philo->args->time_each_philo_must_eat == -1 || philo->time_each_philo_must_eat > 0)
    {
        if (philo->id % 2 == 0)
            usleep(1000);

        pthread_mutex_lock(philo->left_fork);
        print_status("has taken a fork", philo);

        pthread_mutex_lock(philo->right_fork);
        print_status("has taken a fork", philo);

        print_status("is eating", philo);
        monitor_dies(philo, philo->args->time_to_eat);
        philo->init_die = get_time();
        
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);

        print_status("is sleeping", philo);
        monitor_dies(philo, philo->args->time_to_sleep);

        if (philo->args->is_philo_died)
            break;
        (philo->time_each_philo_must_eat)--;
    }
    return (NULL);
}
