/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:44:48 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/03 15:40:02 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct  mapping
{
    char    **map;
    char    **tmp_map;
    int x_P;
    int y_P;
    int p;
    int c;
    int e;
    int nbr_err;
    int nbr_1;
} t_map;

void    flood_fill(int x_P, int y_P, t_map *mapping);
void    print_tab(t_map *mapping);
void free_map(char **tab);
int	bol_chr(const char *s, int c);
void map_conformity(t_map *mapping, int count_line);
void    create_tab(int count_line, t_map *mapping);

#endif
