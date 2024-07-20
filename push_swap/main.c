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

t_swap	*ft_init_stack_a(t_swap *stack_a, char **args)
{
	int		i;
	t_swap	*head;

	i = 0;
	stack_a = malloc(sizeof(t_swap));
	if (stack_a == NULL)
		return (NULL);
	head = stack_a;
	while (args[i])
	{
		stack_a->next = malloc(sizeof(t_swap));
		stack_a->nb = ft_atoi(args[i]);
		stack_a = stack_a->next;
		i++;
	}
	stack_a->next = NULL;
	return (head);
}

void	ft_print_list(t_swap *stack_a)
{
	t_swap	*tmp;

	tmp = stack_a;
	while (tmp->next)
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

int	ft_listlen(t_swap *stack)
{
	int	i;

	i = 0;
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_swap	*ft_lstlast(t_swap *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_swap **lst, t_swap *new)
{
	t_swap	*tmp;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
	return ;
}

void	ra(t_swap *stack_a)
{
	t_swap	*head;

	head = stack_a->next;
	ft_lstadd_back(&head, stack_a);
	stack_a = head;
	return ;
}

int	main(int argc, char **argv)
{
	t_swap	*stack_a;
	char	**args;

	stack_a = NULL;
	if (argc < 2)
	{
		ft_printf("ERROR : Nbr of args\n");
		exit(1);
	}
	args = ft_join_args(argv);
	stack_a = ft_init_stack_a(stack_a, args);
	ra(stack_a);
	// if (!(ft_is_sort(stack_a)))
	//	sa(stack_a);
	ft_print_list(stack_a);
}
