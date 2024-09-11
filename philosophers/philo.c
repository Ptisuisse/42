#include "philosophers.h"

void *routine(void *arg) 
{
    t_philo *philo = (t_philo *)arg;

    if (philo->id % 2 == 0)
        usleep(1000);
    while (1) 
    {
        take_fork(philo);
        ft_is_eating(philo);
        if (!has_died(philo, philo->data))
            break ;
        ft_is_sleeping(philo);
        if (!has_died(philo, philo->data))
            break ;
    }
    return (NULL);
}

void ft_is_sleeping(t_philo *philo) 
{
    printf("%d is sleeping\n", philo->id);
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

int take_fork(t_philo *philo) 
{
    if (pthread_mutex_lock(philo->R_fork) == 0) 
    {
        printf("%d has taken a fork\n", philo->id);
        if (pthread_mutex_lock(philo->L_fork) == 0)
        {
            printf("%d has taken a fork\n", philo->id);
            return (1);
        }
        else
        {
            pthread_mutex_unlock(philo->R_fork);
            ft_printf("IS THINKING\n");
            usleep(500);
        }
    }
    return (0);
}

int has_died(t_philo *philo, t_init *data) 
{
    long current_time = get_current_time_ms();
    long elapsed_time;

    pthread_mutex_lock(&philo->last_meal);
    elapsed_time = current_time - philo->l_meal;
    pthread_mutex_unlock(&philo->last_meal);

    if (elapsed_time > data->time_to_die)
    {
        printf("%d is dead\n", philo->id);
        return (0);
    }
    if (philo->meals_eaten >= data->number_of_times_each_philosopher_must_eat)
    {
        printf("%d has finished\n", philo->id); 
        return (0);
    }
    return (1);
}
