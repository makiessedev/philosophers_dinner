#include "../../include/philo.h"

void *simulation(void *arg)
{
    t_philos *philo;
    philo = (t_philos *)arg;
    printf("id: %d\n", philo->id);
    return (NULL);
}
