/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:30:24 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/10/16 14:32:10 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

/* int	strlen(char *str)
{
	int	i

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
} */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[i])
		{
			i = 0;
			while (to_find[i] != '\0')
			{
				if (str[i] != to_find[i])
					tmp += 1;
				i++;
			}
			if (tmp == 0)
				return (str);
		}
		i++;
	}
	return(NULL);
}

int	main(void)
{
	char	s1[255] = "Test";
	char	s2[255] = "Test";

	printf("%s\n", ft_strstr(s1, s2));
	printf("%s", strstr(s1, s2));
}
