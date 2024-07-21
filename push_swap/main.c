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

char	**ft_check_args(char *str)
{
	char	**args;
	int		i;
	int		j;
	int		count;

	args = ft_split(str, ' ');
	i = 0;
	while (args[i])
	{
		count = 0;
		j = 0;
		while (args[i][j])
		{
			if (!(ft_isdigit(args[i][j])) && (args[i][j] != '+'
					&& args[i][j] != '-'))
				ft_printf("NO DIGIT\n");
			if (args[i][j] == '-' || args[i][j] == '+')
				count++;
			j++;
			if (count > 1)
				ft_printf("- || +\n");
		}
		i++;
	}
	return (args);
}

char	**ft_join_args(char **argv)
{
	int		i;
	char	*str;
	char	**args;

	i = 1;
	str = malloc(sizeof(char) * 1);
	if (str == NULL)
		return (NULL);
	while (argv[i])
	{
		if (i > 1)
			str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	args = ft_check_args(str);
	return (args);
}

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

void	ft_print_list(t_swap *stack_a)
{
	t_swap	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		ft_printf("%d\n", tmp->nb);
		tmp = tmp->next;
	}
}

int	ft_is_sort(t_swap *stack_a)
{
	while (stack_a->next != NULL)
	{
		if ((stack_a->nb > stack_a->next->nb) && (stack_a->next->next != NULL))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_swap	**stack_a;
	t_swap	**stack_b;
	char	**args;

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
	pb(stack_a, stack_b);
	ft_print_list((*stack_a));
	ft_print_list((*stack_b));
}
