#include "../../include/philo.h"

void	destroy_all(t_main *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&program->print_mutex);
	pthread_mutex_destroy(&program->meal_mutex);
	pthread_mutex_destroy(&program->dead_mutex);
	while (i < program->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}