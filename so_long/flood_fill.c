/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:34:06 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/03 15:59:33 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    flood_fill(int x_P, int y_P, t_map *mapping)
{
    if (mapping->tmp_map[mapping->y_P][mapping->x_P] != '1')
    {
        mapping->tmp_map[mapping->y_P][mapping->x_P] = '1';

        flood_fill(mapping->x_P + 1, mapping->y_P, mapping);
        flood_fill(mapping->x_P - 1, mapping->y_P, mapping);
        flood_fill(mapping->x_P, mapping->y_P + 1, mapping);
        flood_fill(mapping->x_P, mapping->y_P - 1, mapping);
    }
}

