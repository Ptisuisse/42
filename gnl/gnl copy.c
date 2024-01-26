#include "gnl.h"

/*void	free_list(t_list **node)
{

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

int	check_end(t_list *node)
{
	int	i;

	if (!node)
		return (0);
		i = 0;
	while(node->content[i] != '\0')
	{
			if(node->content[i] == '\n')
				return (1);
		i++;
	}
	return (0);
}

char	*read_line(t_list *node, int fd)
{
	int	i;
	char	*buf;

	if (check_end(node) == 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL);
		i = read(fd, buf, BUFFER_SIZE);
	}
	buf[i] = '\0';
	node = malloc(sizeof(t_list));
	return (buf);
}

char	*get_next_line(int fd)
{
	static t_list	*node;
	t_list	*list;
	char	*line;
	int	j;

	node = NULL;
	/*lire la ligne + stocker dans new node*/


	line = read_line(node, fd);
	node = store_node(node, line);
	list = node;
	/*couper jsq \n -> stock char*/
	j = ft_strlen(list);
	/*malloc strlen */
	line = malloc(sizeof(char) * (j + 1));
	line = cutline(node, line);

	/*free liste*/
	//free_list(&node);
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
