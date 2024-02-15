/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:30:44 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/02/15 16:58:55 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    ft_char_bin(int pid, int c)
{
   // int i;
    int j;
   // int c;

   // i = 0;
    // while (str[i] != '\0')
    // {
       // c = str[i];
        j = 7;
        while (j >= 0)
        {
            if (c >> j & 1)
                kill (pid, SIGUSR2);
            else
                kill (pid, SIGUSR1);
            j--;
            usleep(100);
       }
      // i++;
    //}
}

int main(int argc, char **argv)
{
    int pid;
    int i;
    i = 0;

    if (argc != 3)
        return (0);
    pid = atoi(argv[1]);
    while (argv[2][i] != '\0')
    {
        ft_char_bin(pid, argv[2][i]);
        i++;
    }
}
