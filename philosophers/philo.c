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

int	ft_is_full(t_philo *philo)
{
	int	i;
	int	nb_philos;
	int	target_meals;

	pthread_mutex_lock(&philo->data->full_mutex);
	if (!philo->data->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_unlock(&philo->data->full_mutex);
		return (1);
	}
	target_meals = philo->data->number_of_times_each_philosopher_must_eat;
	pthread_mutex_unlock(&philo->data->full_mutex);
	pthread_mutex_lock(&philo->data->nbr_of_philo);
	nb_philos = philo->data->number_of_philosophers;
	pthread_mutex_unlock(&philo->data->nbr_of_philo);
	i = 0;
	while (i < nb_philos)
	{
		pthread_mutex_lock(&philo[i].last_meal);
		if (!philo[i].is_full && philo[i].meals_eaten >= target_meals)
		{
			philo[i].is_full = 1;
			pthread_mutex_lock(&philo->data->full_mutex);
			philo->data->num_full_philos++; // Utiliser le compteur persistant
			if (philo->data->num_full_philos >= nb_philos)
			{
				pthread_mutex_unlock(&philo->data->full_mutex);
				log_print("full", philo);
				pthread_mutex_lock(&philo->data->end_of_prog);
				philo->data->end_prog = 0;
				pthread_mutex_unlock(&philo->data->end_of_prog);
				pthread_mutex_unlock(&philo[i].last_meal);
				return (0);
			}
		}
		pthread_mutex_unlock(&philo[i].last_meal);
		i++;
	}
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

void	*ft_supervisor(t_init *data)
{
	int	nb_philos;
	int	i;

	i = 0;
	pthread_mutex_lock(&data->nbr_of_philo);
	nb_philos = data->number_of_philosophers;
	pthread_mutex_unlock(&data->nbr_of_philo);
	while (i < nb_philos)
	{
		if (!ft_died(data->philo))
			break ;
		if (!ft_is_full(data->philo))
			exit(0);
		i++;
	}
	return (NULL);
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

void	ft_is_eating(t_philo *philo)
{
	log_print("is eating", philo);
	pthread_mutex_lock(&philo->last_meal);
	philo->l_meal = get_current_time();
	ft_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->last_meal);
	philo->meals_eaten++;
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
	int	nb_philos;

	pthread_mutex_lock(&philo->data->nbr_of_philo);
	nb_philos = philo->data->number_of_philosophers;
	pthread_mutex_unlock(&philo->data->nbr_of_philo);
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
