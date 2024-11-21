#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

typedef struct s_args
{
    int             num_of_philos;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             time_each_philo_must_eat;
    _Atomic int     is_philo_died;
    pthread_mutex_t printf_mutex;
} t_args;

typedef struct s_philos
{
    int             id;
    t_args          *args;
    pthread_t       thread;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    long long       init_die;
    long long       start_simulation;
    int             time_each_philo_must_eat;
} t_philos;

int         ft_atoi(char *s);
int         is_valid_input(int ac, char **av);
int         ft_strlen(char *s);
void        init_args(char **av, t_args *args);
void        *simulation(void *arg);
void        dinner_init(t_philos *philos, pthread_mutex_t *forks, t_args *args);
void        destroy(pthread_mutex_t *forks, int philos_number);
void        set_forks(pthread_mutex_t *forks, int philos_number);
void        set_philos(t_philos *philos, pthread_mutex_t *forks, t_args *args);
long long   get_time(void);
long long   current_time(long long initial_time);
void        print_status(char *msg, t_philos *philos);
void        monitor_dies(t_philos *philo, int check_time_exceeded);

#endif