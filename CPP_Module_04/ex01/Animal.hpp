/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:12:07 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/28 15:12:07 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	public :
		Animal();
		~Animal();
		Animal(std::string type);
		Animal(Animal const & animal);
		Animal & operator=(Animal const & animal);
		void setType(std::string const & type);
		std::string getType() const;
		virtual void makeSound() const;
	protected:
		std::string _type;
};


#endif