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

int	check_end_prog(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->end_of_prog);
	if (!philo->data->end_prog)
	{
		pthread_mutex_unlock(&philo->data->end_of_prog);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->end_of_prog);
	return (1);
}

int ft_is_full(t_philo *philo)
{
    int full_count;
    int i;

    pthread_mutex_lock(&philo->data->full_mutex);
    if (philo->data->number_of_times_each_philosopher_must_eat <= 0)
    {
        pthread_mutex_unlock(&philo->data->full_mutex);
        return (0);
    }

    full_count = 0;
    i = 0;
    while (i < philo->data->number_of_philosophers)
    {
        pthread_mutex_lock(&philo[i].last_meal);
        if (philo[i].meals_eaten >= philo->data->number_of_times_each_philosopher_must_eat)
            full_count++;
        pthread_mutex_unlock(&philo[i].last_meal);
        i++;
    }

    if (full_count == philo->data->number_of_philosophers)
    {
        pthread_mutex_lock(&philo->data->end_of_prog);
        philo->data->end_prog = 0;
        pthread_mutex_unlock(&philo->data->end_of_prog);
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
	int		nb_philos;

	i = 0;
	pthread_mutex_lock(&philo->data->nbr_of_philo);
	nb_philos = philo->data->number_of_philosophers;
	pthread_mutex_unlock(&philo->data->nbr_of_philo);
	while (i < nb_philos)
	{
		pthread_mutex_lock(&philo[i].last_meal);
		current_time = get_current_time();
		elapsed_time = current_time - philo[i].l_meal;
		if (elapsed_time > philo->data->time_to_die)
		{
			log_print("died", &philo[i]);
			pthread_mutex_lock(&philo->data->end_of_prog);
			philo->data->end_prog = 0;
			pthread_mutex_unlock(&philo->data->end_of_prog);
			pthread_mutex_unlock(&philo[i].last_meal);
			return (0);
		}
		pthread_mutex_unlock(&philo[i].last_meal);
		i++;
	}
	return (1);
}

void *ft_supervisor(t_init *data)
{
    while (1)
    {
        pthread_mutex_lock(&data->end_of_prog);
        if (!data->end_prog)
        {
            pthread_mutex_unlock(&data->end_of_prog);
            return (NULL);
        }
        pthread_mutex_unlock(&data->end_of_prog);

        if (!ft_died(data->philo) || !ft_is_full(data->philo))
        {
            pthread_mutex_lock(&data->end_of_prog);
            data->end_prog = 0;
            pthread_mutex_unlock(&data->end_of_prog);
            return (NULL);
        }
        usleep(100);
    }
}

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

void ft_is_eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->last_meal);
    philo->l_meal = get_current_time();
    log_print("is eating", philo);
    pthread_mutex_unlock(&philo->last_meal);
    ft_sleep(philo->data->time_to_eat);
    pthread_mutex_lock(&philo->last_meal);
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->last_meal);
    if (philo->id % 2 == 0)
    {
        pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
        pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
    }
    else
    {
        pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
        pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
    }
}
int	take_fork(t_philo *philo)
{
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
