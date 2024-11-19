#include "./../../include/philo.h"

void monitor_dies(t_philos *philo, int check_time_exceeded)
{
    int i;

    i = 0;
    while (i < (check_time_exceeded / 10))
    {
        if (current_time(philo->init_die) >= philo->args->time_to_die)
        {
            print_status("died", philo);
            philo->args->is_philo_died = 1;
            break;
        }
        usleep(10000);
        i++;
    }
}