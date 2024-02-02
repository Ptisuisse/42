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
#include <string.h>

char	*free_and_store(char *str, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(str, buf);
	free(str);
	return (tmp);
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
	line = malloc((sizeof(char) * (ft_strlen(buf) - i +1)));
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
	str = malloc(sizeof(char) * (i + 1));
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

	// if (!buf)
	// 	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = 1;
	while (i > 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i <= 0)
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
	buf = read_line(fd, buf); //lire fd stock buf
	if (!buf)
		return (NULL);
	line = sorting_line(buf); //
	buf = sorting_buf(buf);// 
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char	*boulet;

// 	fd = open("42_with_nl", O_RDONLY);

// 	boulet = get_next_line(fd);
// }