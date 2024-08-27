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
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>
#include <stdbool.h>

typedef struct s_philo
{
    int id;
    long l_meal;
	int	meals_eaten;
    pthread_mutex_t *L_fork;
    pthread_mutex_t *R_fork;
    pthread_mutex_t last_meal;
    pthread_t thread;
    struct s_init *data;
} t_philo;

typedef struct s_init
{
    int nbr_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
	int	max_meal;
	long start_time;
    pthread_mutex_t *forks;
    pthread_mutex_t print;
    t_philo *philo;
} t_init;

/*main.c*/
int					check_arg_value(char **arg);
/*error.c*/
void				ft_exit(int i);
/*init_struct*/
void	 init_struct(char **arg, t_init *data);

#endif