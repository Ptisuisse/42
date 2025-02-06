/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:00:40 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/24 10:00:42 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
  public :
	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(int const Integer);
	Fixed(float const Float);
	~Fixed(void);
	Fixed & operator=(Fixed const & src);
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
  private :
	int _integer;
	static const int _fract = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);

#endif
