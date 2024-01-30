/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:24:43 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/01/30 06:50:08 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_list(t_list **list, t_list *new, char *buf)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (new->content[0])
		*list = new;
	else
	{
		free(new);
		free(buf);
	}
	//list = &new;
}

void	free_node(t_list **list)
{
	t_list	*new;
	t_list	*last;
	char	*buf;
	int		j;
	int		i;

	new = malloc(1* sizeof(t_list));
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (new == NULL || buf == NULL)
		return ;
	last = *list;
	j = 0;
	i = 0;
	while (last->next != NULL)
		last = last->next;
	if (check_end(last))
	{
		while (last->content[i] != '\n')
			i++;
	}
	else
	{
		i += 1;
		last->content[i] = '\0';
	}
	while (last->content[i] != '\0')
	{
		buf[j] = last->content[i];
		i++;
		j++;
	}
	buf[j] = '\0';
	new->content = buf;
	new->next = NULL;
	free_list(list, new, buf);
}

int	ft_strlen(t_list *node)
{
	int	i;
	int	j;

	j = 0;
	while (node)
	{
		i = 0;
		while (node->content[i] != '\0')
		{
			if (node->content[i] == '\n')
			{
				j += i + 1;
				return (j);
			}
			i++;
		}
		j += i;
		node = node->next;
	}
	return (j);
}

int	check_end(t_list *list)
{
	int		i;
	t_list	*node;

	node = list;
	if (!node)
		return (0);
	while (node)
	{
		i = 0;
		while (node->content[i] != '\0' && i < BUFFER_SIZE)
		{
			if (node->content[i] == '\n')
				return (1);
			i++;
		}
		node = node->next;
	}
	return (0);
}
