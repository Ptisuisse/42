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

PhoneBook::PhoneBook(void)
{
	this->index = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::print_list(void)
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < this->index; i++)
	{
		//std::cout << std::setw(10) << this->contact[i].index << "|";
		std::cout << std::setw(10) << this->contact[i].get_first_name() << "|";
		std::cout << std::setw(10) << this->contact[i].get_last_name() << "|";
		std::cout << std::setw(10) << this->contact[i].get_nickname() << std::endl;
	}
}

void	PhoneBook::search_contact(void)
{
	int i = 0;
	if (index == 0)
	{
		std::cout << "No contacts in the phonebook" << std::endl;
		return ;
	}
	this->print_list();
	std::cout << "Enter index of the contact you want to see: ";
	std::cin >> i;
	if (std::cin.fail() || i < 0 || i >= this->index)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << "First name: " << this->contact[i].get_first_name() << std::endl;
	std::cout << "Last name: " << this->contact[i].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->contact[i].get_nickname() << std::endl;
	std::cout << "Phone number: " << this->contact[i].get_phone() << std::endl;
	std::cout
		<< "Darkest secret: " << this->contact[i].get_dark() << std::endl;

}

void	PhoneBook::add_contact()
{
	std::string input;
	if (this->index == 8)
	{
        for (int i = 0; i < 7; i++)
            this->contact[i] = this->contact[i + 1];
        this->index = 7;
	}
	std::cout << "Enter first name: ";
	std::cin >> input;
	this->contact[this->index].set_first_name(input);
	std::cout << "Enter last name: ";
	std::cin >> input;
	this->contact[this->index].set_last_name(input);
	std::cout << "Enter nickname: ";
	std::cin >> input;
	this->contact[this->index].set_nickname(input);
	std::cout << "Enter phone number: ";
	std::cin >> input;
	this->contact[this->index].set_phone_number(input);
	std::cout << "Enter darkest secret: ";
	std::cin >> input;
	this->contact[this->index].set_dark(input);
	this->contact[this->index].set_index(this->index);
	this->index++;
}