/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorais <mmorais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:56:25 by mmorais           #+#    #+#             */
/*   Updated: 2024/11/24 22:56:28 by mmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->is_dead_mutex);
	if (*philo->is_dead == 1)
	{
		pthread_mutex_unlock(philo->is_dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->is_dead_mutex);
	return (0);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->philo_id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}

int	thread_create(t_main *main, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, main->philos) != 0)
		destroy_all(main, forks);
	i = 0;
	while (i < main->philos[0].num_of_philos)
	{
		if (pthread_create(&main->philos[i].thread, NULL, &philo_routine,
				&main->philos[i]) != 0)
			destroy_all(main, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		destroy_all(main, forks);
	while (i < main->philos[0].num_of_philos)
	{
		if (pthread_join(main->philos[i].thread, NULL) != 0)
			destroy_all(main, forks);
		i++;
	}
	return (0);
}
