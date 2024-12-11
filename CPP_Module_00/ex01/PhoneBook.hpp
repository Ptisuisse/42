/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:42:18 by lvan-slu          #+#    #+#             */
/*   Updated: 2024/12/11 10:42:19 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>

class Contact
{
  public:
	Contact(void);
	~Contact(void);
	std::string last_name;
	std::string first_name;
	std::string nickname;
	std::string phone_number;
	std::string dark_secret;
};

class PhoneBook
{
  public:
	PhoneBook(std::string str);
	~PhoneBook(void);
	std::string entry;
	int contact[8];
};


class Search
{
  public:
	Search(void);
	~Search(void);
	std::string last_name;
	std::string first_name;
};

#endif
