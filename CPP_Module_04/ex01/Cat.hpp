/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:15:05 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/28 15:15:07 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public :
		Cat();
		~Cat();
		Cat(Cat const & cat);
		Cat & operator=(Cat const & cat);
		virtual void makeSound() const;
	private :
		Brain *brain;
};

#endif