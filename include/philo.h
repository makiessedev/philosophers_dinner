#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

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

// util
int ft_atoi(char *s);

#endif