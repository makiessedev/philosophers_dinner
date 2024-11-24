#include "../../include/philo.h"

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->philo_id);
}

void	dream(t_philo *philo)
{
	print_message("is sleeping", philo, philo->philo_id);
	ft_usleep(philo->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_message("has taken a fork", philo, philo->philo_id);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_message("has taken a fork", philo, philo->philo_id);
	philo->is_eat = 1;
	print_message("is eating", philo, philo->philo_id);
	pthread_mutex_lock(philo->meal_mutex);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_mutex);
	ft_usleep(philo->time_to_eat);
	philo->is_eat = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
