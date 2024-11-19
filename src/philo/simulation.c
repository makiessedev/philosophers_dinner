#include "../../include/philo.h"

void *simulation(void *arg)
{
    t_philos *philo;
    
    philo = (t_philos *)arg;
    philo->init_die = get_time();
    philo->start_simulation = get_time();

    while (philo->args->time_each_philo_must_eat == -1 ||
            philo->time_each_philo_must_eat > 0)
    {
        pthread_mutex_lock(philo->left_fork);
        print_status("has taken a fork", philo);

        pthread_mutex_lock(philo->right_fork);
        print_status("has taken a fork", philo);

        print_status("is eating", philo);
        philo->init_die = get_time();
        monitor_dies(philo, philo->args->time_to_eat);
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);

        print_status("is sleeping", philo);
        monitor_dies(philo, philo->args->time_to_sleep);
        
        (philo->time_each_philo_must_eat)--;
    }
    return (NULL);
}
