/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:25:48 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/01 21:33:01 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strchr(const char *s, int c)
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
			return 0;
		i--;
	}
	return 1;
}

void map_conformity(char **map, int count_line)
{
	int	i;
	int	y;
	int	c;
	int	p;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	y = 0;
	if (!(ft_strchr(map[0], '0')))
		printf("MAP NOT CLOSE\n");
	if (!(ft_strchr(map[count_line - 1], '0')))
		printf("MAP NOTE CLOSE\n");
	while (y < count_line)
	{
		i = 0;
		while (map[y][i])
		{
			if (map[y][i] == 'P')
				p++;
			if (map[y][i] == 'C')
				c++;
			if (map[y][i] == 'E')
				e++;
			i++;
		}
		if ((map[y][0] != '1') || (map[y][i - 1] != '1'))
			printf("MAP NOT CLOSE\n");
		y++;
	}
	if ((e != 1) || (c < 1) || (p != 1))
	 	printf("ERROR\n");
}

char **create_tab(int	count_line) 
{
    char **map;
    char *line;
    int y;
	int len;
	int	fd;

    y = 0;
	printf("%d\n", count_line);
    map = malloc(sizeof(char*) * (count_line + 1));
    if (map == NULL)
		return (0);
	fd = open("map.ber", O_RDONLY);
    while (y < count_line) 
	{
        line = get_next_line(fd);
		len = ft_strlen(line);
	    if (line[len - 1] == '\n') 
			line[len - 1] = '\0';
        map[y] = ft_strdup(line);
		free(line);
		printf("%s\n", map[y]);
        y++;
    }
	map[y] = 0;
	map_conformity(map, count_line);
	//flood_fill(map);
	close(fd);
	return (map);
}

void free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

int	main(void)
{
	char *line;
	char **tab;
	int	count_line;
	int fd;

    fd = open("map.ber", O_RDONLY);
	count_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count_line++;
		
	}
	free(line);
	close(fd);
	tab = create_tab(count_line);
	free_tab(tab);
}
