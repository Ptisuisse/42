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

# include <pthread.h>
//# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	long			l_meal;
	int				meals_eaten;
	int				is_full;
	int				l_fork;
	int				r_fork;
	pthread_t		thread;
	pthread_mutex_t	last_meal;
	struct s_init	*data;
}					t_philo;

typedef struct s_init
{
	int				end_prog;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long			start_time;
	pthread_t		supervisor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	must_eat;
	pthread_mutex_t	nbr_of_philo;
	pthread_mutex_t	end_of_prog;
	t_philo			*philo;
}					t_init;

void				create_threads(t_init *data, t_philo *philo);
void				only_one_philo(t_init *data, t_philo *philo);
/*main.c*/
int					check_arg_value(char **arg);
void				cleanup(t_init *data);
/*init_struct.c*/
void				init_struct(char **arg, t_init *data);
void				init_philo(t_init *data, t_philo *philo);
void				join_threads(t_init *data, t_philo *philo);
/*philo.c*/
void				*routine(t_philo *philo);
void				ft_is_eating(t_philo *philo);
int					take_fork(t_philo *philo);
void				ft_is_sleeping(t_philo *philo);
int					check_end_prog(t_philo *philo);
/*ft_supervisor.c*/
int					ft_is_full(t_philo *philo);
int					ft_died(t_philo *philo);
void				*ft_supervisor(t_init *data);
/*time_and_print.c*/
long				get_current_time(void);
void				log_print(char *str, t_philo *philo);
void				ft_sleep(long sleep_time_ms);
/*utils.c*/
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
int					ft_isdigit(int c);

#endif