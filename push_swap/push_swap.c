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

//A box-> 0 // Bbox-> 1

void	ft_radix(t_swap **stack_a, t_swap **stack_b)
{
	int	size = ft_listlen((*stack_a));
	int	max_num = size;
	int	max_bit = 0;

	while ((max_num >> max_bit) != 0)
		max_bit++;
	int i = 0;
	int	j;
	int num;
	while (i < max_bit)
	{
		j = 0;
		while (j < size)
		{
			j++;
			num = (*stack_a)->nb;
			if ((num >> i & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		i++;
		while ((*stack_b))
			pa(stack_a, stack_b);
	}
}