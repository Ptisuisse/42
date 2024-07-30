/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 21:13:10 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/14 21:13:11 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack_a(t_swap **stack_a, char **args)
{
	int		i;
	t_swap	*new;
	t_swap	*head;

	i = 0;
	while (args[i])
	{
		new = ft_lstnew(ft_atol(args[i++]), stack_a, args);
		ft_lstadd_back(stack_a, new);
		head = (*stack_a);
	}
	return ;
}

int	ft_is_sort(t_swap **stack_a)
{
	t_swap	*head;

	head = (*stack_a);
	while ((*stack_a)->next != NULL)
	{
		if (((*stack_a)->nb > (*stack_a)->next->nb))
		{
			(*stack_a) = head;
			return (1);
		}
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = head;
	ft_printf("Is sort\n");
	return (0);
}

int	ft_is_double(t_swap **stack)
{
	t_swap	*head;
	t_swap	*tmp;
	int		i;

	head = (*stack);
	tmp = (*stack);
	while (tmp)
	{
		i = 0;
		while ((*stack))
		{
			if ((*stack)->nb == tmp->nb)
				i++;
			if (i > 1)
			{
				(*stack) = head;
				ft_printf("ERROR : DOUBLE\n");
				return (0);
			}
			(*stack) = (*stack)->next;
		}
		(*stack) = head;
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_swap	**stack_a;
	t_swap	**stack_b;
	char	**args;

	ft_error_arg(argc);
	args = ft_join_args(argv);
	stack_a = malloc(sizeof(t_swap *));
	if (stack_a == NULL)
		return (0);
	*stack_a = NULL;
	ft_init_stack_a(stack_a, args);
	stack_b = malloc(sizeof(t_swap *));
	if (stack_b == NULL)
		return (0);
	*stack_b = NULL;
	free_tab(args);
	if ((!ft_is_double(stack_a)) || (!ft_is_sort(stack_a)))
	{
		ft_free_stack(stack_a, stack_b);
		return (1);
	}
	else
		(ft_size_list(stack_a, stack_b));
	ft_free_stack(stack_a, stack_b);
	return (0);
}
