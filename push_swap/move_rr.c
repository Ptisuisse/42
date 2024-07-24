/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:44:12 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/20 13:44:13 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_swap **stack_a, t_swap **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}

void	rra(t_swap **stack_a)
{
	t_swap	*head;
	t_swap	*tmp;
	int		i;

	i = ft_listlen((*stack_a));
	i -= 2;
	head = *stack_a;
	tmp = ft_lstlast(head);
	while (i)
	{
		head = head->next;
		i--;
	}
	head->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	ft_printf("rra\n");
}

void	rrb(t_swap **stack_b)
{
	t_swap	*head;
	t_swap	*tmp;
	int		i;

	i = ft_listlen((*stack_b));
	i -= 2;
	head = *stack_b;
	tmp = ft_lstlast(head);
	while (i)
	{
		head = head->next;
		i--;
	}
	head->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_printf("rrb\n");
}

void	rrr(t_swap **stack_a, t_swap **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}
