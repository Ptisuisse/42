/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:17:21 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/21 18:57:59 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_empty_line(t_map *mapping, char *line, int fd)
{
	ft_printf("ERROR\n");
	close(fd);
	free(line);
	free_struct(mapping);
	exit(1);
}

void	check_line(t_map *mapping, int fd)
{
	int	i;

	i = 0;
	while (mapping->char_map[i])
	{
		if ((mapping->char_map[i] == '\n' && mapping->char_map[i + 1] == '\n')
			|| mapping->char_map[0] == '\n')
		{
			ft_printf("ERROR\n");
			close(fd);
			free_struct(mapping);
			exit(1);
		}
		if (mapping->char_map[i] == 'M')
			mapping->eny++;
		i++;
	}
}

int	check_pce(t_map *mapping, int y)
{
	int	x;

	x = 0;
	while (mapping->map[y][x])
	{
		if (mapping->map[y][x] == 'P')
		{
			mapping->y_p = y;
			mapping->x_p = x;
			mapping->p++;
		}
		if (mapping->map[y][x] == 'C')
			mapping->c++;
		if (mapping->map[y][x] == 'E')
			mapping->e++;
		if (mapping->map[y][x] != 'P' && mapping->map[y][x] != 'C'
			&& mapping->map[y][x] != 'E' && mapping->map[y][x] != '1'
			&& mapping->map[y][x] != '0' && mapping->map[y][x] != 'M')
			ft_printf("ERROR\n%d: At [%d, %d]\n", (mapping->nbr_err += 1), x,
				y);
		x++;
	}
	if ((mapping->map[y][0] != '1') || (mapping->map[y][x - 1] != '1'))
		ft_printf("ERROR\n%d: NOT CLOSE \n", (mapping->nbr_err += 1));
	return (0);
}

int	map_conformity(t_map *mapping)
{
	int	y;

	y = 0;
	if (!(bol_chr(mapping->map[y], '1')))
		ft_printf("ERROR\n %d: Close first\n", (mapping->nbr_err++));
	if (!(bol_chr(mapping->map[mapping->count_line - 1], '1')))
		ft_printf("ERROR\n%d: Close last\n", (mapping->nbr_err++));
	y = 1;
	while (y < mapping->count_line - 1 && (!(check_pce(mapping, y))))
		y++;
	if (mapping->e != 1)
		ft_printf("ERROR\n%d: Incorrect number of EXIT (1 needed)\n",
			(mapping->nbr_err += 1));
	if (mapping->c < 1)
		ft_printf("ERROR\n%d: Min. 1 Collectible)\n", (mapping->nbr_err++));
	if (mapping->p != 1)
		ft_printf("ERROR\n%d: Player (1 needed)\n", (mapping->nbr_err++));
	if (mapping->p == 1)
		playable_map(mapping);
	if (mapping->nbr_err > 0)
	{
		ft_free(mapping);
		exit(1);
	}
	return (0);
}

int	check_extension(char *argv)
{
	int	c;

	c = ft_strlen(argv);
	if (!(argv[c - 1] == 'r' && argv[c - 2] == 'e' && argv[c - 3] == 'b'
			&& argv[c - 4] == '.'))
	{
		ft_printf("ERROR\n");
		exit(1);
	}
	if (argv[c - 5] == '\0')
	{
		ft_printf("ERROR\n");
		exit(1);
	}
	return (0);
}
