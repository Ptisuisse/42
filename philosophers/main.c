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
		if ((nb = ft_atoi(arg[i])) <= 0 || nb > 2147483647
			|| (ft_strlen(arg[i]) > 10))
			return (0);
		i++;
	}
	return (1);
}

void ft_sleep(long sleep_time_ms) 
{
    usleep(sleep_time_ms * 1000);
}

long get_current_time_ms() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void ft_is_sleeping(t_philo *philo) 
{
    printf("%d Philosopher is sleeping\n", philo->id);
    ft_sleep(philo->data->time_to_sleep);
}

void ft_is_eating(t_philo *philo) 
{
    printf("%d is eating\n", philo->id);
    ft_sleep(philo->data->time_to_eat);
    pthread_mutex_lock(&philo->last_meal);
    philo->l_meal = get_current_time_ms();
    pthread_mutex_unlock(&philo->last_meal);
    philo->meals_eaten++; 
    pthread_mutex_unlock(philo->L_fork);
    pthread_mutex_unlock(philo->R_fork);
}


void take_fork(t_philo *philo) 
{
    if (philo->id % 2 == 0) 
    {
        pthread_mutex_lock(philo->R_fork);
        printf("%d has taken the right fork\n", philo->id);
        pthread_mutex_lock(philo->L_fork);
        printf("%d has taken the left fork\n", philo->id);
    } 
    else 
    {
        pthread_mutex_lock(philo->L_fork);
        printf("%d has taken the left fork\n", philo->id);
        pthread_mutex_lock(philo->R_fork);
        printf("%d has taken the right fork\n", philo->id);

    }
}


// int has_died(t_philo *philo, t_init *data)
// {
//     long current_time = get_current_time_ms();
//     long elapsed_time;

//     pthread_mutex_lock(&philo->last_meal);
//     elapsed_time = current_time - philo->l_meal;
//     pthread_mutex_unlock(&philo->last_meal);

//     if (elapsed_time > data->time_to_die)
//         return 1;

//     return 0;
// }

int has_died(t_philo *philo, t_init *data) {
    long current_time = get_current_time_ms();
    long elapsed_time;

    pthread_mutex_lock(&philo->last_meal);
    elapsed_time = current_time - philo->l_meal;
    pthread_mutex_unlock(&philo->last_meal);

    if (elapsed_time > data->time_to_die)
        return 1;
    if (philo->meals_eaten == data->max_meal) {
        return 2;
    }
    return 0;
}

void *routine(void *arg) 
{
    t_philo *philo = (t_philo *)arg;
    int death_status;

    while (1) 
    {
        pthread_mutex_lock(&philo->data->print);
        take_fork(philo);
        ft_is_eating(philo);
        pthread_mutex_unlock(&philo->data->print);
        death_status = has_died(philo, philo->data);
        if (death_status == 1) 
        {
            pthread_mutex_lock(&philo->data->print);
            printf("%d is dead\n", philo->id);
            pthread_mutex_unlock(&philo->data->print);
            return (NULL);
        } 
        else if (death_status == 2) 
        {
            pthread_mutex_lock(&philo->data->print);
            printf("%d has finished eating.\n", philo->id);
            pthread_mutex_unlock(&philo->data->print);
            return (NULL);
        }
        ft_is_sleeping(philo);
    }
    return (NULL);
}

void init_philo(t_init *data)
{
    int i;

    i = 0;
    while (i < data->nbr_philo)
    {
        data->philo[i].id = i + 1;
        data->philo[i].R_fork = &data->forks[i];
        data->philo[i].L_fork = &data->forks[(i + 1) % data->nbr_philo];
        data->philo[i].meals_eaten = 0;
        pthread_mutex_init(&data->philo[i].last_meal, NULL);
        pthread_mutex_init(&data->forks[i], NULL);
        data->philo[i].data = data;
        if (pthread_create(&data->philo[i].thread, NULL, routine, &data->philo[i]) != 0)
            return;
        i++;
    }
    i = 0;
    while (i < data->nbr_philo)
    {
        if (pthread_join(data->philo[i].thread, NULL) != 0)
            return;
        i++;
    }
}

void clean_up(t_init *data)
{
    int i;

    i = 0;
    while (i < data->nbr_philo)
    {
        pthread_mutex_destroy(&data->forks[i]);
        pthread_mutex_destroy(&data->philo[i].last_meal);
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
	clean_up(data);
	return (0);
}
