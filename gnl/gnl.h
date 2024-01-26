#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef GNL_H
# define GNL_H


#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#endif

typedef struct s_list
{
	char	*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*read_line(t_list *node, int fd);
int	check_end(t_list *list);
//int	check_end(char *buf);
t_list	*store_node(t_list *node, char *buf);
t_list	*find_last(t_list *node);
char	*cutline(t_list *node, char *line);
int	ft_strlen(t_list *node);

#endif