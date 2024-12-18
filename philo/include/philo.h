/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorais <mmorais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:55:13 by mmorais           #+#    #+#             */
/*   Updated: 2024/11/24 22:55:14 by mmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				philo_id;
	int				is_eat;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*is_dead;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*is_dead_mutex;
	pthread_mutex_t	*meal_mutex;
}					t_philo;

typedef struct s_main
{
	int				is_dead_flag;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	print_mutex;
	t_philo			*philos;
}					t_main;

int					check_args(char **argv);
void				destroy_all(t_main *main, pthread_mutex_t *forks);
void				init_main(t_main *main, t_philo *philos);
void				init_forks(pthread_mutex_t *forks, int philo_num);
void				init_philos(t_philo *philos, t_main *main,
						pthread_mutex_t *forks, char **argv);
void				init_input(t_philo *philo, char **argv);
int					thread_create(t_main *main, pthread_mutex_t *forks);
void				*monitor(void *pointer);
void				*philo_routine(void *pointer);
void				eat(t_philo *philo);
void				dream(t_philo *philo);
void				think(t_philo *philo);
int					dead_loop(t_philo *philo);
int					ft_atoi(char *str);
int					ft_usleep(size_t microseconds);
int					ft_strlen(char *str);
void				print_status(char *str, t_philo *philo, int id);
size_t				get_current_time(void);

#endif
