/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:24:43 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/02/03 17:17:09 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_strrchr(char *s, int c)
{
	char			*str;
	unsigned char	b;
	int				i;

	str = s;
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*dst;

	i = 0;
	dst = (char *)dest;
	str = (char *)src;
	if (dst == 0 && str == 0)
		return (0);
	while (i < n)
	{
		dst[i] = str[i];
		i++;
	}
	return (dst);
}

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char				*ptr;
	unsigned long long	total;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	total = nmemb * size;
	if (total / size != nmemb)
		return (NULL);
	ptr = malloc((sizeof(char) * (size + nmemb + 1)));
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}