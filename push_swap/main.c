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

	i = 0;
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}
}

int	ft_is_sort(t_swap **stack_a)
{
	t_swap *head;

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
		return (0);
}

	void ft_print_list(t_swap * stack_a)
	{
		t_swap *tmp;

		tmp = stack_a;
		while (tmp)
		{
			ft_printf("%d\n", tmp->nb);
			tmp = tmp->next;
		}
	}
	int main(int argc, char **argv)
	{
		t_swap **stack_a;
		t_swap **stack_b;
		char **args;

		stack_a = malloc(sizeof(t_swap *));
		if (stack_a == NULL)
			return (0);
		*stack_a = NULL;
		stack_b = malloc(sizeof(t_swap *));
		if (stack_b == NULL)
			return (0);
		*stack_b = NULL;
		if (argc < 2)
		{
			ft_printf("ERROR : Nbr of args\n");
			exit(1);
		}
		args = ft_join_args(argv);
		ft_init_stack_a(stack_a, args);
		if (ft_is_sort(stack_a) == 0)
			return (1);
		else
			(ft_size_list(stack_a, stack_b));
		return (0);
	}