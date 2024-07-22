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

/* Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.*/

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

	/*rajouter secu pour stackb > 2 fonction stacklen*/
	if (stack_b && (ft_listlen((*stack_b)) > 1))
	{
		tmp = (*stack_b)->nb;
		(*stack_b)->nb = (*stack_b)->next->nb;
		(*stack_b)->next->nb = tmp;
	}
	return ;
}

void	ss(t_swap **stack_a, t_swap **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
/*Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.*/

void	pa(t_swap **stack_b, t_swap **stack_a)
{
	t_swap	*head;

	head = *stack_b;
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_front(stack_a, head);
}

void	pb(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*head;

	head = *stack_a;
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_front(stack_b, head);
}

/*Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.*/

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
	return ;
}

void	rr(t_swap **stack_a, t_swap **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

/*Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.*/

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
}

void	rrr(t_swap **stack_a, t_swap **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
