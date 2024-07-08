/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:34:06 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/27 14:04:43 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(int x, int y, t_map *mapping)
{
	if (mapping->nbr_err >= 1)
		return (0);
	if (mapping->tmp_map[y][x] != '1' && mapping->tmp_map[y][x] != 'M')
	{
		mapping->tmp_map[y][x] = '1';
		flood_fill(x + 1, y, mapping);
		flood_fill(x - 1, y, mapping);
		flood_fill(x, y + 1, mapping);
		flood_fill(x, y - 1, mapping);
	}
	if (x > 300 || y > 300)
	{
		ft_printf("ERROR\n");
		exit(1);
	}
	return (1);
}

int	playable_map(t_map *mapping)
{
	int	x;
	int	y;

	x = mapping->x_p;
	y = mapping->y_p;
	if (!(flood_fill(x, y, mapping)))
		return (1);
	y = 0;
	while (mapping->tmp_map[y])
	{
		x = 0;
		while (mapping->tmp_map[y][x])
		{
			if (mapping->tmp_map[y][x] == 'C' || mapping->tmp_map[y][x] == 'P'
				|| mapping->tmp_map[y][x] == 'E')
			{
				ft_printf("ERROR %d:\nYou can't win\n");
				ft_free(mapping);
				exit (1);
			}
			x++;
		}
		y++;
	}
	return (1);
}
