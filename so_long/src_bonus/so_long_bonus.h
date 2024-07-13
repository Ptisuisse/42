/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:44:48 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/12 13:26:48 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../MacroLibX/includes/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
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
	void	*img_eny;
}			t_mlx;

typedef struct mapping
{
	t_mlx	*mlx;
	char	*char_map;
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
	int		eny;
	int		nbr_err;
	char	*str;
}			t_map;

/*map.c*/
void		init_map(t_map *mapping, char *argv);
void		create_tab(t_map *mapping, char *argv);
int			bol_chr(const char *s, int c);
void		split_map(t_map *mapping);
/*flood_fill.c*/
int			flood_fill(int x, int y, t_map *mapping);
int			playable_map(t_map *mapping);
/*mlx.c*/
int			ft_mlx_init(t_map *mapping);
void		ft_mlx_sprites(t_map *mapping);
void		ft_sizeof_window(t_map *mapping);
int			mouse_hook(int button, void *data);
/*images.c*/
void		ft_put_floor(t_map *mapping);
void		ft_put_collectible(t_map *mapping);
void		ft_put_exit(t_map *mapping);
void		ft_put_player(t_map *mapping);
void		ft_put_wall(t_map *mapping);
/*move.c*/
void		ft_move_up(t_map *mapping);
void		ft_move_down(t_map *mapping);
void		ft_move_right(t_map *mapping);
void		ft_move_left(t_map *mapping);
/*events.c*/
int			ft_event(void *mapping);
int			keyhook(int key, void *mapping);
/*init.c*/
void		init_struct_map(t_map *mapping);
void		init_struct_mlx(t_map *mapping);
int			check_sprite(t_map *mapping);
void		check_fd(int fd, t_map *mapping);
/*free.c*/
void		free_mlx(t_map *mapping);
void		free_struct(t_map *mapping);
void		free_map(char **tab);
void		ft_free(t_map *mapping);
/*errors.c*/
void		ft_empty_line(t_map *mapping, char *line, int fd);
void		check_line(t_map *mapping, int fd);
int			map_conformity(t_map *mapping);
int			check_pce(t_map *mapping, int x);
int			check_extension(char *argv);
/*bonus.c*/
void		ft_put_eny(t_map *mapping);
void		ft_bonus_lose(t_map *mapping);
void		ft_put_move(t_map *mapping);
void		ft_free_eny(t_map *mapping);
void		ft_init_eny(t_map *mapping);

#endif
