/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:15:31 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/28 15:15:32 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(std::string type) : _type(type)
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog & Dog::operator=(Dog const & dog)
{
	std::cout << "Assignation operator called" << std::endl;
	_type = dog._type;
	return *this;
}

Dog::Dog(Dog const & dog)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = dog;
}

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}