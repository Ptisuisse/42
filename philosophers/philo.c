#include "philosophers.h"

/*log_print + time_stamp + supervisor*/

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		log_print("is thinking", philo);
		ft_sleep(philo->data->time_to_eat);
	}
	while (1)
	{
		take_fork(philo);
		ft_is_eating(philo);
		ft_is_sleeping(philo);
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
		else
			pthread_mutex_unlock(philo->R_fork);
	}
	return (0);
}

