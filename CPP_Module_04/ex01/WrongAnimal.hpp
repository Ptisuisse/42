/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:29:49 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/02/03 10:29:50 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const & wronganimal);
		WrongAnimal & operator=(WrongAnimal const & wronganimal);
		void setType(std::string const & type);
		std::string getType() const;
		virtual void makeSound() const;
	protected:
		std::string _type;
};

#endif
