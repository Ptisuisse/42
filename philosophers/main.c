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
#include <stdio.h>

int	check_arg_value(char **arg)
{
	int	i;
	int	j;
	int	nb;

	i = 1;
	while (arg[i])
	{
		if (i == 6 && !arg[i])
			break ;
		j = 0;
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j]))
				return (0);
			j++;
		}
		if ((nb = ft_atoi(arg[i])) <= 0 || nb > 2147483647
			|| (ft_strlen(arg[i]) > 10))
			return (0);
		i++;
	}
	return (1);
}

void	ft_test(t_init philo)
{
	usleep(5000);
	printf("TEST%d\n", philo.i);
}

void	*routine(t_init philo)
{
	pthread_mutex_lock(&philo.mutex);
	philo.i += 1;
	ft_test(philo);
	pthread_mutex_unlock(&philo.mutex);
	return (NULL);
}

void	test_thread(char *arg, t_init philo)
{
	int	i;

	i = ft_atoi(arg);
	philo.thread = malloc(sizeof(pthread_t) * i);
	while (i)
	{
		if (pthread_create(&philo.thread[i], NULL, (void *)routine,
				(void *)&philo) != 0)
			return ;
		i--;
	}
	i = ft_atoi(arg);
	while (i)
	{
		if (pthread_join(philo.thread[i], NULL) != 0)
			return ;
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_init	philo;

	if (argc < 5 || argc > 6)
		ft_exit(1);
	if (!check_arg_value(argv))
	{
		ft_printf("ERROR\n");
		return (1);
	}
	/*init struct valeur argv*/
	init_struct(argv, philo);
	/*creation thread dependant nbr philo*/
	test_thread(argv[1], philo);
}
