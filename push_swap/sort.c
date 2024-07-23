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
	int	i;

	i = ft_listlen((*stack_a));
	while (i != 3)
	{
		pa(stack_a, stack_b);
		i--;
	}
	sort_three(stack_a);
	i = ft_listlen((*stack_b));
	if (i == 2 && ((*stack_b)->nb < (*stack_b)->next->nb))
		sb(stack_b);
	pb(stack_b, stack_a);
	if ((*stack_a)->nb > (*stack_a)->next->nb)
	{
		ra(stack_a);
		sort_four(stack_a, stack_b);
	}
}

int	check_biggest(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*head;
	int		i;
	int		j;
	int		tmp;

	head = (*stack_a);
	i = 1;
	j = 0;
	if (stack_b == NULL)
		tmp = (*stack_a)->nb;
	else
		tmp = (*stack_b)->nb;
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->nb > tmp)
		{
			j = i;
			tmp = (*stack_a)->nb;
		}
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	if ((*stack_a)->nb > tmp)
	{
		j = i;
		tmp = (*stack_a)->nb;
	}
	(*stack_a) = head;
	ft_printf("max : %d\n", j);
	ft_printf("tmp : %d\n", tmp);
	return (j);
}

int	check_lowest(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*head;
	int		i;
	int		j;
	int		tmp;

	head = (*stack_a);
	i = 1;
	j = 0;
	if (stack_b == NULL)
		tmp = (*stack_a)->nb;
	else
		tmp = (*stack_b)->nb;
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->nb < tmp)
		{
			j = i;
			tmp = (*stack_a)->nb;
		}
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	if ((*stack_a)->nb < tmp)
	{
		j = i;
		tmp = (*stack_a)->nb;
	}
	(*stack_a) = head;
	ft_printf("min : %d\n", j);
	ft_printf("tmp : %d\n", tmp);
	return (j);
}

void	sort_five(t_swap **stack_a, t_swap **stack_b)
{
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	sort_three(stack_a);
	if (check_biggest(stack_a, stack_b) == 0)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	if (check_lowest(stack_a, stack_b) == 0)
		pa(stack_a, stack_b);
	if (check_biggest(stack_a, stack_b) != 0)
	{
		if (check_lowest(stack_a, stack_b) == 0)
		{
			sb(stack_b);
			pa(stack_a, stack_b);
		}
	}
	if (check_lowest(stack_a, stack_b) != 0)
	{
	}
	ft_print_list((*stack_a));
}

//&&(*stack_a)->next->next->nb < (*stack_a)->next->next->next->nb
