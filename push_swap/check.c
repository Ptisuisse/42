/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:21:20 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/25 15:21:21 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_move_lowest(t_swap **stack_a, t_swap **stack_b)
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

int	check_lowest_number(t_swap **stack_a)
{
	t_swap	*head;
	int		i;
	int		tmp;

	head = (*stack_a);
	i = 1;
	tmp = (*stack_a)->nb;
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->nb < tmp)
		{
			tmp = (*stack_a)->nb;
		}
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	if ((*stack_a)->nb < tmp)
	{
		tmp = (*stack_a)->nb;
	}
	(*stack_a) = head;
	return (tmp);
}

int	check_biggest(t_swap **stack_a)
{
	t_swap	*head;
	int		i;
	int		j;
	int		tmp;

	head = (*stack_a);
	i = 1;
	j = 0;
	tmp = check_lowest_number(stack_a);
	while ((*stack_a)->next != NULL)
	{
		if (((*stack_a)->nb > tmp || (*stack_a)->nb == tmp)
			&& (*stack_a)->checked != 1)
		{
			j = i;
			tmp = (*stack_a)->nb;
		}
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	if (((*stack_a)->nb > tmp || (*stack_a)->nb == tmp)
		&& (*stack_a)->checked != 1)
	{
		j = i;
		tmp = (*stack_a)->nb;
	}
	(*stack_a) = head;
	return (j);
}
