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

int	ft_died(t_philo *philo)
{
	long	current_time;
	long	elapsed_time;

	current_time = get_current_time();
	pthread_mutex_lock(&philo->last_meal);
	elapsed_time = current_time - philo->l_meal;
	pthread_mutex_unlock(&philo->last_meal);
	if (elapsed_time > philo->data->time_to_die)
	{
		log_print("died", philo);
		philo->data->stop = 0;
		return (0);
	}
	return (1);
}

void	*ft_supervisor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(5000);
		if (ft_died(philo) == 0)
		{
			break ;
		}
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		log_print("is thinking", philo);
		ft_sleep(philo->data->time_to_eat);
	}
	while (philo->data->stop == 1)
	{
		take_fork(philo);
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
	log_print("is eating", philo);
	ft_sleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->last_meal);
	philo->l_meal = get_current_time();
	pthread_mutex_unlock(&philo->last_meal);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->L_fork);
	pthread_mutex_unlock(philo->R_fork);
}

int	take_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->R_fork) == 0)
	{
		log_print("has taken a fork", philo);
		if (pthread_mutex_lock(philo->L_fork) == 0)
		{
			log_print("has taken a fork", philo);
			return (1);
		}
	}
	return (0);
}
