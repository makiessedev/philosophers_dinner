#include "../../include/philo.h"

static int is_valid_arg(char *arg);
static int is_number(char c);
static int print_input_error();

int is_valid_input(int ac, char **av)
{
    int i;

    i = -1;
    if (ac != 5 && ac != 6)
        return (print_input_error(), 0);
    while (ac - 1 > ++i)
    {
        if (!is_valid_arg(av[i + 1]))
            return (print_input_error(), 0);
    }
    return (1);
}

static int print_input_error()
{
    char msg[] = "Error: ./philo <n_philos> <t_die> <t_eat> <t_sleep> [n_each_must_eat]\n";
    write(2, &msg, ft_strlen(msg));
}

static int is_valid_arg(char *arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (!is_number(arg[i]))
            return (0);
        i++;
    }
    return (1);
}

static int is_number(char c)
{
    return (c >= '0' && c <= '9');
}