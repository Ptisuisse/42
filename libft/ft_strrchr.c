/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:02:13 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/11/04 17:29:51 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*dest;
	int	i;
	int	j;

	i = 0;
	j = 0;
	dest = (char*)s;
	while(dest[i] != '\0')
	{
		if (dest[i] == c)
			j = i;
		i++;
	}
	if (dest[i] == c && dest[i] == '\0')
		return (&dest[i]);
	if (j == 0)
		return (0);
	return (&dest[j]);
}

int	main(void)
{
	char	src[] = "yestyuhf";

	printf("%s\n", ft_strrchr(src, 'u'));
	printf("%s\n", strrchr(src, 'u'));
}
