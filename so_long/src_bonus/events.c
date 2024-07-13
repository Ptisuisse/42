/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:31:17 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/27 15:18:07 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	mouse_hook(int button, void *data)
{
	t_map	*mapping;

	mapping = (t_map *)data;
	if (button == 0)
		mlx_loop_end(mapping->mlx->mlx);
	return (0);
}

int	ft_event(void *mapping)
{
	t_map	*data;

	data = (t_map *)mapping;
	mlx_on_event(data->mlx->mlx, data->mlx->win, MLX_KEYDOWN, keyhook, data);
	mlx_on_event(data->mlx->mlx, data->mlx->win, MLX_WINDOW_EVENT, mouse_hook,
		data);
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
	if (mapping->map[mapping->y_p][mapping->x_p] == 'M')
		ft_bonus_lose(mapping);
	return (0);
}
