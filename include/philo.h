#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

// to remove
#include <stdio.h>

#define PHILO_MAX 200

typedef struct s_args
{
    int num_of_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int time_each_philo_must_eat;
} t_args;

typedef struct s_philos
{
    int id;
    pthread_t thread;
} t_philos;

int ft_atoi(char *s);
int is_valid_input(int ac, char **av);
int ft_strlen(char *s);

#endif