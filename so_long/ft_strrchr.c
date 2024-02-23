/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:02:13 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/02/23 16:28:58 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	unsigned char	b;
	int				i;

	str = (char *)s;
	i = ft_strlen(str);
	b = c;
	while (i >= 0)
	{
		if (str[i] == b)
			return (&str[i]);
		i--;
	}
	return (0);
}
