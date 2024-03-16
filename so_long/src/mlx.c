/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:21:00 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/16 23:51:21 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_mlx_sprites(t_map *mapping)
{
    mapping->y = 0;
    while(mapping->tmp_map[mapping->y])
    {
        mapping->x = 0;
        while (mapping->map[mapping->y][mapping->x])
        {
            if(mapping->map[mapping->y][mapping->x] == '1')
                ft_put_wall(mapping);
            if(mapping->map[mapping->y][mapping->x] == 'P')
                ft_put_player(mapping);
            if(mapping->map[mapping->y][mapping->x] == 'C')
                ft_put_collectible(mapping);
            if(mapping->map[mapping->y][mapping->x] == 'E')
                ft_put_exit(mapping);
            if(mapping->map[mapping->y][mapping->x] == '0')
                ft_put_floor(mapping);
            mapping->x++;
        }
        mapping->y++;
    }
}

void    ft_sizeof_window(t_map *mapping)
{
    mapping->win_x = 0;
    mapping->win_y = 0;

    while (mapping->map[mapping->win_y])
    {
        mapping->win_x = 0;
        while (mapping->map[mapping->win_y][mapping->win_x])
            mapping->win_x++;
        mapping->win_y++;
    }
}

int ft_mlx_init(t_map *mapping)
{
    mapping->mlx = mlx_init();
    ft_sizeof_window(mapping);
    mapping->win = mlx_new_window(mapping->mlx, (mapping->win_x * 64), (mapping->win_y * 64), "So_long");
    ft_mlx_sprites(mapping);
    //mlx_on_event(mapping->mlx, mapping->win, MLX_KEYDOWN2, keyhook, mapping);
    mlx_loop_hook(mapping->mlx, ft_event, mapping);
    mlx_loop(mapping->mlx);
    //mlx_destroy_image(mapping->mlx, mapping->img);
    mlx_destroy_window(mapping->mlx, mapping->win);
    mlx_destroy_display(mapping->mlx);
}
