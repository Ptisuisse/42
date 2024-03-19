/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:31:17 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/19 18:31:21 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_event(void *mapping)
{
	t_map	*data;

	data = (t_map *)mapping;
	mlx_on_event(data->mlx->mlx, data->mlx->win, MLX_KEYDOWN, keyhook, data);
	return (0);
}

int	keyhook(int key, void *data)
{
	t_map	*mapping;

	mapping = (t_map *)data;
	if (key == 41)
		mlx_loop_end(mapping->mlx->mlx);
	if (key == 26 || key == 82)
		ft_move_up(mapping);
	if ((key == 22 || key == 81))
		ft_move_down(mapping);
	if ((key == 4 || key == 80))
		ft_move_left(mapping);
	if ((key == 7 || key == 79))
		ft_move_right(mapping);
	if (mapping->c == 0)
		ft_put_exit(mapping);
	if (mapping->c == 0 && mapping->map[mapping->y_p][mapping->x_p] == 'E')
		mlx_loop_end(mapping->mlx->mlx);
	return (0);
}

void	ft_move_up(t_map *mapping)
{
	mapping->shots++;
	if (mapping->map[(mapping->y_p - 1)][mapping->x_p] != '1')
	{
		mapping->x = mapping->x_p;
		mapping->y = mapping->y_p;
		ft_put_floor(mapping);
		mapping->y_p--;
		ft_put_player(mapping);
	}
}

void	ft_move_down(t_map *mapping)
{
	mapping->shots++;
	if (mapping->map[(mapping->y_p + 1)][mapping->x_p] != '1')
	{
		mapping->x = mapping->x_p;
		mapping->y = mapping->y_p;
		ft_put_floor(mapping);
		mapping->y_p++;
		ft_put_player(mapping);
	}
}

void	ft_move_left(t_map *mapping)
{
	mapping->shots++;
	if (mapping->map[mapping->y_p][(mapping->x_p - 1)] != '1')
	{
		mapping->x = mapping->x_p;
		mapping->y = mapping->y_p;
		if (mapping->map[mapping->y_p][mapping->x_p] != 'E')
			ft_put_floor(mapping);
		else
			ft_put_exit(mapping);
		mapping->x_p--;
		ft_put_player(mapping);
	}
}

void	ft_move_right(t_map *mapping)
{
	mapping->shots++;
	if (mapping->map[mapping->y_p][(mapping->x_p + 1)] != '1')
	{
		mapping->x = mapping->x_p;
		mapping->y = mapping->y_p;
		if (mapping->map[mapping->y_p][mapping->x_p] != 'E')
			ft_put_floor(mapping);
		else
			ft_put_exit(mapping);
		mapping->x_p++;
		ft_put_player(mapping);
	}
}

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
	mlx_put_image_to_window(mapping->mlx->mlx, mapping->mlx->win, mapping->mlx->img_player,
		(mapping->x_p * 64), (mapping->y_p * 64));
}

void	ft_put_wall(t_map *mapping)
{
	mlx_put_image_to_window(mapping->mlx->mlx, mapping->mlx->win, mapping->mlx->img,
		(mapping->x * 64), (mapping->y * 64));
}

void	ft_put_collectible(t_map *mapping)
{
	mlx_put_image_to_window(mapping->mlx->mlx, mapping->mlx->win, mapping->mlx->img_coll,
		(mapping->x * 64), (mapping->y * 64));
}

void	ft_put_floor(t_map *mapping)
{
	mlx_put_image_to_window(mapping->mlx->mlx, mapping->mlx->win, mapping->mlx->img_floor,
		(mapping->x * 64), (mapping->y * 64));
}

void	ft_put_exit(t_map *mapping)
{
	if (mapping->c > 0)
	{
		mlx_put_image_to_window(mapping->mlx->mlx, mapping->mlx->win, mapping->mlx->img_exit,
			(mapping->x_e * 64), (mapping->y_e * 64));
	}
	else
	{
		mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img_exit);
		mapping->mlx->img_exit = mlx_png_file_to_image(mapping->mlx->mlx,
				"./sprites/lock_green.png",
				&mapping->mlx->img_width, &mapping->mlx->img_height);
		mlx_put_image_to_window(mapping->mlx->mlx, mapping->mlx->win, mapping->mlx->img_exit,
			(mapping->x_e * 64), (mapping->y_e * 64));
	}
}
