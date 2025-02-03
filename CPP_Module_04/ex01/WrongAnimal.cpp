/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:29:44 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/02/03 10:29:45 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::setType(std::string const & type)
{
	_type = type;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & wronganimal)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = wronganimal;
}

WrongAnimal &  WrongAnimal::operator=(WrongAnimal const & wronganimal)
{
	std::cout << "Assignation operator called" << std::endl;
	_type = wronganimal._type;
	return *this;
}

WrongAnimal::WrongAnimal()
{
	_type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wronganimal destructor called" << std::endl;
}