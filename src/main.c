#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_main		main;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if (argc != 5 && argc != 6)
		return (write(2, "Wrong argument count\n", 22), 1);
	if (check_args(argv) == 1)
		return (1);
	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	forks = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	init_main(&main, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &main, forks, argv);
	thread_create(&main, forks);
	destory_all(NULL, &main, forks);
	return (0);
}
