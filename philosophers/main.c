/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:22:30 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/08/01 15:22:31 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg_value(char **arg)
{
	int	i;
	int	j;
	int	nb;

	i = 1;
	while (arg[i])
	{
		if (i == 6)
			break ;
		j = 0;
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j]))
				return (0);
			j++;
		}
		nb = ft_atoi(arg[i]);
		if (nb <= 0 || (nb > 2147483647) || (ft_strlen(arg[i]) > 10))
			return (0);
		i++;
	}
	return (1);
}

void	cleanup(t_init *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->philo[i].last_meal);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->time_die);
	pthread_mutex_destroy(&data->nbr_of_philo);
	pthread_mutex_destroy(&data->end_of_prog);
	free(data->philo);
	free(data->forks);
}

int	main(int argc, char **argv)
{
	t_init	data;
	t_philo	*philo;

	philo = NULL;
	if (argc < 5 || argc > 6)
		exit(1);
	if (!check_arg_value(argv))
	{
		printf("ERROR\n");
		return (1);
	}
	init_struct(argv, &data);
	init_philo(&data, philo);
	cleanup(&data);
	return (0);
}
