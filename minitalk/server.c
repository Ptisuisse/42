/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:00:01 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/08 19:00:02 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

char *ftstrjoin(char const *s1, char const s2)
{
	int ls1;
	char *news;

	if (!s1)
		return (0);
	ls1 = ft_strlen(s1);
	news = ft_calloc((ls1 + 2), sizeof(char));
	if (news == NULL)
		return (NULL);
	ft_memcpy(news, s1, ls1);
	news[ls1] = s2;
	return (news);
}

void ft_handler(int sig, siginfo_t *info, void *oldcat)
{
	(void)oldcat;
	static int pwr;
	int byte;
	char	*str;

	if (sig == SIGUSR2)
		byte ^= 1 << (7 - pwr);
	pwr++;
	// if () //start == 0
	// {
	// 	str = malloc;
	// 	str[0]
	// 	start write
	// 	start++
	// }
	if (pwr == 8)
	{
		if (byte == 0)
		{
			write (1, &str, ft_strlen(str));
			free (str);
		}
		else
			ftstrjoin(str, (char)byte);
		pwr = 0;
		byte = 0;
	}
}

int main(void)
{
	struct sigaction	sa;

	write(1, "PID :", 5);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		// signal(SIGUSR1, decrypt_bin);
		// signal(SIGUSR2, decrypt_bin);
		pause();
	}
}


void	ft_handler(int sig, siginfo_t *info, void *oldact)
{
	(void)oldact;
	g_bit_info.car = g_bit_info.car << 1;
	if (sig == SIGUSR2)
		g_bit_info.car++;
	g_bit_info.bits++;
	if (g_bit_info.is_start == 0)
	{
		g_bit_info.str = malloc(1);
		g_bit_info.str[0] = 0;
		ft_start_writer(info->si_pid);
		g_bit_info.is_start ++;
	}
	if (g_bit_info.bits == 8)
	{
		if (g_bit_info.car == 0 && --g_bit_info.is_start == 0)
		{
			write(1, g_bit_info.str, ft_strlen(g_bit_info.str));
			free(g_bit_info.str);
		}
		else
			g_bit_info.str = ft_strjoin(g_bit_info.str, (char)g_bit_info.car);
		g_bit_info.bits = 0;
		g_bit_info.car = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
