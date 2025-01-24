/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:00:36 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/24 10:00:37 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool 	Fixed::operator>(Fixed const & src)
{
}

std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
	o << src.toFloat();
	return o;
}

int Fixed::toInt(void) const
{
	return (_integer >> _fract);
}

float Fixed::toFloat(void) const
{
 	return((float)_integer / (1 << _fract));
}

Fixed::Fixed(float const Float)
{
	std::cout << "Float constructor called" << std::endl;
	_integer = roundf(Float * (1 << _fract));
	return ;
}

Fixed::Fixed(int const Integer)
{
	std::cout << "Int constructor called" << std::endl;
	_integer = Integer << _fract;
	return ;
}

Fixed & Fixed::operator=(Fixed const & src)
{
	if (this != &src)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_integer = src.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	return _integer;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_integer = raw << _fract;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
Fixed::Fixed()
{
	_integer = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

