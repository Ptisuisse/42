/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:42:32 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/12/11 12:26:27 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
# include <string.h>

int	main(int argc, char **argv)
{
	std::string csin;

	while (1)
	{
		std::getline(std::cin, csin);
		PhoneBook PhoneBk(csin);
		// if (csin.compare("ADD") == 0)
		// {
		// 	std::cout << "Hello, " << Contact.first_name << " " << Contact.last_name << std::endl;
		// }
	}
	return (0);
}
