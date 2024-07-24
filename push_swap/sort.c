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
	ft_find_last(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	check_lowest(t_swap **stack_a)
{
	t_swap	*head;
	int		i;
	int		j;
	int		tmp;

	head = (*stack_a);
	i = 1;
	j = 0;
	tmp = (*stack_a)->nb;
	while ((*stack_a))
	{
		if ((*stack_a)->nb < tmp)
		{
			j = i;
			tmp = (*stack_a)->nb;
		}
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	(*stack_a) = head;
	return (j);
}

void	ft_find_last(t_swap **stack_a, t_swap **stack_b)
{
	while ((ft_listlen((*stack_a)) != 3))
	{
		if (check_lowest(stack_a) == 0)
			pb(stack_a, stack_b);
		else if (check_lowest(stack_a) == 2)
		{
			sa(stack_a);
			pb(stack_a, stack_b);
		}
		else if (check_lowest(stack_a) == 3)
		{
			ra(stack_a);
			ra(stack_a);
			pb(stack_a, stack_b);
		}
		else if (check_lowest(stack_a) == 4 || check_lowest(stack_a) == 5)
		{
			if (ft_listlen((*stack_a)) == 5 && check_lowest(stack_a) == 4)
				rra(stack_a);
			rra(stack_a);
			pb(stack_a, stack_b);
		}
	}
	sort_three(stack_a);
}

void	sort_five(t_swap **stack_a, t_swap **stack_b)
{
	ft_find_last(stack_a, stack_b);
	if ((*stack_b)->nb < (*stack_b)->next->nb)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
