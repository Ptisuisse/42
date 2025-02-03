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

int main(void)
{
	PhoneBook   book;
	std::string command;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH or EXIT): ";
		if (!std::getline(std::cin >> std::ws, command))
		{
			std::cout << "\nGoodbye!" << std::endl;
			break;
		}
		if (command == "ADD")
			book.add_contact();
		else if (command == "SEARCH")
			book.search_contact();
		else if (command == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid command. Please use ADD, SEARCH or EXIT." << std::endl;
		std::cin.clear();
	}
	return (0);
}