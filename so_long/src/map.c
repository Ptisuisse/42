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
	int	j;

	j = 0;
	i = ft_strlen(s);
	while (j < i)
	{
		if (s[j] != c)
			return (0);
		j++;
	}
	return (1);
}

void	create_tab(t_map *mapping, char *argv)
{
	char	*line;
	int		y;
	int		fd;

	y = 0;
	mapping->char_map = malloc(sizeof(char) * (mapping->count_line + 1));
	if (mapping->char_map == NULL)
		return ;
	mapping->char_map[0] = '\0';
	fd = open(argv, O_RDONLY);
	while (y < mapping->count_line)
	{
		line = get_next_line(fd);
		mapping->char_map = free_strjoin(mapping->char_map, line);
		check_line(mapping, fd);
		free(line);
		y++;
	}
	get_next_line(fd);
	close(fd);
	split_map(mapping);
	return ;
}

void	split_map(t_map *mapping)
{
	mapping->map = ft_split(mapping->char_map, '\n');
	mapping->tmp_map = ft_split(mapping->char_map, '\n');
	free(mapping->char_map);
	map_conformity(mapping);
	ft_sizeof_window(mapping);
}

void	init_map(t_map *mapping, char *argv)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR\n");
		close(fd);
		exit (1);
	}
	line = get_next_line(fd);
	if (line == NULL)
		ft_empty_line(mapping, line, fd);
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
