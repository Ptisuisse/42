/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:29:05 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/11/02 16:58:23 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = s;
	while (n != 0)
	{
		*str = c;
		str++;
		n--;
	}
	return (s);
}

int	main(void)
{
	char	a[10];
	ft_memset(a, 'a', 3);
	memset(a, 'c', 3);
	printf("%s\n", a);
	printf("%s", a);
}
