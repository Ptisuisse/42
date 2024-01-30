/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:24:43 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/01/30 18:16:49 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*into_char(t_list *list)
{
	int		i;
	int		j;
	char	*line;
	t_list	*new;

	new = list;
	j = ft_strlen(new);
	line = malloc((j + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	j = 0;
	if (!new->content[0])
		return (NULL);
	while (new)
	{
		i = 0;
		while (new->content[i] != '\0')
		{
			if (new->content[i] == '\n')
			{
				line[j++] = '\n';
				line[j] = '\0';
			}
			j++;
			i++;
			line[j] = new->content[i];
		}
		new = new->next;
	}
	line[j] = '\0';
	return (line);
}

void	store_node(t_list **list, char *buf, int read)
{
	t_list	*new;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	new = malloc(1 *sizeof(t_list));
	new->content = malloc((read + 1) * sizeof(char));
	if (!new || !list || new->content == NULL)
		return ;
	while (buf[i])
	{
		new->content[i] = buf[i];
		i++;
	}
	new->content[i] = '\0';
	new->next = NULL;
	if (*list == NULL)
		*list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return ;
}

void	read_line(t_list **list, int fd)
{
	int		i;
	char	*buf;

	i = 0;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buf == NULL)
			return ;
	while (!(check_end(*list)))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == 0)
		{
			free(buf);
			return ;
		}
		buf[i] = '\0';
		store_node(list, buf, i);
	}
	free(buf);
	return ;
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line(&list, fd);
	if (list == NULL)
		return (NULL);
	line = into_char(list);
	free_node(&list);
	return (line);
}

int	main(void)
{
	int	fd;
	char	*boulet;

	fd = open("nl", O_RDONLY);

	boulet = get_next_line(fd);
	printf("%s", boulet);
	// boulet = get_next_line(fd);
	// printf("%s\n", boulet);
	// boulet = get_next_line(fd);
	// printf("%s\n", boulet);

	// while (boulet)
	// {
	// 	printf("%s", boulet);
	// 	free(boulet);
	// 	boulet = get_next_line(fd);
	// }
}