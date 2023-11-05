/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:00:49 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/11/05 14:12:46 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	void	*srce;

	i = 0;
	srce = (void)src;
	while (i < n)
	{
		i++;
	}
	return (srce);
}

int	main(void)
{
	int	array [] = {54, 85, 20, 63, 21};
	int	copy = NULL;

	printf("%d", ft_memcpy(copy, array, 10));
/*	for(length = 0; length < 5; length++)
	{
		printf("%d", copy[length]);
	}
	free (copy);
	return EXIT_SUCCESS;*/
}
