/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:25:48 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/02/23 18:05:19 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		dest = malloc(sizeof(char) * 1);
		if (dest == NULL)
			return (0);
		*dest = '\0';
		return (dest);
	}
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] != '\0' && j < len)
		dest[j++] = s[i++];
	dest[j] = '\0';
	return (dest);
}


static	void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

static int	count_sep(char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (s[0] != c && s[0] != '\0')
		j++;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c) && (s[i + 1] != '\0'))
			j++;
		i++;
	}
	return (j);
}

static char	**word_cpy(char *s, char c, char **tab, int j)
{
	size_t	i;

	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (s[i] != c && s[i] != '\0')
				i++;
			tab[j] = ft_substr(s, 0, i);
			if (!tab[j])
			{
				free_tab(tab);
				break ;
			}
			s = (s + i);
			j++;
		}
		else
			s++;
	}
	return (tab);
}

char	**ft_split(char *s, char c, int j)
{
	char	**split;

	if (!s)
		return (NULL);
	split = calloc(((count_sep(s, c)) + 1), sizeof(char *));
	if (split == NULL)
		return (NULL);
	word_cpy(s, c, split, j);
	return (split);
}

void    create_tab(int fd)
{
    char    **map;
    char    c;
    int j;

    j = 0;
    c = '\n';
    while(1)
    {
       map = ft_split(get_next_line(fd), c, j);
        if (map == NULL)
            break ;
        j++;
    }
    //check_map(map, i);
}

int main(void)
{
    int fd;

    fd = open("map.ber", O_RDONLY);
    create_tab(fd);
}
