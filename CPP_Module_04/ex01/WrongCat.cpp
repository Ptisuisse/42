/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:29:55 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/02/03 10:29:56 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(WrongCat const & cat)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = cat;
}

WrongCat & WrongCat::operator=(WrongCat const & cat)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	_type = cat._type;
	return *this;
}

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}
