/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 21:19:12 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/07/14 23:10:59 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_swap
{
	long int		nb;
	int				index;
	int				checked;
	struct s_swap	*next;
}					t_swap;

/*main.c*/
int					ft_is_sort(t_swap **stack_a);
int					ft_is_double(t_swap **stack);
void				ft_init_stack_a(t_swap **stack_a, char **args);

/*parsing.c*/
char				**ft_check_args(char *str, char **args);
char				**ft_join_args(char **argv);

/*short_sort.c*/
void				sort_three(t_swap **stack);
void				sort_four(t_swap **stack_a, t_swap **stack_b);
void				sort_five(t_swap **stack_a, t_swap **stack_b);
void				ft_size_list(t_swap **stack_a, t_swap **stack_b);

/*move_s.c*/
void				sa(t_swap **stack_a);
void				sb(t_swap **stack_b);
void				ss(t_swap **stack_a, t_swap **stack_b);
/*move.c*/
void				pa(t_swap **stack_a, t_swap **stack_b);
void				pb(t_swap **stack_a, t_swap **stack_b);
void				ra(t_swap **stack_a);
void				rb(t_swap **stack_b);
/*move_rr.c*/
void				rr(t_swap **stack_a, t_swap **stack_b);
void				rra(t_swap **stack_a);
void				rrb(t_swap **stack_b);
void				rrr(t_swap **stack_a, t_swap **stack_b);

/*lst_utils.c*/
void				ft_lstadd_front(t_swap **lst, t_swap *new);
void				ft_lstadd_back(t_swap **lst, t_swap *new);
t_swap				*ft_lstlast(t_swap *lst);
t_swap				*ft_lstnew(long int content, t_swap **stack_a, char **args);
int					ft_listlen(t_swap *stack);

/*push_swap*/
void				ft_radix(t_swap **stack_a, t_swap **stack_b);
void				ft_radix_sort(t_swap **stack_a, t_swap **stack_b,
						int max_bit, int size);
int					ft_list_nb(t_swap **stack);

/*check.c*/
void				ft_move_lowest(t_swap **stack_a, t_swap **stack_b);
int					check_lowest(t_swap **stack_a);
int					check_lowest_number(t_swap **stack_a);
int					check_biggest(t_swap **stack_a);
int					ft_biggest(t_swap **stack_a, int tmp, int i, int j);

/*free_error.c*/
void				free_tab(char **tab);
void				ft_error(char **args, char *str);
void				ft_error_arg(int argc);
void				ft_lstclear(t_swap **lst, void (*del)(void *));
void				ft_free_stack(t_swap **stack_a, t_swap **stack_b);

#endif