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

char	**ft_check_args(char *str, char **args)
{
	int	i;
	int	count;

	i = 0;
	while (str[i])
	{
		count = 0;
		if (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break ;
		if (!(ft_isdigit(str[i])) && (str[i] != '+' && str[i] != '-'))
			ft_error(args, str);
		if (str[i] == '-' || str[i] == '+')
			count++;
		if ((str[i] == '-' || str[i] == '+') && str[i + 1] == ' ')
			ft_error(args, str);
		if (count > 1)
			ft_error(args, str);
		i++;
	}
	str[i - 1] = '\0';
	args = ft_split(str, ' ');
	free(str);
	return (args);
}

// char	**ft_check_args(char *str)
//{
//	char	**args;
//	int		i;
//	int		j;
//	int		count;

//	args = ft_split(str, ' ');
//	i = 0;
//	while (args[i])
//	{
//		count = 0;
//		j = 0;
//		while (args[i][j])
//		{
//			if (!(ft_isdigit(args[i][j])) && (args[i][j] != '+'
//					&& args[i][j] != '-'))
//				ft_error(args, str);
//			if (args[i][j] == '-' || args[i][j] == '+')
//				count++;
//			j++;
//			if (count > 1)
//				ft_error(args, str);
//		}
//		i++;
//	}
//	return (args);
//}

char	**ft_join_args(char **argv)
{
	size_t	i;
	int		len;
	char	*str;
	char	**args;

	i = 1;
	len = 0;
	while (argv[i])
	{
		len += ft_strlen(argv[i++]);
		len++;
	}
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[0] = 0;
	i = 1;
	while (argv[i])
	{
		ft_strcat(str, argv[i++]);
		ft_strcat(str, " ");
	}
	args = NULL;
	args = ft_check_args(str, args);
	return (args);
}
