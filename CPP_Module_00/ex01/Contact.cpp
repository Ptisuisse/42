/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:33:39 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/02/03 16:33:40 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string Contact::get_first_name(void)
{
	return (first_name);
}

std::string Contact::get_last_name(void)
{
	return (last_name);
}

std::string Contact::get_nickname(void)
{
	return (nickname);
}

std::string Contact::get_phone(void)
{
	return (phone_number);
}

std::string Contact::get_dark(void)
{
	return (darkest_secret);
}

void    Contact::set_first_name(std::string f_name)
{
    this->first_name = f_name;
}

void    Contact::set_last_name(std::string l_name)
{
    this->last_name = l_name;
}

void    Contact::set_nickname(std::string nick)
{
    this->nickname = nick;
} 

void    Contact::set_phone_number(std::string phone)
{
    this->phone_number = phone;
}

void    Contact::set_dark(std::string d_secret)
{
    this->darkest_secret = d_secret;
}
