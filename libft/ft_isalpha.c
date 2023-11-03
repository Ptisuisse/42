/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:12:13 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/11/02 10:56:39 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <unistd.h>
#include <stdio.h>

int	ft_isalpha(int	c)
{
	if (c >= 65 && c <= 90 || c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

int	main(void)
{
	char	a = '1';
	printf("%d\n", ft_isalpha(a));
	printf("%d", isalpha(a));
}

