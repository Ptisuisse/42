/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:39:27 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/25 15:39:28 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_swap **stack_a, t_swap **stack_b)
{
	if (stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b)
		ft_lstclear(stack_b, free);
}

void	ft_error(char **args, char *str)
{
	if (args)
		free_tab(args);
	if (str)
		free(str);
	ft_printf("ERROR\n");
	exit(1);
}

void	ft_error_arg(int argc, char **argv)
{
	if (argc < 2)
		exit(1);
	if (argv[1][0] == '\0')
	{
		ft_printf("ERROR\n");
		exit(1);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void	ft_lstclear(t_swap **lst, void (*del)(void *))
{
	t_swap	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
	free(lst);
}
