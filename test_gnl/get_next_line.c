/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <lvan-slu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:24:43 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/02/03 17:15:45 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*free_and_store(char *str, char *buf)
{
	char	*new;
	int	str_len;
	int	buf_len;

	buf_len = ft_strlen(buf);
	str_len = ft_strlen(str);
	new = ft_calloc((str_len + buf_len + 1), sizeof(char));
	if (!buf || !str || !new)
		return (NULL);
	ft_memcpy(new, buf, buf_len);
	str_len = 0;
	while (str[str_len] != '\0')
	{
		new[buf_len] = str[str_len];
		buf_len++;
		str_len++;
	}
	return (new);
}

char	*sorting_buf(char *buf)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buf) - i + 1), (sizeof(char)));
	i++;
	j = 0;
	while (buf[i])
		line[j++] = buf[i++];
	free(buf);
	return (line);
}

char	*sorting_line(char *buf)
{
	char	*str;
	int	i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	str = calloc((i + 1), sizeof(char));
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		str[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		str[i++] = '\n';
	return  (str);
}

char	*read_line(int fd, char *buf)
{
	char	*str;
	int	i;

	if (!buf)
		buf = ft_calloc((1 + 1), sizeof(char));
	str = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!str || !buf)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		buf = free_and_store(str, buf);
		if (ft_strrchr(buf, '\n'))
			break;
	}
	free(str);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_line(fd, buf); //lire fd jusqu au 1er \n stock buf
	if (!buf)
		return (NULL);
	line = sorting_line(buf); //copier buf dans line sans \n
	buf = sorting_buf(buf); //garder apres \n
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char	*boulet;

// 	fd = open("42_with_nl", O_RDONLY);

// 	printf("%s", boulet = get_next_line(fd));
// 	printf("%s", boulet = get_next_line(fd));
// }