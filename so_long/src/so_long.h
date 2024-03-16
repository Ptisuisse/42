/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:44:48 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/16 23:53:26 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../../MacroLibX/includes/mlx.h"

typedef enum
{
	MLX_KEYDOWN2 = 0,
	MLX_KEYUP2 = 1,
	MLX_MOUSEDOWN2 = 2,
	MLX_MOUSEUP2 = 3,
	MLX_MOUSEWHEEL2 = 4,
	MLX_WINDOW_EVENT2 = 5
} mlx_event_type2;


typedef struct  mapping
{
    char    **map;
    char    **tmp_map;
    int x_P;
    int y_P;
    int x;
    int y;
    int p;
    int c;
    int e;
    int nbr_err;
    int win_x;
    int win_y;
    void    *mlx;
    void    *img;
    void    *win;
    int img_height;
    int img_width;
    void    *img_player;
    void    *img_floor;
    void    *img_coll;
    void    *img_exit;
} t_map;

void    print_tab(t_map *mapping);
void    free_map(char **tab);
int bol_chr(const char *s, int c);
int map_conformity(t_map *mapping, int count_line);
void    create_tab(int count_line, t_map *mapping);
int check_PCE(t_map *mapping, int x);
int flood_fill(int x, int y, t_map *mapping);
int playable_map(t_map *mapping);
void    init_map(t_map *mapping);
int ft_mlx_init(t_map *mapping);
int mlx_event(void *mlx, void *win, mlx_event_type2 event, int (*f)(int, void*), t_map *mapping);
void    ft_mlx_sprites(t_map *mapping);
int keyhook(int key, void *mapping);
void    ft_put_player(t_map *mapping);
void    ft_put_wall(t_map *mapping);
int ft_event(void *mapping);
int keyhook(int key, void *mapping);
void    ft_move_up(t_map *mapping);
void    ft_move_down(t_map *mapping);
void    ft_move_right(t_map *mapping);
void    ft_move_left(t_map *mapping);
void    ft_put_floor(t_map *mapping);
void    ft_put_collectible(t_map *mapping);
void    ft_put_exit(t_map *mapping);

#endif
