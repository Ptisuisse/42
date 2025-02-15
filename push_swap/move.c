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

void	pa(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*head;

	head = *stack_b;
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_front(stack_a, head);
	ft_printf("pa\n");
}

void	pb(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*head;

	head = *stack_a;
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_front(stack_b, head);
	ft_printf("pb\n");
}

void	ra(t_swap **stack_a)
{
	t_swap	*head;
	t_swap	*tmp;

	head = *stack_a;
	tmp = ft_lstlast(head);
	*stack_a = head->next;
	head->next = NULL;
	tmp->next = head;
	ft_printf("ra\n");
	return ;
}

void	rb(t_swap **stack_b)
{
	t_swap	*head;
	t_swap	*tmp;

	head = *stack_b;
	tmp = ft_lstlast(head);
	*stack_b = head->next;
	head->next = NULL;
	tmp->next = head;
	ft_printf("rb\n");
	return ;
}
