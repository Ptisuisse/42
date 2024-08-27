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

void init_struct(char **arg, t_init *data) 
{
    data->nbr_philo = ft_atoi(arg[1]);
    data->philo = malloc(sizeof(t_philo) * data->nbr_philo);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
    data->time_to_die = ft_atoi(arg[2]);
    data->time_to_eat = ft_atoi(arg[3]);
    data->time_to_sleep = ft_atoi(arg[4]);
	if (arg[5])
		data->max_meal = ft_atoi(arg[5]);

    pthread_mutex_init(&data->print, NULL);
}