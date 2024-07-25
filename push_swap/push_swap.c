/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 21:13:14 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/14 21:13:14 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_nb(t_swap **stack)
{
	t_swap	*head;
	int		i;
	int		j;
	int		len;

	head = (*stack);
	j = 1;
	len = ft_listlen((*stack));
	while (len)
	{
		i = (check_biggest(stack));
		while (i > 1)
		{
			(*stack) = (*stack)->next;
			i--;
		}
		(*stack)->index = j;
		(*stack)->checked = 1;
		(*stack) = head;
		j++;
		len--;
	}
	return (j);
}

void	ft_radix_sort(t_swap **stack_a, t_swap **stack_b, int max_bit, int size)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j < size)
		{
			num = (*stack_a)->index;
			if ((num >> i & 1) == 0)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		i++;
		while ((*stack_b))
			pa(stack_a, stack_b);
	}
}

void	ft_radix(t_swap **stack_a, t_swap **stack_b)
{
	int	max_num;
	int	max_bit;
	int	size;

	size = ft_listlen((*stack_a));
	max_num = ft_list_nb(stack_a);
	max_bit = 0;
	while ((max_num >> max_bit))
		max_bit++;
	max_bit++;
	ft_radix_sort(stack_a, stack_b, max_bit, size);
}
