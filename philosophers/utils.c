/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:17:53 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/09/11 10:17:54 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	log_print(char *str, t_philo *philo)
{
	if (philo->data->stop)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%ld %d %s\n", (get_current_time() - (philo->data->start_time)) , philo->id, str);
		pthread_mutex_unlock(&philo->data->print);
	}
	return ;
}

void	ft_sleep(long sleep_time_ms)
{
	usleep(sleep_time_ms * 1000);
}

long	get_current_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}