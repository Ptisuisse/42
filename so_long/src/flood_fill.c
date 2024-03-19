/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:34:06 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/19 15:00:00 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(int x, int y, t_map *mapping)
{
	if (mapping->nbr_err >= 1)
		return (0);
	if (mapping->tmp_map[y][x] != '1')
	{
		mapping->tmp_map[y][x] = '1';
		flood_fill(x + 1, y, mapping);
		flood_fill(x - 1, y, mapping);
		flood_fill(x, y + 1, mapping);
		flood_fill(x, y - 1, mapping);
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
				printf("ERROR %d :\nYou can't win", (mapping->nbr_err += 1));
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
