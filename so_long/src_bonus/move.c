/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:12:56 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/21 18:36:02 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_up(t_map *mapping)
{
	if (mapping->map[(mapping->y_p - 1)][mapping->x_p] != '1')
	{
		mapping->shots++;
		ft_printf("%d\n", mapping->shots);
		mapping->str = ft_itoa(mapping->shots);
		mapping->x = 0;
		mapping->y = 0;
		ft_put_wall(mapping);
		ft_put_move(mapping);
		mapping->x = mapping->x_p;
		mapping->y = mapping->y_p;
		if (mapping->map[mapping->y_p][mapping->x_p] != 'E')
			ft_put_floor(mapping);
		else
			ft_put_exit(mapping);
		mapping->y_p--;
		ft_put_player(mapping);
	}
}

void	ft_move_down(t_map *mapping)
{
	if (mapping->map[(mapping->y_p + 1)][mapping->x_p] != '1')
	{
		mapping->shots++;
		ft_printf("%d\n", mapping->shots);
		mapping->str = ft_itoa(mapping->shots);
		mapping->x = 0;
		mapping->y = 0;
		ft_put_wall(mapping);
		ft_put_move(mapping);
		mapping->x = mapping->x_p;
		mapping->y = mapping->y_p;
		if (mapping->map[mapping->y_p][mapping->x_p] != 'E')
			ft_put_floor(mapping);
		else
			ft_put_exit(mapping);
		mapping->y_p++;
		ft_put_player(mapping);
	}
}

void	ft_move_left(t_map *mapping)
{
	if (mapping->map[mapping->y_p][(mapping->x_p - 1)] != '1')
	{
		mapping->shots++;
		ft_printf("%d\n", mapping->shots);
		mapping->str = ft_itoa(mapping->shots);
		mapping->x = 0;
		mapping->y = 0;
		ft_put_wall(mapping);
		ft_put_move(mapping);
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
	if (mapping->map[mapping->y_p][(mapping->x_p + 1)] != '1')
	{
		mapping->shots++;
		ft_printf("%d\n", mapping->shots);
		mapping->str = ft_itoa(mapping->shots);
		mapping->x = 0;
		mapping->y = 0;
		ft_put_wall(mapping);
		ft_put_move(mapping);
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
