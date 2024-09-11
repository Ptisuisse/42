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
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s\n", (get_current_time() - (philo->data->start_time)),
		philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}
