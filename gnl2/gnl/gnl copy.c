#include "gnl.h"

void	free_list(t_list **list, t_list *new, char	*buf)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while(*list)
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
}

void	free_node(t_list **list)
{
	t_list	*new;
	t_list	*last;
	char	*buf;
	int	j;
	int	i;

	new = malloc(sizeof(t_list));
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (new == NULL || buf == NULL)
		return ;
	last = *list;
	j = 0;
	i = 0;
	while (last->next != NULL)
		last = last->next;
	while (last->content[i] != '\n')
		i++;
	last->content[i++];
	while (last->content[i] != '\0')
	{
		buf[j] = last->content[i];
		i++;
		j++;
	}
	new->content = buf;
	new->next = NULL;
	free_list(list, new, buf);
}

char	*into_char(t_list *list)
{
	int	i;
	int	j;
	char	*line;
	t_list	*new;
	
	new = list;
	j = ft_strlen(new);
	line = malloc(sizeof(char) * (j + 1));
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
	line[i + j] = '\0';
	return (line);
}

int	ft_strlen(t_list *node)
{
	int	i;
	int	j;

	j =0;
	while (node)
	{
		i = 0;
		while(node->content[i] != '\n' && node->content[i] != '\0')
			i++;
		j += i;
		node = node->next;
	}
	return (j);
}

void	store_node(t_list **list, char *buf, int read)
{
	t_list	*new;
	t_list	*tmp;
	int	i;

	i = 0;
	tmp = *list;
	new = malloc(sizeof(t_list));
	new->content = malloc(sizeof(char) * (read + 1));
	if (!new || !list || new->content == NULL)
		return ;
	while(buf[i] && i < read)
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

int	check_end(t_list *list)
{
	int	i;
	t_list	*node;

	node = list;
	if (node == NULL)
		return (0);
	while (node)
	{
		i = 0;
		while(node->content[i] != '\0' && i < BUFFER_SIZE)
		{
				if(node->content[i] == '\n')
					return (1);
			i++;
		}
		node = node->next;
	}
	return (0);
}

void	read_line(t_list **list, int fd)
{
	int	i;
	char	*buf;

	i = 1;
	while (!(check_end(*list)))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		i = read(fd, buf, BUFFER_SIZE);
		if (!i)
		{
			free(buf);
			return;
		}
		buf[i] = 0;
		store_node(list, buf, i);
	}
	return ;
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char	*line;
	int	j;

	read_line(&list, fd);
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
