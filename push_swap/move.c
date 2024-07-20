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

void	sa(t_swap *stack_a)
{
	int	tmp;

	if (stack_a && (ft_listlen(stack_a) > 1))
	{
		tmp = stack_a->nb;
		stack_a->nb = stack_a->next->nb;
		stack_a->next->nb = tmp;
	}
	return ;
}

void	sb(t_swap *stack_b)
{
	int	tmp;

	if (stack_b && (ft_listlen(stack_b) > 1))
	/*rajouter secu pour stackb > 2 fonction stacklen*/
	{
		tmp = stack_b->nb;
		stack_b->nb = stack_b->next->nb;
		stack_b->next->nb = tmp;
	}
	return ;
}

void	ss(t_swap *stack_a, t_swap *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
/*Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.*/

void	pa(t_swap *stack_a, t_swap *stack_b)
{
	t_swap	*head;

	head = stack_b->next;
	add_front(&stack_a, stack_b);
	stack_b = head;
}

void	pb(t_swap *stack_a, t_swap *stack_b)
{
	t_swap	*head;

	//if (stack_b->next == NULL)
	//{
	//	stack_b
	//}
	head = stack_a->next;
	add_front(&stack_b, stack_a);
	stack_a = head;
}

/*Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.*/

void	ra(t_swap *stack_a)
{
	t_swap	*head;

	head = stack_a->next;
	ft_lstadd_back(&head, stack_a);
}

void	rb(void)
{
}

void	rr(void)
{
}

/*Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.*/

void	rra(void)
{
}

void	rrb(void)
{
}

void	rrr(void)
{
}