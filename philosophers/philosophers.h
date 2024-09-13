/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:22:54 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/08/01 15:22:57 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_philo
{
	int				id;
	long			l_meal;
	int				meals_eaten;
	pthread_mutex_t	*L_fork;
	pthread_mutex_t	*R_fork;
	pthread_mutex_t	last_meal;
	pthread_t		thread;
	struct s_init	*data;
}					t_philo;

typedef struct s_init
{
	int	stop;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long			start_time;
	pthread_t		supervisor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_philo			*philo;
}					t_init;

/*main.c*/
int					check_arg_value(char **arg);
void				clean_up(t_init *data);
/*error.c*/
void				ft_exit(int i);
/*init_struct.c*/
void				init_struct(char **arg, t_init *data);
void				init_philo(t_init *data);
/*philo.c*/
void				*routine(void *arg);
void				ft_is_eating(t_philo *philo);
int					take_fork(t_philo *philo);
void				ft_is_sleeping(t_philo *philo);
// int					has_died(t_philo *philo, t_init *data);
/*time.c*/
void				ft_sleep(long sleep_time_ms);
long				get_current_time(void);
/*utils.c*/
void				log_print(char *str, t_philo *philo);
void				init_data_philo(t_init *data, int i);

void	*ft_supervisor(void *philo);
void				ft_join_threads(t_philo *philo);

#endif