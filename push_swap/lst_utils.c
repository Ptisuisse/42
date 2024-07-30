/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:37:46 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/20 17:37:47 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_swap **lst, t_swap *new)
{
	new->next = *lst;
	*lst = new;
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

t_swap	*ft_lstlast(t_swap *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_swap	*ft_lstnew(long int content, t_swap **stack_a, char **args)
{
	t_swap	*element;
	t_swap	*head;

	head = (*stack_a);
	if (content < -2147483648 || content > 2147483647)
	{
		free_tab(args);
		if ((*stack_a))
		{
			(*stack_a) = head;
			ft_lstclear(&(*stack_a), free);
		}
		else
			free(stack_a);
		exit(1);
	}
	element = malloc(sizeof(t_swap));
	if (element == NULL)
		return (NULL);
	element->next = NULL;
	element->nb = content;
	element->checked = 0;
	return (element);
}

int	ft_listlen(t_swap *stack)
{
	int		i;
	t_swap	*tmp;

	i = 1;
	tmp = stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
