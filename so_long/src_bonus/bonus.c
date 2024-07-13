/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:01:08 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/12 12:01:12 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_eny(t_map *mapping)
{
	mapping->mlx->img_eny = mlx_png_file_to_image(mapping->mlx->mlx,
			"./sprites/blockerMad.png", &mapping->mlx->img_width,
			&mapping->mlx->img_height);
}

void	ft_put_eny(t_map *mapping)
{
	ft_put_floor(mapping);
	mlx_put_image_to_window(mapping->mlx->mlx, mapping->mlx->win,
		mapping->mlx->img_eny, (mapping->x * 64), (mapping->y * 64));
}

void	ft_bonus_lose(t_map *mapping)
{
	ft_printf("YOU LOSE\n");
	mlx_loop_end(mapping->mlx->mlx);
}

void	ft_put_move(t_map *mapping)
{
	mlx_string_put(mapping->mlx->mlx, mapping->mlx->win, 20, 20, 0xFFFFFFFF,
		mapping->str);
	free(mapping->str);
}

void	ft_free_eny(t_map *mapping)
{
	mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img_eny);
}
