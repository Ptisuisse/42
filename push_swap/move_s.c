/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:44:12 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/30 16:05:20 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_swap **stack_a)
{
	int	tmp;

	if (stack_a && (ft_listlen((*stack_a)) > 1))
	{
		tmp = (*stack_a)->nb;
		(*stack_a)->nb = (*stack_a)->next->nb;
		(*stack_a)->next->nb = tmp;
	}
	ft_printf("sa\n");
	return ;
}

void	sb(t_swap **stack_b)
{
	int	tmp;

	if (stack_b && (ft_listlen((*stack_b)) > 1))
	{
		tmp = (*stack_b)->nb;
		(*stack_b)->nb = (*stack_b)->next->nb;
		(*stack_b)->next->nb = tmp;
	}
	ft_printf("sb\n");
	return ;
}

void	ss(t_swap **stack_a, t_swap **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
