/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:34:06 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/02 18:49:07 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    find_start(t_map *mapping) //trouver P
{
    int x;
    int y;

    y = 0;
    while(mapping->map[y])
    {
        x = 0;
        while(1)
        {
            if (mapping->map[y][x] == 'P')
            {
                mapping->y = y; // POS Y --OK
                mapping->x = x; // POS X --OK
                printf("1");
                return ;
            }
            x++;
        }
        y++;
    }
   // flood_fill(x, y, pos, map);
    return ;
}

// int    flood_fill(int x, int y, t_pos *pos, char **map)
// {
//     char    **tmp_map;

//     tmp_map = map;
//     printf("%d", pos->y);
//     if (tmp_map[pos->y][pos->x] != '1')
//     {
//         tmp_map[pos->y][pos->x] == '1';
//         flood_fill(pos->x + 1, pos->y, pos, tmp_map);
//         flood_fill(pos->x - 1, pos->y, pos, tmp_map);
//         flood_fill(pos->x, pos->y + 1, pos, tmp_map);
//         flood_fill(pos->x, pos->y - 1, pos, tmp_map);
//     }
// }
