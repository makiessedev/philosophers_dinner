#include "../../include/philo.h"

void	init_input(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->num_of_philos = ft_atoi(argv[1]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoi(argv[5]);
	else
		philo->num_times_to_eat = -1;
}

void	init_philos(t_philo *philos, t_main *main, pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].philo_id = i + 1;
		philos[i].is_eat = 0;
		philos[i].meals_eaten = 0;
		init_input(&philos[i], argv);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].print_mutex = &main->print_mutex;
		philos[i].is_dead_mutex = &main->dead_mutex;
		philos[i].meal_mutex = &main->meal_mutex;
		philos[i].is_dead = &main->is_dead_flag;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_main(t_main *main, t_philo *philos)
{
	main->is_dead_flag = 0;
	main->philos = philos;
	pthread_mutex_init(&main->print_mutex, NULL);
	pthread_mutex_init(&main->dead_mutex, NULL);
	pthread_mutex_init(&main->meal_mutex, NULL);
}
