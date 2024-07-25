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

void	ft_free_stack(t_swap **stack)
{
	while ((*stack))
	{
		free((*stack));
		(*stack) = (*stack)->next;
	}
}

void	ft_free(t_swap **stack_a, t_swap **stack_b)
{
	if (stack_a != NULL)
		ft_free_stack(stack_a);
	if (stack_b != NULL)
		ft_free_stack(stack_b);
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
