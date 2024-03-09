/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:37:40 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/08 22:40:12 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    t_map	*mapping;

	mapping = malloc(sizeof(t_map));
	if (mapping == NULL)
		return 0;
    init_map(mapping);
    ft_mlx_init(mapping);
}