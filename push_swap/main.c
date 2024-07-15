/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 21:13:10 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/14 21:13:11 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_check_sign(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (argv[i])
	{
		j = 0;
		count = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				count++;
				if ((count > 1) || (!(ft_isdigit(argv[i][j + 1]))))
				{
					ft_printf("ERROR\n");
					break ;
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_args(char **argv)
{
	char	*str;
	int		i;

	i = 1;
	str = malloc(sizeof(char) * 1);
	if (str == NULL)
		return ;
	while (argv[i])
	{
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
		{
			if ((str[i] != '+' || str[i] != '-') && !(ft_isdigit(str[i + 1])))
			{
				ft_printf("NOK");
				break ;
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		ft_printf("ERROR : Nbr of args\n");
		exit(1);
	}
	ft_check_sign(argv);
	/*Verifier argc argv : nbr de param // is_digit // + et - // ' '
		// INTMAX */
	ft_check_args(argv);
	/*init struct*/
}
