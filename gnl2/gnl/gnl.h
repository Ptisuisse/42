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
void	read_line(t_list **list, int fd);
int	check_end(t_list *list);
void	store_node(t_list **list, char *buf, int read);
int	ft_strlen(t_list *node);
char	*into_char(t_list *list);
void	free_node(t_list **list);
void	free_list(t_list **list, t_list *new, char	*buf);
t_list	*char_buf(t_list *node, char *buf);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*find_last(t_list	*list);

#endif