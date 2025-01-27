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

Fixed Fixed::min(Fixed & src1, Fixed & src2)
{
	if (src1.getRawBits() < src2.getRawBits())
		return (src1);
	return (src2);
}

Fixed Fixed::min(Fixed const & src1, Fixed const & src2)
{
	if (src1.getRawBits() < src2.getRawBits())
		return (src1);
	return (src2);
}

Fixed Fixed::max(Fixed & src1, Fixed & src2)
{
	if (src1.getRawBits() > src2.getRawBits())
		return (src1);
	return (src2);
}

Fixed Fixed::max(Fixed const & src1, Fixed const & src2)
{
	if (src1.getRawBits() > src2.getRawBits())
		return (src1);
	return (src2);
}

Fixed	Fixed::operator++(void)
{
	_integer++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	_integer--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed	Fixed::operator+(Fixed const & src) const
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed	Fixed::operator-(Fixed const & src) const
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed	Fixed::operator*(Fixed const & src) const
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed	Fixed::operator/(Fixed const & src) const
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

bool 	Fixed::operator>(Fixed const & src)
{
	if (this->_integer > src._integer)
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const & src)
{
	if (this->_integer < src._integer)
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const & src)
{
	if (this->_integer >= src._integer)
		return (true);
	return (false);
}

bool 	Fixed::operator<=(Fixed const & src)
{
	if (this->_integer <= src._integer)
		return (true);
	return (false);
}

bool 	Fixed::operator==(Fixed const & src)
{
	if (this->_integer == src._integer)
		return (true);
	return (false);
}

bool 	Fixed::operator!=(Fixed const & src)
{
	if (this->_integer != src._integer)
		return (true);
	return (false);
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
	_integer = roundf(Float * (1 << _fract));
	return ;
}

Fixed::Fixed(int const Integer)
{
	_integer = Integer << _fract;
	return ;
}

Fixed & Fixed::operator=(Fixed const & src)
{
	if (this != &src)
	{
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
	this->_integer = raw << _fract;
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}
Fixed::Fixed()
{
	_integer = 0;
}

Fixed::~Fixed()
{
}

