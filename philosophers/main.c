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

t_init	*ft_is_sleeping(t_init *philo)
{
	int	i;

	i = (philo->time_to_sleep * 1000);
	printf("Is sleeping\n");
	usleep(i); /*during time to eat en ms*/
	return (philo);
}

t_init	*ft_is_eating(t_init *philo)
{
	int	i;

	i = (philo->time_to_eat * 1000);
	printf("Is eating\n");
	usleep(i); /*during time to eat en ms*/
	return (philo);
}
void	ft_fork_unlock(t_init *philo)
{
	pthread_mutex_unlock(&philo->R_fork);
	pthread_mutex_unlock(&philo->L_fork);
}

void	ft_fork_lock(t_init *philo)
{
	int	r_fork;
	int	l_fork;

	r_fork = philo->i % philo->nbr_philo;
	l_fork = philo->i - 1;
	if (l_fork % philo->nbr_philo == r_fork - 1)
	{
		pthread_mutex_lock(&philo->L_fork);
		printf("philo %d has taken fork 1\n", philo->i);
		pthread_mutex_lock(&philo->R_fork);
		printf("philo %d has taken fork 2\n", philo->i);
	}
	else
		usleep((philo->time_to_eat)* 1000);
}

void	*routine(t_init *philo)
{
	ft_fork_lock(philo);
	ft_is_eating(philo);
	ft_fork_unlock(philo);
	ft_is_sleeping(philo);
	return (NULL);
}

void	test_thread(t_init *philo)
{
	int	i;

	i = philo->nbr_philo;
	philo->thread = malloc(sizeof(pthread_t) * i);
	while (i)
	{
		usleep(100);
		if (pthread_create(&philo->thread[i], NULL, (void *)routine,
				philo) != 0)
			return ;
		philo->i++;
		i--;
	}
	i = philo->nbr_philo;
	while (i)
	{
		if (pthread_join(philo->thread[i], NULL) != 0)
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
	philo = init_struct(argv);
	/*creation thread dependant nbr philo*/
	test_thread(&philo);
}
