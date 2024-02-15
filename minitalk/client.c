/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:30:44 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/02/15 17:08:22 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void    ft_binary(int pid, char c)
{
    int i;
    {
        i = 7;
        while (i >= 0)
        {
            if (c >> i & 1)
                kill (pid, SIGUSR1);
            else
                kill (pid, SIGUSR2);
            usleep(100);
            i--;
        }
    }
}

void    ft_char(int pid, char *str)
{
    int i;
    char    c;

    i = 0;
    while (str[i] != '\0')
    {
        c = str[i];
        ft_binary(pid, c);
        i++;
    }
    // ft_binary(pid, '\0');
    // ft_binary(pid, '\n');
}

int main(int argc, char **argv)
{
    int pid;

    if (argc != 3)
        return (0);
    pid = atoi(argv[1]);
    ft_char(pid, argv[2]);
}
