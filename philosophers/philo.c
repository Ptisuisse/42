#include "philosophers.h"

/*supervisor*/

int	ft_supervisor(t_philo *philo)
{
	long	current_time;
	long	elapsed_time;

	current_time = get_current_time();
	pthread_mutex_lock(&philo->last_meal);
	elapsed_time = current_time - philo->l_meal;
	pthread_mutex_unlock(&philo->last_meal);
	if (elapsed_time > philo->data->time_to_die)
	{
		log_print("died", philo);
		return (0);
	}
	if (philo->meals_eaten >= philo->data->number_of_times_each_philosopher_must_eat)
	{
		return (0);
	}
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		log_print("is thinking", philo);
		ft_sleep(philo->data->time_to_eat);
	}
	while (ft_supervisor(philo))
	{
		take_fork(philo);
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
	ft_sleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->last_meal);
	philo->l_meal = get_current_time();
	pthread_mutex_unlock(&philo->last_meal);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->L_fork);
	pthread_mutex_unlock(philo->R_fork);
}

int	take_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->R_fork) == 0)
	{
		log_print("has taken a fork", philo);
		if (pthread_mutex_lock(philo->L_fork) == 0)
		{
			log_print("has taken a fork", philo);
			return (1);
		}
	}
	return (0);
}
