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
	line = malloc(sizeof(char) * (j + 1));
	if (line == NULL)
		return (NULL);
	j = 0;
	while (new)
	{
		i = 0;
		while (new->content[i] != '\n' && new->content[i] != '\0')
		{
			line[i + j] = new->content[i];
			i++;
		}
		j += i;
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
	new = malloc(sizeof(t_list));
	new->content = malloc(sizeof(char) * (read + 1));
	if (!new || !list || new->content == NULL)
		return ;
	while (i < read)
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
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
	while (!(check_end(*list)))
	{
		i = (int)read(fd, buf, BUFFER_SIZE);
		if (!i)
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
	static t_list	*list = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
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

	fd = open("test.txt", O_RDONLY);
	boulet = get_next_line(fd);
	printf("%s\n", boulet);
	boulet = get_next_line(fd);
	printf("%s\n", boulet);
	boulet = get_next_line(fd);
	printf("%s\n", boulet);
}