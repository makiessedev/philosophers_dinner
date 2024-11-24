#include "../../include/philo.h"

void	print_status(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_mutex);
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_mutex);
}
