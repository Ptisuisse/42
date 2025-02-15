/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:06:18 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/03/21 18:07:43 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

size_t				ft_strlen(const char *str);

void				*ft_memset(void *s, int c, size_t n);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t n);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

int					ft_toupper(int c);

int					ft_tolower(int c);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

char				*ft_strnstr(const char *big, const char *little,
						size_t len);

int					ft_atoi(const char *str);

void				*ft_calloc(size_t nmemb, size_t size);

char				*ft_strdup(char *src);

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);

char				**ft_split(char const *s, char c);

char				*ft_itoa(int n);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

char				*get_next_line(int fd);

char				*read_line(int fd, char *buf);

char				*sorting_line(char *tmp);

char				*sorting_buf(char *buf);

char				*free_strjoin(char *s1, char *s2);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);

t_list				*ft_lstlast(t_list *lst);

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

void				ft_lstadd_front(t_list **lst, t_list *new);

int					ft_lstsize(t_list *lst);

void				ft_lstadd_back(t_list **lst, t_list *new);

void				ft_lstdelone(t_list *lst, void (*del)(void *));

void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));

int					ft_printf(const char *format, ...);

int					print_char(int c);

int					print_str(char *str);

int					print_type(char type, va_list ap);

int					print_digit(long n, int base, char type);

int					print_pointeur(unsigned long long n,
						unsigned long long base);

int					print_add(unsigned long long n, unsigned long long base);

#endif
