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
#include <unistd.h>

// void	map_conformity(char **map)
// {
	
// }

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

void wall_map(char **map, int count_line)
{
	int	i;
	int	y;

	y = 0;
	if (!(ft_strchr(map[0], '0')))
		printf("MAP NOT CLOSE\n");
	if (!(ft_strchr(map[count_line - 1], '0')))
		printf("MAP NOTE CLOSE\n");
	while (y < count_line)
	{
		i = 0;
		while (map[y][i])
			i++;
		if ((map[y][0] != '1') || (map[y][i - 1] != '1'))
			printf("MAP NOT CLOSE\n");
		y++;
	}
}

void create_tab(int	count_line) 
{
    char **map;
    char *line;
    int y;
	int	fd;

    y = 0;
    map = malloc(sizeof(char*) * count_line);
    if (map == NULL)
		return ;
	fd = open("map.ber", O_RDONLY);
    while (1) 
	{
        line = get_next_line(fd);
        if (line == NULL)
            break;
	    if (line[ft_strlen(line) - 1] == '\n') 
			line[ft_strlen(line) - 1] = '\0';
        map[y] = ft_strdup(line);
		//printf("%s\n", map[y]);
        y++;
    }
	wall_map(map, count_line);
	//map_conformity(map);
	close(fd);
}

int main(void)
{
    int fd;
	int	count_line;

	count_line = 0;
    fd = open("map.ber", O_RDONLY);
	while (get_next_line(fd) != NULL)
		count_line++;
	create_tab(count_line);
	close(fd);
}
