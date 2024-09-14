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

int ft_is_full(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->data->number_of_philosophers)
    {
        if (!philo[i].is_full && philo[i].meals_eaten >= philo->data->number_of_times_each_philosopher_must_eat)
        {
            philo[i].is_full = 1;
            pthread_mutex_lock(&philo->data->full_mutex);
            philo->data->num_full_philos++;
            pthread_mutex_unlock(&philo->data->full_mutex);
        }
        i++;
    }
    pthread_mutex_lock(&philo->data->full_mutex);
    if (philo->data->num_full_philos == philo->data->number_of_philosophers)
    {
       //log_print("full", philo);
        philo->data->stop = 0;
        pthread_mutex_unlock(&philo->data->full_mutex);
        return (0);
    }
    pthread_mutex_unlock(&philo->data->full_mutex);
    return (1);
}

int	ft_died(t_philo *philo)
{
	long	current_time;
	long	elapsed_time;
	int		i;

	i = 0;
	while (i < philo->data->number_of_philosophers)
	{
		current_time = get_current_time();
		pthread_mutex_lock(&philo[i].last_meal);
		elapsed_time = current_time - philo[i].l_meal;
		pthread_mutex_unlock(&philo[i].last_meal);
		if (elapsed_time > philo->data->time_to_die)
		{
			log_print("died", &philo[i]);
			philo->data->stop = 0;
			return (0);
		}
		i++;
	}
	return (1);
}

void	*ft_supervisor(t_init *data)
{
	while (1)
	{
		if (!ft_died(data->philo) || !ft_is_full(data->philo))
			break ;
	}
	return (NULL);
}

void	*routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		log_print("is thinking", philo);
		ft_sleep(philo->data->time_to_eat);
	}
	while (philo->data->stop)
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
	pthread_mutex_lock(&philo->last_meal);
	philo->l_meal = get_current_time();
	pthread_mutex_unlock(&philo->last_meal);
	philo->meals_eaten++;
	ft_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
}

int take_fork(t_philo *philo)
{
    if (philo->data->number_of_philosophers == 1)
    {
        pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
        log_print("has taken a fork", philo);
        ft_sleep(philo->data->time_to_die + 1);
        pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
        philo->data->stop = 0;
        return (0);
    }
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
        log_print("has taken a fork", philo);
        pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
        log_print("has taken a fork", philo);
    }
    else
    {
        pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
        log_print("has taken a fork", philo);
        pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
        log_print("has taken a fork", philo);
    }
    return (1);
}

