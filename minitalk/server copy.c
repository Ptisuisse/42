/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:31:47 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/02/15 16:55:50 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar_fd(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr_fd(int n)
{
	if (n > 9)
	{
		ft_putnbr_fd (n / 10);
		n = n % 10;
		ft_putchar_fd(n + '0');
	}
	else
		ft_putchar_fd(n + '0');
}

void	decrypt_bin(int signal)
{
	static int	pwr;
	static int	byte;

	if (signal == SIGUSR2)
		byte |= 1 << (7 - pwr);
	pwr++;
	if (pwr == 8)
	{
		ft_putchar_fd(byte);
		pwr = 0;
		byte = 0;
	}
}

int main(void)
{
	write (1, "PID: ", 5);
    ft_putnbr_fd(getpid());
	ft_putchar_fd('\n');
	signal(SIGUSR1, decrypt_bin);
	signal(SIGUSR2, decrypt_bin);
	while (1)
		sleep (1);
	return (0);
}