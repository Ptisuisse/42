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

void	init_struct(char **arg, t_init *data)
{
	data->number_of_philosophers = ft_atoi(arg[1]);
	data->philo = malloc(sizeof(t_philo) * data->number_of_philosophers);
	data->forks = malloc(sizeof(pthread_mutex_t)
			* data->number_of_philosophers);
	data->time_to_die = ft_atoi(arg[2]);
	data->time_to_eat = ft_atoi(arg[3]);
	data->time_to_sleep = ft_atoi(arg[4]);
	if (arg[5])
		data->number_of_times_each_philosopher_must_eat = ft_atoi(arg[5]);
}

void	init_philo(t_init *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		init_data_philo(data, i);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return ;
		i++;
	}
}
 void	init_data_philo(t_init *data, int i)
{
	data->philo[i].id = i + 1;
	data->philo[i].R_fork = &data->forks[i];
	data->philo[i].L_fork = &data->forks[(i + 1)
		% data->number_of_philosophers];
	//if (data->number_of_philosophers % 2)
	//{
	//	data->philo[i].L_fork = &data->forks[i];
	//	data->philo[i].R_fork = &data->forks[(i + 1)
	//		% data->number_of_philosophers];
	//}
	data->philo[i].meals_eaten = 0;
	pthread_mutex_init(&data->philo[i].last_meal, NULL);
	data->philo[i].data = data;
	pthread_mutex_init(&data->print, NULL);
	data->start_time = get_current_time();
	if (pthread_create(&data->philo[i].thread, NULL, routine,
			&data->philo[i]) != 0)
		return ;
	data->philo[i].l_meal = get_current_time();
}
