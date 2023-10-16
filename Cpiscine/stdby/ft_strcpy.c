/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:16:18 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/10/14 23:43:38 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	while (dest[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main (int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%s\n", ft_strcpy(argv[1], argv[2]));
		printf("%s", strcpy(argv[1], argv[2]));
	}
}
