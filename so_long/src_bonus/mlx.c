/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:21:00 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/21 18:49:07 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_mlx_sprites(t_map *mapping)
{
	while (mapping->tmp_map[mapping->y])
	{
		mapping->x = 0;
		while (mapping->map[mapping->y][mapping->x])
		{
			if (mapping->map[mapping->y][mapping->x] == '1')
				ft_put_wall(mapping);
			if (mapping->map[mapping->y][mapping->x] == 'P')
				ft_put_player(mapping);
			if (mapping->map[mapping->y][mapping->x] == 'C')
				ft_put_collectible(mapping);
			if (mapping->map[mapping->y][mapping->x] == 'E')
			{
				mapping->x_e = mapping->x;
				mapping->y_e = mapping->y;
				ft_put_exit(mapping);
			}
			if (mapping->map[mapping->y][mapping->x] == '0')
				ft_put_floor(mapping);
			if (mapping->map[mapping->y][mapping->x] == 'M')
				ft_put_eny(mapping);
			mapping->x++;
		}
		mapping->y++;
	}
}

void	ft_sizeof_window(t_map *mapping)
{
	int	tmpx;

	tmpx = 0;
	while (mapping->map[mapping->win_y])
	{
		mapping->win_x = 0;
		while (mapping->map[mapping->win_y][mapping->win_x])
			mapping->win_x++;
		if (tmpx == 0)
			tmpx = mapping->win_x;
		else if (tmpx != mapping->win_x)
		{
			ft_printf("ERROR\n");
			exit(1);
		}
		mapping->win_y++;
	}
}

int	ft_mlx_init(t_map *mapping)
{
	check_sprite(mapping);
	mapping->mlx->mlx = mlx_init();
	init_struct_mlx(mapping);
	ft_sizeof_window(mapping);
	mapping->mlx->win = mlx_new_window(mapping->mlx->mlx, (mapping->win_x * 64),
			(mapping->win_y * 64), "So_long");
	ft_mlx_sprites(mapping);
	mlx_loop_hook(mapping->mlx->mlx, ft_event, mapping);
	mlx_loop(mapping->mlx->mlx);
	return (0);
}
