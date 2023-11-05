/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:01:20 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/11/05 12:20:06 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	j;
	char	*str;

	str = (char*)src;
	j = 0;
	while (j < size)
	{
		dst[j] = str[j];
		j++;
	}
	dst[j] = '\0';
	return (j);
}
/*
int	main()
{
	char	src[200] = "";
	char	dest[10];

	printf("src : %s\n dest : %s\n strlcpy : %zu\n", src, dest, ft_strlcpy(dest, src, 15));
}*/
