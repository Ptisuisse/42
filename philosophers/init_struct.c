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

t_init	init_struct(char **arg, t_init philo)
{
	philo.nbr_philo = ft_atoi(arg[1]);
	philo.i = ft_atoi(arg[1]);
	philo.time_eat = ft_atoi(arg[3]);
	philo.time_sleep = ft_atoi(arg[4]);
	pthread_mutex_init(&philo.mutex, NULL);
	pthread_mutex_init(&philo.m_eat, NULL);
	return (philo);
}