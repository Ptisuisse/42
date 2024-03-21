/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:25:48 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/21 16:54:42 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	bol_chr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return (0);
		i--;
	}
	return (1);
}

void	create_tab(t_map *mapping, char *argv)
{
	char	*char_map;
	char	*line;
	int		y;
	int		fd;

	y = 0;
	char_map = malloc(sizeof(char) * (mapping->count_line + 1));
	if (char_map == NULL)
		return ;
	char_map[0] = '\0';
	fd = open(argv, O_RDONLY);
	while (y < mapping->count_line)
	{
		line = get_next_line(fd);
		char_map = free_strjoin(char_map, line);
		free(line);
		y++;
	}
	mapping->map = ft_split(char_map, '\n');
	mapping->tmp_map = ft_split(char_map, '\n');
	free(char_map);
	map_conformity(mapping);
	ft_sizeof_window(mapping);
	close(fd);
	return ;
}

void	init_map(t_map *mapping, char *argv)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		mapping->count_line++;
	}
	free(line);
	close(fd);
	create_tab(mapping, argv);
}
