#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

// to remove
#include <stdio.h>

#define PHILOS_MAX 200

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
    t_args  args;
    pthread_t thread;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
} t_philos;

int     ft_atoi(char *s);
int     is_valid_input(int ac, char **av);
int     ft_strlen(char *s);
void    init_args(char **av, t_args *args);
void    dinner_init(t_philos *philos, pthread_mutex_t *forks, t_args args);
void    set_forks(pthread_mutex_t *forks, int philos_number);
void    set_philos(t_philos *philos, pthread_mutex_t *forks);

#endif