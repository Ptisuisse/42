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
	int	i;

	data->num_full_philos = 0;
	data->number_of_philosophers = ft_atoi(arg[1]);
	data->forks = malloc(sizeof(pthread_mutex_t)
			* data->number_of_philosophers);
	data->time_to_die = ft_atoi(arg[2]);
	data->time_to_eat = ft_atoi(arg[3]);
	data->time_to_sleep = ft_atoi(arg[4]);
	if (arg[5])
		data->number_of_times_each_philosopher_must_eat = ft_atoi(arg[5]);
	else
		data->number_of_times_each_philosopher_must_eat = -1;
	data->end_prog = 1;
	i = 0;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->time_die, NULL);
	pthread_mutex_init(&data->nbr_of_philo, NULL);
	pthread_mutex_init(&data->end_of_prog, NULL);
	while (i < ft_atoi(arg[1]))
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	init_philo(t_init *data, t_philo *philo)
{
	int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->number_of_philosophers);
	data->start_time = get_current_time();
	data->philo = philo;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(&philo[i].last_meal, NULL);
		philo[i].id = i + 1;
		philo[i].is_full = 0;
		philo[i].r_fork = i;
		philo[i].l_fork = ((i + 1) % data->number_of_philosophers);
		philo[i].meals_eaten = 0;
		philo[i].data = data;
		philo[i].l_meal = get_current_time();
		i++;
	}
	create_threads(data, philo);
}

void	create_threads(t_init *data, t_philo *philo)
{
	int	i;

	i = 0;
	if (data->number_of_philosophers == 1)
	{
		only_one_philo(data, philo);
		return ;
	}
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread, NULL, (void *)routine,
				(void *)&philo[i]) != 0)
			return ;
		i++;
	}
	if (pthread_create(&data->supervisor, NULL, (void *)ft_supervisor,
			(void *)data) != 0)
		return ;
	join_threads(data, philo);
}

void	join_threads(t_init *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return ;
		i++;
	}
	if (pthread_join(data->supervisor, NULL) != 0)
		return ;
}
