/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:14:51 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/09/11 14:14:53 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		log_print("is thinking", philo);
		usleep(100);
	}
	while (check_end_prog(philo))
	{
		if (!take_fork(philo))
			break ;
		ft_is_eating(philo);
		ft_is_sleeping(philo);
		log_print("is thinking", philo);
	}
	return (NULL);
}

void	ft_is_sleeping(t_philo *philo)
{
	log_print("is sleeping", philo);
	ft_sleep(philo->data->time_to_sleep);
}

void	ft_is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal);
	philo->l_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->last_meal);
	log_print("is eating", philo);
	ft_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
}

int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
	log_print("has taken a fork", philo);
	pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
	log_print("has taken a fork", philo);
	return (1);
}

void	only_one_philo(t_init *data, t_philo *philo)
{
	pthread_mutex_lock(&data->forks[0]);
	log_print("has taken a fork", &philo[0]);
	ft_sleep(data->time_to_die + 1);
	log_print("is died", &philo[0]);
	pthread_mutex_unlock(&data->forks[0]);
	pthread_mutex_lock(&data->end_of_prog);
	data->end_prog = 0;
	pthread_mutex_unlock(&data->end_of_prog);
}
