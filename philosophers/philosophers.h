/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:22:54 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/08/01 15:22:57 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_init
{
	pthread_t		*thread;
	pthread_mutex_t	mutex;
	pthread_mutex_t	m_eat;
	int				nbr_philo;
	int	i;
	size_t			time_eat;
	size_t			time_sleep;
}					t_init;

/*main.c*/
int					check_arg_value(char **arg);
/*error.c*/
void				ft_exit(int i);
/*init_struct*/
t_init				init_struct(char **arg, t_init philo);
#endif