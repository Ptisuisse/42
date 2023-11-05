#ifndef libft_h
#define libft_h

#include <stdlib.h>
#include <unistd.h>

int	ft_isalpha(int c);

int	ft_isdigit(int c);

int	ft_isalnum(int c);

int	ft_isascii(int c);

int	ft_isprint(int c);

int	ft_strlen(char *str);

int	ft_strncmp(char *dest, char *src, size_t n);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*memcpy(void *dst, const void *src, size_t n);

int	ft_toupper(int c);

int	ft_tolower(int c);

#endif
