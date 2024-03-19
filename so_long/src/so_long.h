/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:44:48 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/19 18:07:09 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../MacroLibX/includes/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct mlx
{
	int		img_height;
	int		img_width;
	void	*mlx;
	void	*img;
	void	*win;
	void	*img_player;
	void	*img_floor;
	void	*img_coll;
	void	*img_exit;
}	t_mlx;

typedef struct mapping
{
	t_mlx	*mlx;
	char	**map;
	char	**tmp_map;
	int		count_line;
	int		x_p;
	int		y_p;
	int		x_e;
	int		y_e;
	int		win_x;
	int		win_y;
	int		shots;
	int		x;
	int		y;
	int		p;
	int		c;
	int		e;
	int		nbr_err;
}			t_map;

void		print_tab(t_map *mapping);
void		free_map(char **tab);
int			bol_chr(const char *s, int c);
int			map_conformity(t_map *mapping);
void		create_tab(t_map *mapping);
int			check_pce(t_map *mapping, int x);
int			flood_fill(int x, int y, t_map *mapping);
int			playable_map(t_map *mapping);
void		init_map(t_map *mapping);
int			ft_mlx_init(t_map *mapping);
void		ft_mlx_sprites(t_map *mapping);
int			ft_event(void *mapping);
int			keyhook(int key, void *mapping);
void		ft_move_up(t_map *mapping);
void		ft_move_down(t_map *mapping);
void		ft_move_right(t_map *mapping);
void		ft_move_left(t_map *mapping);
void		ft_put_floor(t_map *mapping);
void		ft_put_collectible(t_map *mapping);
void		ft_put_exit(t_map *mapping);
void		ft_put_player(t_map *mapping);
void		ft_put_wall(t_map *mapping);
void		ft_exit_game(t_map *mapping);
void	init_struct_map(t_map *mapping);
void	init_struct_mlx(t_map *mapping);

#endif
