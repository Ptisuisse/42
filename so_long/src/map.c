/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:25:48 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/08 22:36:28 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	bol_chr(const char *s, int c)
{
	int				i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return (0);
		i--;
	}
	return (1);
}

int	check_PCE(t_map *mapping, int y)
{
	int x;
	x = 0;
	while (mapping->map[y][x])
	{
		if (mapping->map[y][x] == 'P')
		{
			mapping->y_P = y;
			mapping->x_P = x;
			mapping->p++;
		}
		if (mapping->map[y][x] == 'C')
			mapping->c++;
		if (mapping->map[y][x] == 'E')
			mapping->e++;
		if (mapping->map[y][x] != 'P' && mapping->map[y][x] != 'C' && mapping->map[y][x] != 'E' && mapping->map[y][x] != '1' && mapping->map[y][x] != '0')
			printf("ERROR %d :\nAt [%d, %d] [ASCII]%d is not available\n", (mapping->nbr_err += 1), x, y, mapping->map[y][x]);
		x++;
	}
	if ((mapping->map[y][0] != '1') || (mapping->map[y][x - 1] != '1'))
		printf("ERROR %d :\nMAP NOT CLOSE at [%d, %d]\n", (mapping->nbr_err += 1), x, y);
	return (1);
}

int map_conformity(t_map *mapping, int count_line)
{
	int	y;

	y = 0;
	mapping->e = 0;
	mapping->c = 0;
	mapping->p = 0;
	if (!(bol_chr(mapping->map[y], '0')))
		printf("ERROR %d :\nFirst line not close\n", (mapping->nbr_err += 1));
	if (!(bol_chr(mapping->map[count_line - 1], '0')))
		printf("ERROR %d :\nLast line not close\n", (mapping->nbr_err += 1));
	y = 1;
	while (y< count_line - 1 && (check_PCE(mapping, y)))
		y++;
	if (mapping->e != 1)
		printf("ERROR %d :\nIncorrect number of EXIT (1 needed)\n", (mapping->nbr_err += 1));
	if (mapping->c < 1)
		printf("ERROR %d :\nIncorrect number of Collectible (min. 1 needed)\n", (mapping->nbr_err += 1));
	if (mapping->p != 1)
		printf("ERROR %d :\nIncorrect number of Player (1 needed)\n", (mapping->nbr_err += 1));
	if (mapping->p == 1)
		playable_map(mapping);
	return (1);
}

void	create_tab(int count_line, t_map *mapping) 
{
	char	*char_map;
    char	*line;
    int	y;
	int	fd;

    y = 0;
	char_map = malloc(sizeof(char) * (count_line + 1));
    if (char_map == NULL)
		return ;
	char_map[0] = '\0';
	fd = open("map.ber", O_RDONLY);
    while (y < count_line) 
	{
        line = get_next_line(fd);
		char_map = free_strjoin(char_map, line);
		free(line);
        y++;
    }
	mapping->map = ft_split(char_map, '\n');
	mapping->tmp_map = ft_split(char_map, '\n');
	free(char_map);
	map_conformity(mapping, count_line);
	close(fd);
	return ;
}

void free_map(char **tab)
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

void	init_map(t_map *mapping)
{
	char *line;
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
	create_tab(count_line, mapping);
}
