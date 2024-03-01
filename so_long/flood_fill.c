/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:34:06 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/01 22:08:17 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void find_start(char **map)
{
    t_pos  *pos;
    int x;
    int y;

    pos = malloc(sizeof(t_pos));
    y = 0;
    while(map[y])
    {
        x = 0;
        while(map[y][x])
        {
            if (map[y][x] == 'P')
            {
                pos->y = y;
                pos->x = x;
                printf("%d\n", pos->y);
                printf("%d\n", pos->x);
            }
            x++;
        }
        y++;      
    }
}