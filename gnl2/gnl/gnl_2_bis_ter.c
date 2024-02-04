#include "gnl.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

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
*/
/*
t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->content = content;
	return (new);
}
*/

int	ft_strlen(t_list *node)
{
	int	i;

	i = 0;
	while(node->content[i] != '\0')
		i++;
	return (i);
}

char	*cutline(t_list *node, char *line)
{
	int	i;

	i = 0;
	while(i <= BUFFER_SIZE)
	{
		if (node->content[i] == '\n')
			return (line);
		line[i] = node->content[i];
		i++;
	}
	return (line);
}

t_list	*find_last(t_list *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

t_list	*store_node(t_list *node, char *buf)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return(NULL);
	node = find_last(node);
	if (!node)
	{
		node = malloc(sizeof(t_list));
		node->content = buf;
		node->next = NULL;
	}
	else
	{
		node->next = new_node;
		new_node->content = buf;
		new_node->next = NULL;
	}
	return (node);
}

int	check_end(char *buf)
{
	int	i;
    
    i = 0;
	while(buf[i] != '\0')
	{
			if(buf[i] == '\n')
				return (1);
		i++;
	}
	return (0);
}

char	*read_line(int fd)
{
	int	i;
	char	*buf;

	if (check_end(buf) == 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL);
		i = read(fd, buf, BUFFER_SIZE);
	}
	buf[i] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	static t_list	*node;
	char	*line;
	int	j;

	node = NULL;
    line = read_line(fd);
	store_node(node, line);
	//j = ft_strlen(node);
	line = malloc(sizeof(char) * (j + 1));
	line = cutline(node, line);
	return (line);
}

int	main(void)
{
	int	fd;
	char	*boulet;

	fd = open("test.txt", O_RDONLY);
	boulet = get_next_line(fd);
	printf("%s", boulet);
}