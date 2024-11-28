/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_and_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:01:43 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/11/24 19:01:45 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	log_print(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->end_of_prog);
	if (philo->data->end_prog)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%ld %d %s\n", (get_current_time() - (philo->data->start_time)),
			philo->id, str);
		pthread_mutex_unlock(&philo->data->print);
	}
	pthread_mutex_unlock(&philo->data->end_of_prog);
}

void	ft_sleep(long sleep_time_ms)
{
	usleep(sleep_time_ms * 1000);
}

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

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
