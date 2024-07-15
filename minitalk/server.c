/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:00:01 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/14 16:08:49 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str;

char	*ft_strjoin_serv(char *s1, char s2)
{
	int		i;
	int		len;
	char	*dest;

	len = 0;
	if (s1 != NULL)
		len = ft_strlen(s1);
	dest = malloc(sizeof(char) * (len + 2));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = s2;
	dest[i + 1] = '\0';
	free(s1);
	return (dest);
}

void	ft_handler(int signal)
{
	static int	pwr;
	static int	byte;

	byte <<= 1;
	if (signal == SIGUSR1)
		byte |= 1;
	pwr++;
	if (pwr == 8)
	{
		if (byte == '\0')
		{
			ft_putstr_fd(g_str, 1);
			free(g_str);
			g_str = NULL;
		}
		else
			g_str = ft_strjoin_serv(g_str, (char)byte);
		byte = 0;
		pwr = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		return (0);
	write(1, "PID :", 5);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
	{
		pause();
	}
}
