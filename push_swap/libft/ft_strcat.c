/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:56:24 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/09/28 17:40:42 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	destlen;

	destlen = 0;
	while (dest[destlen] != '\0')
		destlen++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[i + destlen] = src [i];
		i++;
	}
	dest[i + destlen] = '\0';
	return (dest);
}
