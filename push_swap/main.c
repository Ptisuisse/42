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

int	ft_check_sign(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (argv[i])
	{
		j = 0;
		count = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				count++;
				if ((count > 1) || (!(ft_isdigit(argv[i][j + 1]))))
				{
					ft_printf("ERROR\n");
					break ;
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_args(char **argv)
{
	char	*str;
	int		i;

	i = 1;
	str = malloc(sizeof(char) * 1);
	if (str == NULL)
		return ;
	while (argv[i])
	{
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
		{
			if ((str[i] != '+' || str[i] != '-') && !(ft_isdigit(str[i + 1])))
			{
				ft_printf("NOK");
				break ;
			}
		}
		i++;
	}
}

t_swap	*ft_init_stack_a(t_swap *stack_a, char **argv)
{
	int		i;
	t_swap	*head;

	i = 1;
	stack_a = malloc(sizeof(t_swap));
	if (stack_a == NULL)
		return (NULL);
	head = stack_a;
	while (argv[i])
	{
		stack_a->next = malloc(sizeof(t_swap));
		stack_a->nb = ft_atoi(argv[i]);
		stack_a = stack_a->next;
		i++;
	}
	return (head);
}

void	ft_is_sort(t_swap *stack_a)
{

	while (stack_a->next)
	{
		ft_printf("NBDEBASE%d\n", stack_a->nb);
		if (stack_a->nb > stack_a->next->nb)
		{
			ft_printf("nb%d\n", stack_a->nb);
			ft_printf("nbnext%d\n", stack_a->next->nb);
		}
		stack_a = stack_a->next;
	}
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

int	main(int argc, char **argv)
{
	t_swap	*stack_a;

	stack_a = NULL;
	if (argc < 3)
	{
		ft_printf("ERROR : Nbr of args\n");
		exit(1);
	}
	ft_check_sign(argv);
	/*Verifier argc argv : nbr de param // is_digit // + et - // ' '
		// INTMAX */
	ft_check_args(argv);
	/*init struct*/
	/*stocker dans stack A*/
	stack_a = ft_init_stack_a(stack_a, argv);
	//ft_print_list(stack_a);
	ft_is_sort(stack_a);
	/*Verifier si trier*/
	/*si <= 5 (sort <= de 5)*/
	/*si superieur big sort*/
}
