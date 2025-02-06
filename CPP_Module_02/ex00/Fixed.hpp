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

class Fixed
{
  public :
	Fixed(void);
	Fixed(Fixed const & src);
	~Fixed(void);
	Fixed & operator=(Fixed const & src);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
  private :
	int _integer;
	static const int _fract = 8;
};

#endif
