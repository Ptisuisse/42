/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:31:17 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/18 17:39:25 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_event(void *mapping)
{
    t_map *data = (t_map *)mapping;
    mlx_on_event(data->mlx, data->win, MLX_KEYDOWN, keyhook, data);
    return (0);
}

int keyhook(int key, void *data)
{
    t_map *mapping = (t_map *)data;
    mapping->shots = 0;
    if(key == 41)
        mlx_loop_end(mapping->mlx);
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
    if (mapping->c == 0 && mapping->map[mapping->y_P][mapping->x_P] == 'E')
        mlx_loop_end(mapping->mlx);
    return (0);
}

void    ft_move_up(t_map *mapping)
{
    mapping->shots++;
    if (mapping->map[(mapping->y_P - 1)][mapping->x_P] != '1')
    {
        mlx_destroy_image(mapping->mlx, mapping->img_player);
        mapping->y_P--;
        if (mapping->map[mapping->y_P][mapping->x_P] == 'C')
        {
            mapping->map[mapping->y_P][mapping->x_P] = '0';
            mapping->c--;
        }
        ft_put_player(mapping);
    }
}

void    ft_move_down(t_map *mapping)
{
    mapping->shots++;
    if (mapping->map[(mapping->y_P + 1)][mapping->x_P] != '1')
    {
        mlx_destroy_image(mapping->mlx, mapping->img_player);
        mapping->y_P++;
        if (mapping->map[mapping->y_P][mapping->x_P] == 'C')
        {
            mapping->map[mapping->y_P][mapping->x_P] = '0';
            mapping->c--;
        }
        ft_put_player(mapping);
    }
}

void    ft_move_left(t_map *mapping)
{
    mapping->shots++;
    if (mapping->map[mapping->y_P][(mapping->x_P - 1)] != '1')
    {
        mlx_destroy_image(mapping->mlx, mapping->img_player);
        mapping->x_P--;
        if (mapping->map[mapping->y_P][mapping->x_P] == 'C')
        {
            mapping->map[mapping->y_P][mapping->x_P] = '0';
            mapping->c--;
        }
        ft_put_player(mapping);
    }
}

void    ft_move_right(t_map *mapping)
{
    mapping->shots++;
    if (mapping->map[mapping->y_P][(mapping->x_P + 1)] != '1')
    {
        mlx_destroy_image(mapping->mlx, mapping->img_player);
        mapping->x_P++;
        if (mapping->map[mapping->y_P][mapping->x_P] == 'C')
        {
            mapping->map[mapping->y_P][mapping->x_P] = '0';
            mapping->c--;
        }
        ft_put_player(mapping);
    }
}

void    ft_put_player(t_map *mapping)
{
    if (mapping->map[mapping->y_P][mapping->x_P] != 'E')
    {
        mapping->img_player = mlx_png_file_to_image(mapping->mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/sprites/bg.png", &mapping->img_width, &mapping->img_height);
        mlx_put_image_to_window(mapping->mlx, mapping->win, mapping->img_player, (mapping->x_P * 64),(mapping->y_P * 64));
    }
    mapping->img_player = mlx_png_file_to_image(mapping->mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/sprites/p1_front.png", &mapping->img_width, &mapping->img_height);
    mlx_put_image_to_window(mapping->mlx, mapping->win, mapping->img_player, (mapping->x_P * 64),(mapping->y_P * 64));
}

void    ft_put_wall(t_map *mapping)
{
    mapping->img = mlx_png_file_to_image(mapping->mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/sprites/boxAlt.png", &mapping->img_width, &mapping->img_height);
    mlx_put_image_to_window(mapping->mlx, mapping->win, mapping->img, (mapping->x * 64),(mapping->y * 64));
}

void    ft_put_collectible(t_map *mapping)
{
    mapping->img_coll = mlx_png_file_to_image(mapping->mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/sprites/star.png", &mapping->img_width, &mapping->img_height);
    mlx_put_image_to_window(mapping->mlx, mapping->win, mapping->img_coll, (mapping->x * 64),(mapping->y * 64));
}

void    ft_put_floor(t_map *mapping)
{
    mapping->img_floor = mlx_png_file_to_image(mapping->mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/sprites/bg.png", &mapping->img_width, &mapping->img_height);
    mlx_put_image_to_window(mapping->mlx, mapping->win, mapping->img_floor, (mapping->x * 64),(mapping->y * 64));
}

void    ft_put_exit(t_map *mapping)
{
    if (mapping->c > 0)
    {
        mapping->img_exit = mlx_png_file_to_image(mapping->mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/sprites/lock_red.png", &mapping->img_width, &mapping->img_height);
        mlx_put_image_to_window(mapping->mlx, mapping->win, mapping->img_exit, (mapping->x_E * 64),(mapping->y_E * 64));
    }
    else 
    {
        mlx_destroy_image(mapping->mlx, mapping->img_exit);
        mapping->img_exit = mlx_png_file_to_image(mapping->mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/sprites/lock_green.png", &mapping->img_width, &mapping->img_height);
        mlx_put_image_to_window(mapping->mlx, mapping->win, mapping->img_exit, (mapping->x_E* 64),(mapping->y_E * 64));
    }
}