/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:15:25 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/28 15:15:28 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(std::string type) : _type(type)
{
	std::cout << "Cat constructor called" << std::endl;
	_type = "Cat";
}

Cat & Cat::operator=(Cat const & cat)
{
	std::cout << "Assignation operator called" << std::endl;
	_type = cat._type;
	return *this;
}

Cat::Cat(Cat const & cat)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cat;
}

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}