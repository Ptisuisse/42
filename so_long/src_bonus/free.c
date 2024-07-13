/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:19:58 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/05 11:26:13 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(t_map *mapping)
{
	free_map(mapping->map);
	free_map(mapping->tmp_map);
	free_struct(mapping);
}

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

void	free_mlx(t_map *mapping)
{
	mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img);
	mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img_player);
	mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img_floor);
	mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img_coll);
	mlx_destroy_image(mapping->mlx->mlx, mapping->mlx->img_exit);
	if (mapping->eny > 0)
		ft_free_eny(mapping);
	mlx_clear_window(mapping->mlx->mlx, mapping->mlx->win);
	mlx_destroy_window(mapping->mlx->mlx, mapping->mlx->win);
	mlx_destroy_display(mapping->mlx->mlx);
}

void	free_struct(t_map *mapping)
{
	free(mapping->mlx);
	free(mapping);
}
