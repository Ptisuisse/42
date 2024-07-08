/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:19:58 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/05 11:26:20 by lvan-slu         ###   ########.fr       */
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

int	check_sprite(t_map *mapping)
{
	int	fd;

	fd = open ("./sprites/star.png", O_RDONLY);
	check_fd(fd, mapping);
	fd = open ("./sprites/lock_red.png", O_RDONLY);
	check_fd(fd, mapping);
	fd = open ("./sprites/lock_green.png", O_RDONLY);
	check_fd(fd, mapping);
	fd = open ("./sprites/bg.png", O_RDONLY);
	check_fd(fd, mapping);
	fd = open ("./sprites/p1_front.png", O_RDONLY);
	check_fd(fd, mapping);
	fd = open ("./sprites/blockerMad.png", O_RDONLY);
	check_fd(fd, mapping);
	fd = open ("./sprites/boxAlt.png", O_RDONLY);
	check_fd(fd, mapping);
	close(fd);
	return (0);
}

void	check_fd(int fd, t_map *mapping)
{
	if (fd < 0)
	{
		ft_printf("ERROR\n");
		free_struct(mapping);
		close(fd);
		exit (1);
	}
	close (fd);
}
