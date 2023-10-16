/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:50:32 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/10/14 22:50:17 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] == 32 || str[i] >= 9 && str[i] <= 13)
			i++;
		if (str[i] == 43 || str [i] == 45)
		{
			if (str[i] == 45)
				j *= -1;
			i++;
		}
		while (str[i] >= '0' && str [i] <= '9')
		{
			k = k * 10 + (str[i] - '0');
			i++;
		}
		return (k * j);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argv;
	printf("%d", ft_atoi(argv[1]));
}
