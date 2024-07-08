/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:37:40 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/21 18:33:56 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*mapping;

	if (argc != 2)
	{
		ft_printf("ERROR\n");
		exit (1);
	}
	check_extension(argv[1]);
	mapping = malloc(sizeof(t_map));
	if (mapping == NULL)
		return (0);
	mapping->mlx = malloc(sizeof(t_mlx));
	if (mapping->mlx == NULL)
		return (0);
	init_struct_map(mapping);
	init_map(mapping, argv[1]);
	ft_mlx_init(mapping);
	free_mlx(mapping);
	ft_free(mapping);
	return (0);
}
