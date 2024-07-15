/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:10:24 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/08 19:10:25 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

/*Client*/
void	ft_binary(int pid, char c);
void	ft_char_to_bin(char *str, int pid);
/*Server*/
char	*ft_strjoin_serv(char *s1, char s2);
void	ft_handler(int signal);

#endif
