/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:41:46 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/22 12:41:47 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_check_args(char *str)
{
	char	**args;
	int		i;
	int		j;
	int		count;

	args = ft_split(str, ' ');
	i = 0;
	while (args[i])
	{
		count = 0;
		j = 0;
		while (args[i][j])
		{
			if (!(ft_isdigit(args[i][j])) && (args[i][j] != '+'
					&& args[i][j] != '-'))
				ft_printf("NO DIGIT\n");
			if (args[i][j] == '-' || args[i][j] == '+')
				count++;
			j++;
			if (count > 1)
				ft_printf("- || +\n");
		}
		i++;
	}
	return (args);
}

char	**ft_join_args(char **argv)
{
	int		i;
	char	*str;
	char	**args;

	i = 1;
	str = malloc(sizeof(char) * 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	while (argv[i])
	{
		if (i > 1)
			str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	args = ft_check_args(str);
	return (args);
}
