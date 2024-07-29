/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:41:52 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/22 12:41:53 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_size_list(t_swap **stack_a, t_swap **stack_b)
{
	int	size;

	size = ft_listlen((*stack_a));
	if (size == 3)
		sort_three(stack_a);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else
		(ft_radix(stack_a, stack_b));
}

void	sort_three(t_swap **stack)
{
	if ((*stack)->nb > (*stack)->next->nb)
	{
		sa(stack);
		sort_three(stack);
	}
	else if ((*stack)->next->nb > (*stack)->next->next->nb)
	{
		rra(stack);
		sort_three(stack);
	}
	return ;
}

void	sort_four(t_swap **stack_a, t_swap **stack_b)
{
	ft_move_lowest(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_five(t_swap **stack_a, t_swap **stack_b)
{
	ft_move_lowest(stack_a, stack_b);
	if ((*stack_b)->nb < (*stack_b)->next->nb)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
