/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:54:53 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/11/03 09:20:35 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_bzero(void *s, size_t n)
{
	char	*c;

	c = s;
	while (n != 0)
	{
		*c = 0;
		c++;
		n--;
	}
	return (s);
}

int	main(void)
{	
	char	a[10];
	ft_bzero(a, 3);
	bzero(a, 3);
	printf("%s\n", a);
	printf("%s", a);
}
