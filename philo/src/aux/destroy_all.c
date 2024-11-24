/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorais <mmorais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:55:33 by mmorais           #+#    #+#             */
/*   Updated: 2024/11/24 22:55:35 by mmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	destroy_all(t_main *main, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	pthread_mutex_destroy(&main->print_mutex);
	pthread_mutex_destroy(&main->meal_mutex);
	pthread_mutex_destroy(&main->dead_mutex);
	while (i < main->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}