/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:21:20 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/01/30 05:40:47 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef	GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
#endif

typedef struct s_list
{
	char	*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	read_line(t_list **list, int fd);
void	store_node(t_list **list, char *buf, int read);
char	*into_char(t_list *list);
int	check_end(t_list *list );
int	ft_strlen(t_list *node);
void	free_node(t_list **list);
void	free_list(t_list **list, t_list *new, char *buf);
void	check_nl(t_list	*last, t_list	*new, char *buf, int i, int j);

#endif
