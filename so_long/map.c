/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:25:48 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/03 12:24:48 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

int	bol_chr(const char *s, int c)
{
	int				i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return 0;
		i--;
	}
	return 1;
}

void map_conformity(t_map *mapping, int count_line)
{
	t_conf	*conf;
	int	x;
	int	y;

	conf = malloc(sizeof(t_conf));
	if (conf == NULL)
		return ;
	conf->p = 0;
	conf->c = 0;
	conf->e = 0;
	if (!(bol_chr(mapping->map[0], '0')))
		printf("MAP NOT CLOSE\n");
	if (!(bol_chr(mapping->map[count_line - 1], '0')))
		printf("MAP NOT CLOSE2\n");
	y = 1;
	while (y < count_line - 1)
	{
		x = 0;
		while (mapping->map[y][x])
		{
			if (mapping->map[y][x] == 'P')
				conf->p++;
			if (mapping->map[y][x] == 'C')
				conf->c++;
			if (mapping->map[y][x] == 'E')
				conf->e++;
			if (mapping->map[y][x] != 'P' && mapping->map[y][x] != 'C' && mapping->map[y][x] != 'E' && mapping->map[y][x] != '1' && mapping->map[y][x] != '0')
				printf("ERROR");
			x++;
		}
		if ((mapping->map[y][0] != '1') || (mapping->map[y][x - 1] != '1'))
			printf("MAP NOT CLOSE3\n");
		y++;
	}
	if ((conf->e != 1) || (conf->c < 1) || (conf->p != 1))
	 	printf("ERROR\n");
	free(conf);
}
void	create_tab(int count_line, t_map *mapping) 
{
	char	*map;
    char	*line;
    int	y;
	int	fd;

    y = 0;
	map = malloc(sizeof(char) * (count_line + 1));
    if (map == NULL)
		return ;
	map[0] = '\0';
	fd = open("map.ber", O_RDONLY);
    while (y < count_line) 
	{
        line = get_next_line(fd);
		map = free_strjoin(map, line);
		free(line);
        y++;
    }
	mapping->map = ft_split(map, '\n');
	mapping->tmp_map = ft_split(map, '\n');
	free(map);
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

int	main(void)
{
	char *line;
	int	count_line;
	int fd;
	t_map	*mapping;

	mapping = malloc(sizeof(t_map));
	if (mapping == NULL)
		return 0;
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
	//find_start(mapping);
	free_map(mapping->map);
	free(mapping);
}
