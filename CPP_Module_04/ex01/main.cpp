/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:11:48 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/28 15:11:53 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include "Brain.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* l = new Cat();
	const WrongAnimal* i = new WrongCat();
	const WrongAnimal* k = new WrongAnimal();
	std::cout << "---------------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << "---------------" << std::endl;
	j->makeSound();
	l->makeSound();
	i->makeSound();
	meta->makeSound();
	k->makeSound();
	std::cout << "---------------" << std::endl;
	delete meta;
	delete j;
	delete l;
	delete k;
	delete i;
	return (0);
}