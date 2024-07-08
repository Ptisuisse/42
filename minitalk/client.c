/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:00:05 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/08 19:00:06 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_binary(char c, int pid)
{
    int i;
    char bit;
    i = 7;
    while (i >= 0)
    {
        bit = c >> i;
        if ((bit & 1) == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(5);
        i--;
    }
}

void ft_char_to_bin(char *str, int pid)
{
    int i;
    char c;

    i = 0;
    while (str[i])
    {
        c = str[i];
        ft_binary(c, pid);
        i++;
    }
}

int main(int argc, char **argv)
{
    int pid;

    if (argc != 3)
        return (0);
    pid = ft_atoi(argv[1]); // ft_atoi
    ft_char_to_bin(argv[2], pid);
}