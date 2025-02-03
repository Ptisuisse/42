/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:12:02 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/28 15:12:04 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

void Animal::setType(std::string const & type)
{
	_type = type;
}

std::string	Animal::getType() const
{
	return _type;
}

Animal & Animal::operator=(Animal const & animal)
{
	std::cout << "Assignation operator called" << std::endl;
	_type = animal._type;
	return *this;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const & animal)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = animal;
}

Animal::Animal()
{
	_type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}