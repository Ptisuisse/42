/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:14:23 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/21 16:14:59 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_player(t_map *mapping)
{
	if (mapping->shots == 0)
		ft_put_floor(mapping);
	if (mapping->map[mapping->y_p][mapping->x_p] == 'C')
	{
		mapping->map[mapping->y_p][mapping->x_p] = '0';
		mapping->c--;
		mapping->y = mapping->y_p;
		mapping->x = mapping->x_p;
		ft_put_floor(mapping);
	}
	mlx_put_image_to_window(mapping->mlx->mlx, mapping->mlx->win,
		mapping->mlx->img_player, (mapping->x_p * 64), (mapping->y_p * 64));
}

void	ft_put_wall(t_map *mapping)
{
	mlx_put_image_to_window(mapping->mlx->mlx, mapping->mlx->win,
		mapping->mlx->img, (mapping->x * 64), (mapping->y * 64));
}

void	ft_put_collectible(t_map *mapping)
{
	mlx_put_image_to_window(mapping->mlx->mlx, mapping->mlx->win,
		mapping->mlx->img_coll, (mapping->x * 64), (mapping->y * 64));
}

void	ft_put_floor(t_map *mapping)
{
	mlx_put_image_to_window(mapping->mlx->mlx, mapping->mlx->win,
		mapping->mlx->img_floor, (mapping->x * 64), (mapping->y * 64));
}

void	ft_put_exit(t_map *mapping)
{
	if (mapping->c > 0)
	{
		mlx_put_image_to_window(mapping->mlx->mlx, mapping->mlx->win,
			mapping->mlx->img_exit, (mapping->x_e * 64), (mapping->y_e * 64));
	}
	else
	{
		mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img_exit);
		mapping->mlx->img_exit = mlx_png_file_to_image(mapping->mlx->mlx,
				"./sprites/lock_green.png", &mapping->mlx->img_width,
				&mapping->mlx->img_height);
		mlx_put_image_to_window(mapping->mlx->mlx, mapping->mlx->win,
			mapping->mlx->img_exit, (mapping->x_e * 64), (mapping->y_e * 64));
	}
}
