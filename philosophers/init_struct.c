/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:53:07 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/08/06 17:53:08 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_init	init_struct(char **arg)
{
	t_init	philo;

	philo.nbr_philo = ft_atoi(arg[1]);
	philo.time_to_eat = ft_atoi(arg[3]);
	philo.time_to_sleep = ft_atoi(arg[4]);
	philo.i = 1;
	pthread_mutex_init(&philo.mutex, NULL);
	//pthread_mutex_init(&philo.m_eat, NULL);
	pthread_mutex_init(&philo.R_fork, NULL);
	pthread_mutex_init(&philo.L_fork, NULL);
	return (philo);
}
/*Init nombre de fouchettes // Time to eat // Time to sleep // */