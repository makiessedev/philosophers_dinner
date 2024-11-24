#include "../../include/philo.h"

static int	is_invalid_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **argv)
{
	if (ft_atoi(argv[1]) <= 0 || is_invalid_arg(argv[1]) == 1)
		return (write(2, "Invalid philosophers number\n", 29), 1);
	if (ft_atoi(argv[2]) <= 0 || is_invalid_arg(argv[2]) == 1)
		return (write(2, "Invalid time to die\n", 21), 1);
	if (ft_atoi(argv[3]) <= 0 || is_invalid_arg(argv[3]) == 1)
		return (write(2, "Invalid time to eat\n", 21), 1);
	if (ft_atoi(argv[4]) <= 0 || is_invalid_arg(argv[4]) == 1)
		return (write(2, "Invalid time to sleep\n", 23), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || is_invalid_arg(argv[5]) == 1))
		return (write(2, "Invalid number of times each philosopher must eat\n",
				51), 1);
	return (0);
}