/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:24:40 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/11/05 14:28:03 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

int	ft_strlen(char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*stc;

	stc = (char*)src;
	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(stc));
	while (dst[j] != '\0' && j < size - 1)
	{
		j++;
	}
	while (i < size)
	{
		dst[j+i] = stc[i];
		i++;
	}
	dst[j+i] = '\0';
	return (j+i);
}

int	main(void)
{
	char	dest [] = "Hello";
	char	src [] = "World!";

	printf("src : %s\n dest:%s\n %zu",src, dest, ft_strlcat(dest, src, 0));
}
