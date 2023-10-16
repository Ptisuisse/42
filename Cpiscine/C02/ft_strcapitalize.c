/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:57:23 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/10/16 15:57:43 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && (str[i] >= 97 && str[i] <= 122))
			str[i] -= 32;
		if (str[i] == 32 && (str[i + 1] >= 97 && str[i + 1] <= 122))
			str[i + 1] -= 32;
		if (str[i] >= 33 && str[i] <= 47 && (str[i + 1] >= 97 && str[i + 1] <= 122))
			str[i + 1] -= 32;
		write (1, &str[i], 1);
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			ft_strcapitalize(argv[i]);
			write (1, " ", 1);
			i++;
		}
	}
}
