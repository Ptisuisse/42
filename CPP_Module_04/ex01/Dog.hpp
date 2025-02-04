/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:14:59 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/28 15:15:00 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public :
		Dog();
		~Dog();
		Dog(Dog const & dog);
		Dog & operator=(Dog const & dog);
		virtual void makeSound() const;
	private :
		Brain *brain;
};

#endif
