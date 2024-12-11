/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:42:14 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/12/11 10:42:15 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(std::string str) : entry(str)
{
	if (entry.compare("ADD") == 0)
		Contact;
	if (entry.compare("EXIT") == 0)
		exit(1) ;
	return ;
}

Contact::Contact()
{
	std::cout << "first name : ";
	std::getline (std::cin,this->first_name);
	std::cout << "last name : ";
	std::getline (std::cin,this->last_name);
	std::cout << "nickname : ";
	std::getline (std::cin,this->nickname);
	std::cout << "phone number: ";
	std::getline (std::cin,this->phone_number);
	std::cout << "dark secret : ";
	std::getline (std::cin,this->dark_secret);
	return ;
}

Contact::~Contact(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}