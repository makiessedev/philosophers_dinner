#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_main		main;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if ((argc != 5 && argc != 6) || check_args(argv) == 1)
	{
		write(2, "Invalid arguments\n", 18);
		return (1);
	}
	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	forks = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	init_main(&main, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &main, forks, argv);
	thread_create(&main, forks);
	destroy_all(&main, forks);
	free(philos);
	free(forks);
	return (0);
}
