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
	pa(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	sort_three(stack_b);
	pa(stack_a, stack_b);
	ra(stack_b);
	(*stack_a) = (*stack_b);
	while ((*stack_a)->nb > (*stack_a)->next->nb)
	{
		sa(stack_a);
		if (((*stack_a)->nb < (*stack_a)->next->nb) && ((*stack_a)->next != NULL))
			(*stack_a) = (*stack_a)->next;
	}
	ft_print_list((*stack_a));
}

// void	sort_five(t_swap **stack_a, t_swap **stack_b)
//{
//	t_swap	*head;
//	int		i;

//	// i = ft_listlen(*stack_a);
//	// i = 3;
//	head = (*stack_a);
//	while ((*stack_a)->nb < (*stack_a)->next->nb && ((*stack_a)->next != NULL))
//		sa(stack_a);
//	while ((*stack_a)->next != NULL)
//	{
//		(*stack_a) = (*stack_a)->next;
//		rra(stack_a);
//		pa(stack_a, stack_b);
//		i++;
//	}
//	(*stack_a) = head;
//	sort_three(stack_a);
//	ft_lstadd_back(stack_a, (*stack_b));
//	ft_print_list((*stack_a));
//	return ;
//}
