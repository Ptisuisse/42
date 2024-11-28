/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supervisor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:01:50 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/11/24 19:01:51 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	full_check(t_philo *philo, int nb_philos, int nbr_of_meals)
{
	int	i;
	int	full_count;

	full_count = 0;
	i = 0;
	while (i < nb_philos)
	{
		pthread_mutex_lock(&philo[i].last_meal);
		if (philo[i].meals_eaten >= nbr_of_meals)
			full_count++;
		pthread_mutex_unlock(&philo[i].last_meal);
		i++;
	}
	if (full_count == nb_philos)
	{
		// pthread_mutex_lock(&philo->data->end_of_prog);
		// philo->data->end_prog = 0;
		// pthread_mutex_unlock(&philo->data->end_of_prog);
		return (0);
	}
	return (1);
}

int	ft_is_full(t_philo *philo)
{
	int	nbr_of_meals;
	int	nb_philos;

	nb_philos = 0;
	nbr_of_meals = 0;
	pthread_mutex_lock(&philo->data->nbr_of_philo);
	nb_philos = philo->data->number_of_philosophers;
	pthread_mutex_unlock(&philo->data->nbr_of_philo);
	pthread_mutex_lock(&philo->data->time_die);
	if (philo->data->number_of_times_each_philosopher_must_eat <= 0)
	{
		pthread_mutex_unlock(&philo->data->time_die);
		return (1);
	}
	nbr_of_meals = philo->data->number_of_times_each_philosopher_must_eat;
	pthread_mutex_unlock(&philo->data->time_die);
	if (!full_check(philo, nb_philos, nbr_of_meals))
		return (0);
	return (1);
}

int	end_prog_died(t_philo *philo, int i)
{
	log_print("died", &philo[i]);
	pthread_mutex_lock(&philo->data->end_of_prog);
	philo->data->end_prog = 0;
	pthread_mutex_unlock(&philo->data->end_of_prog);
	return (0);
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
		current_time = get_current_time();
		pthread_mutex_lock(&philo[i].last_meal);
		elapsed_time = current_time - philo[i].l_meal;
		if (elapsed_time > philo->data->time_to_die)
		{
			end_prog_died(philo, i);
			// pthread_mutex_unlock(&philo[i].last_meal);
		}
		pthread_mutex_unlock(&philo[i].last_meal);
		i++;
	}
	return (1);
}

void	*ft_supervisor(t_init *data)
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
