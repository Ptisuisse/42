/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:24:43 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/01/30 06:50:08 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char *ft_strrchr(char *s, int c) 
{
    const char *last_occurrence = NULL;

    // Iterate through the string until the end
    while (*s != '\0') {
        // If the character matches, update last occurrence
        if (*s == (char)c) {
            last_occurrence = s;
        }
        s++; // Move to the next character
    }

    // If the character was found, return its address
    if (last_occurrence != NULL) {
        return (char *)last_occurrence;
    } else {
        return NULL; // Character not found
    }
}


// char	*ft_strrchr(char *s, int c)
// {
// 	char			*str;
// 	unsigned char	b;
// 	int				i;

// 	str = s;
// 	i = ft_strlen(str);
// 	b = c;
// 	while (i >= 0)
// 	{
// 		if (str[i] == b)
// 			return (&str[i]);
// 		i--;
// 	}
// 	return (0);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	int		ls1;
	int		ls2;
	char	*news;

	if (!s1 || !s2)
		return (0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	news = calloc((ls1 + ls2 + 1), sizeof(char));
	if (news == NULL)
		return (NULL);
	memcpy(news, s1, ls1);
	ls2 = 0;
	while (s2[ls2] != '\0')
	{
		news[ls1] = s2[ls2];
		ls1++;
		ls2++;
	}
	return (news);
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
