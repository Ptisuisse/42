/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:19:58 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/21 18:46:13 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_map(t_map *mapping)
{
	mapping->win_y = 0;
	mapping->e = 0;
	mapping->c = 0;
	mapping->p = 0;
	mapping->y = 0;
	mapping->count_line = 0;
	mapping->nbr_err = 0;
	mapping->shots = 0;
}

void	init_struct_mlx(t_map *mapping)
{
	mapping->mlx->img_coll = mlx_png_file_to_image(mapping->mlx->mlx,
			"./sprites/star.png", &mapping->mlx->img_width,
			&mapping->mlx->img_height);
	mapping->mlx->img_exit = mlx_png_file_to_image(mapping->mlx->mlx,
			"./sprites/lock_red.png", &mapping->mlx->img_width,
			&mapping->mlx->img_height);
	mapping->mlx->img_floor = mlx_png_file_to_image(mapping->mlx->mlx,
			"./sprites/bg.png", &mapping->mlx->img_width,
			&mapping->mlx->img_height);
	mapping->mlx->img_player = mlx_png_file_to_image(mapping->mlx->mlx,
			"./sprites/p1_front.png", &mapping->mlx->img_width,
			&mapping->mlx->img_height);
	mapping->mlx->img = mlx_png_file_to_image(mapping->mlx->mlx,
			"./sprites/boxAlt.png", &mapping->mlx->img_width,
			&mapping->mlx->img_height);
	mapping->mlx->img_eny = mlx_png_file_to_image(mapping->mlx->mlx,
			"./sprites/blockerMad.png", &mapping->mlx->img_width,
			&mapping->mlx->img_height);
}

void	free_map(char **tab)
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

void	free_mlx(t_map *mapping)
{
	mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img_exit);
	mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img);
	mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img_player);
	mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img_floor);
	mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img_coll);
	mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img_eny);
	mlx_clear_window(mapping->mlx->mlx, mapping->mlx->win);
	mlx_destroy_window(mapping->mlx->mlx, mapping->mlx->win);
	mlx_destroy_display(mapping->mlx->mlx);
}

void	free_struct(t_map *mapping)
{
	free(mapping->mlx);
	free(mapping);
}
