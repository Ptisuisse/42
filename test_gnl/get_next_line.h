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

char	*get_next_line(int fd);
char	*read_line(int fd, char *buf);
char	*sorting_line(char *buf);
int	ft_strlen(char *str);
//char	*ft_strrchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*sorting_buf(char *buf);
char	*free_and_store(char *str, char *buf);
char	*ft_strrchr(char *string, int searchedChar );

#endif
