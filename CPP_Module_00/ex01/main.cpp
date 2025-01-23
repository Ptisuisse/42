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
    PhoneBook   book;
    std::string command;

    while (1)
    {
        std::cout << "Enter command (ADD, SEARCH or EXIT): ";
        std::cin >> command;
        
        if (command == "ADD")
            book.add_contact();
        else if (command == "SEARCH")
            book.search_contact();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "Invalid command" << std::endl;
    }
    return (0);
}
