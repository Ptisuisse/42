/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:11:10 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/28 15:11:11 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void    FragTrap::highFivesGuys(void)
{
	if (getHealthPoints() == 0)
	{
		std::cout << "Sorry to tell you but ..." << _name << " is dead" << std::endl;
		return ;
	}
	std::cout << _name << " is asking for a high five!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	if (name == "")
	{
		this->_name = "FragTrap";
		return ;
	}
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap : "<< _name << " is ready to fight!" << std::endl;
}

FragTrap::FragTrap()
{
}

FragTrap::~FragTrap()
{
	std::cout << " FragTrap Destructor Called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
{
	if (this != &src)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
		_name = src._name;
	}
	return *this;
}
