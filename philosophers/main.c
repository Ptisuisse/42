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
		if (i == 6 /*&& !arg[i]*/)
			break ;
		j = 0;
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j]))
				return (0);
			j++;
		}
		if ((nb = ft_atoi(arg[i])) <= 0 || (nb > 2147483647)
			|| (ft_strlen(arg[i]) > 10))
			return (0);
		i++;
	}
	return (1);
}

void	clean_up(t_init *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->philo->R_fork[i]);
		pthread_mutex_destroy(&data->philo->L_fork[i]);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->philo[i].last_meal);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	free(data->forks);
	free(data->philo);
	free(data);
}

int	main(int argc, char **argv)
{
	t_init	*data;

	data = malloc(sizeof(t_init));
	if (argc < 5 || argc > 6)
		exit(1);
	if (!check_arg_value(argv))
	{
		ft_printf("ERROR\n");
		return (1);
	}
	init_struct(argv, data);
	init_philo(data);
	//clean_up(data);
	return (0);
}
