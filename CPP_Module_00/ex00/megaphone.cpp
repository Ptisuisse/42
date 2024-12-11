/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:34:30 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/12/11 10:34:32 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	std::string str;
	int i = 1;
	int j;

	if (ac > 1)
	{
		while (av[i])
		{
			std::string str = av[i];
			j = 0;
			while (str[j])
				std::cout << (char)toupper(str[j++]);
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}