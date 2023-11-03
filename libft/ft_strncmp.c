/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:19:55 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/11/03 14:45:05 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *dest, char *src, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (dest[i] > src[i])
			return (dest[i] - src[i]);
		if (dest[i] < src[i])
			return (dest[i] - src[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	char	dest [] = "Test3";
	char	src [] = "Test3";

	printf("%d\n", ft_strncmp(dest, src, 5));
	printf("%d", strncmp(dest, src, 5));
}
