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

std::string PhoneBook::truncate(std::string str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void	PhoneBook::print_list(void)
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < this->index; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(this->contact[i].get_first_name()) << "|";
		std::cout << std::setw(10) << truncate(this->contact[i].get_last_name()) << "|";
		std::cout << std::setw(10) << truncate(this->contact[i].get_nickname()) << "|";
		std::cout << std::setw(10) << truncate(this->contact[i].get_phone()) << "|";
		std::cout<< std::setw(10) << truncate(this->contact[i].get_dark()) << std::endl;
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
	std::cout << "Darkest secret: " << this->contact[i].get_dark() << std::endl;

}

std::string getValidInput(const std::string& prompt)
{
	std::string input;
	bool firstTry = true;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cin.clear();
				std::cout << "\nEOF detected. Please try again." << std::endl;
				return "";
			}
			return "";
		}
		if (!input.empty())
			break ;
		firstTry = false;
	}
	return input;
}


void	PhoneBook::add_contact()
{
	if (this->index == 8)
	{
		for (int i = 0; i < 7; i++)
			this->contact[i] = this->contact[i + 1];
		this->index = 7;
	}
	std::string firstName = getValidInput("Enter first name: ");
	if (firstName.empty())
		return;
	this->contact[this->index].set_first_name(firstName);
	std::string lastName = getValidInput("Enter last name: ");
	if (lastName.empty())
		return;
	this->contact[this->index].set_last_name(lastName);
	std::string nickname = getValidInput("Enter nickname: ");
	if (nickname.empty())
		return;
	this->contact[this->index].set_nickname(nickname);
	std::string phone = getValidInput("Enter phone number: ");
	if (phone.empty())
		return;
	this->contact[this->index].set_phone_number(phone);
	std::string dark = getValidInput("Enter darkest secret: ");
	if (dark.empty())
		return;
	this->contact[this->index].set_dark(dark);
	std::cout << "Contact added" << std::endl;
	this->index++;
}