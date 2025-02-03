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

int	check_digit(const std::string& prompt, int ref)
{
	int i = 0;
 while (prompt[i])
	{
		if (ref == 1)
		{
			if (!std::isdigit(prompt[i]))
				return (0);
		}
		else if (ref == 0)
		{
			if (std::isdigit(prompt[i]))
				return (0);
		}
		i++;
	}
	return 1;
}

std::string getValidInput(const std::string& prompt, int ref)
{
	std::string input;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cin.clear();
				std::clearerr(stdin);
				std::cout << "\nEOF detected. Please try again." << std::endl;
				continue;
			}
			return "";
		}
		if (input.empty())
		{
			std::cout << "Empty input not allowed. Please try again." << std::endl;
			continue;
		}
		if (!check_digit(input, ref))
		{
			if (ref == 0)
				std::cout << "Error: Only letters allowed. Please try again." << std::endl;
			else
				std::cout << "Error: Only numbers allowed. Please try again." << std::endl;
			continue;
		}
		return input;
	}
}

void	PhoneBook::search_contact(void)
{
	std::string input;
	int i = 0;
	if (index == 0)
	{
		std::cout << "No contacts in the phonebook" << std::endl;
		return ;
	}
	this->print_list();
	input = getValidInput("Enter index of the contact you want to see: ", 1);
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



void	PhoneBook::add_contact()
{
	if (this->index == 8)
	{
		for (int i = 0; i < 7; i++)
			this->contact[i] = this->contact[i + 1];
		this->index = 7;
	}
	std::string firstName = getValidInput("Enter first name: ", 0);
	if (firstName.empty())
		return;
	this->contact[this->index].set_first_name(firstName);
	std::string lastName = getValidInput("Enter last name: ", 0);
	if (lastName.empty())
		return;
	this->contact[this->index].set_last_name(lastName);
	std::string nickname = getValidInput("Enter nickname: ", 0);
	if (nickname.empty())
		return;
	this->contact[this->index].set_nickname(nickname);
	std::string phone = getValidInput("Enter phone number: ", 1);
	if (phone.empty())
		return;
	this->contact[this->index].set_phone_number(phone);
	std::string dark = getValidInput("Enter darkest secret: ", 0);
	if (dark.empty())
		return;
	this->contact[this->index].set_dark(dark);
	std::cout << "Contact added" << std::endl;
	this->index++;
}