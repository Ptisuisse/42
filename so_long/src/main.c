/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:37:40 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/19 18:15:20 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
void	init_struct_mlx(t_map *mapping)
{
	mapping->mlx->img_coll = mlx_png_file_to_image(mapping->mlx->mlx, "./sprites/star.png", &mapping->mlx->img_width, &mapping->mlx->img_height);
	mapping->mlx->img_exit = mlx_png_file_to_image(mapping->mlx->mlx, "./sprites/lock_red.png", &mapping->mlx->img_width, &mapping->mlx->img_height); 
	mapping->mlx->img_floor = mlx_png_file_to_image(mapping->mlx->mlx, "./sprites/bg.png", &mapping->mlx->img_width, &mapping->mlx->img_height);
	mapping->mlx->img_player = mlx_png_file_to_image(mapping->mlx->mlx, "./sprites/p1_front.png", &mapping->mlx->img_width, &mapping->mlx->img_height);
	mapping->mlx->img = mlx_png_file_to_image(mapping->mlx->mlx, "./sprites/boxAlt.png", &mapping->mlx->img_width, &mapping->mlx->img_height);
}

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

int	check_extension(char *argv)
{
	int	c;

	c = ft_strlen(argv);
	
}

int	main(void)
{
	// if (argc != 2)
	// 	return (0);
	// //check_extension(argv[1]);
	t_map	*mapping;

	mapping = malloc(sizeof(t_map));
	if (mapping == NULL)
		return (0);
	mapping->mlx = malloc(sizeof(t_mlx));
	if (mapping->mlx == NULL)
		return (0);
	init_struct_map(mapping);
	init_map(mapping);
	ft_mlx_init(mapping);
	mlx_clear_window(mapping->mlx->mlx, mapping->mlx->win);
	mlx_destroy_window(mapping->mlx->mlx, mapping->mlx->win);
	mlx_destroy_display(mapping->mlx->mlx);
	free_map(mapping->map);
	free_map(mapping->tmp_map);
	free(mapping->mlx);
	free(mapping);
}
