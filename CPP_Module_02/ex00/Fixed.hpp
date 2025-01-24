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
	Fixed(void); //constructeur par defaut
	Fixed(Fixed const & src); // constructeur par copie
	~Fixed(void); // destructeur
	Fixed & operator=(Fixed const & src); // surchage d operateur
	int getRawBits( void ) const;
	void setRawBits( int const raw );
  private :
	int _integer;
	static const int _fract = 8;
};

#endif
