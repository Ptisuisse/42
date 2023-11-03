/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:46:31 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/11/03 09:02:37 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef libft_h
#define libft_h

# include <stdlib.h>
# include <unistd.h>

int	ft_isalpha(int c);

int	ft_isdigit(int c);

int	ft_isalnum(int c);



int	ft_strlen(char *str);

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

int	ft_toupper(int c);

#endif
