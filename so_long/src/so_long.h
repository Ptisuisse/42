/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:44:48 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/05 12:07:05 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

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
} t_map;

void    print_tab(t_map *mapping);
void free_map(char **tab);
int	bol_chr(const char *s, int c);
int map_conformity(t_map *mapping, int count_line);
void    create_tab(int count_line, t_map *mapping);
int	check_PCE(t_map *mapping, int x);
int   flood_fill(int x, int y, t_map *mapping);
int    playable_map(t_map *mapping);
void	init_map(t_map *mapping);

#endif
