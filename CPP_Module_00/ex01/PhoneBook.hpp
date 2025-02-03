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
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);
	int index;
	void	search_contact(void);
	void	add_contact(void);
	void	print_list(void);
	std::string truncate(std::string str) const;
	Contact contact[8];
};

#endif
