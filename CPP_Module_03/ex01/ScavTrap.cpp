/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:55:56 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/27 16:55:57 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

bool	ScavTrap::getGuardmode()
{
	return _guardMode;
}

void	ScavTrap::setGuardmode(bool mode)
{
	_guardMode = mode;
}

void	ScavTrap::attack(std::string const & target)
{
	if (getEnergy() == 0)
	{
		std::cout << "Not enough energy" << std::endl;
		return ;
	}
	if (getHealthPoints() == 0)
	{
		std::cout << "Sorry to tell you but ..." << _name << " is dead" << std::endl;
		return ;
	}
	setEnergy();
	std::cout << "ScaveTrap : "<< _name << " attack " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	std::cout << "Energy: " << getEnergy() << std::endl;
}

void	ScavTrap::guardGate()
{
	if (getHealthPoints() == 0)
	{
		std::cout << "Sorry to tell you but ..." << _name << " is dead" << std::endl;
		return ;
	}
	if (_guardMode == false)
	{
		std::cout << _name <<" enter in Gate keeper mode" << std::endl;
		_guardMode = true;
	}
	else
		std::cout << _name <<" is already in Gate keeper mode" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	if (name == "")
	{
		this->_name = "ScavTrap";
		return ;
	}
	setGuardmode(true);
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_baseLife = 100;
	std::cout << "ScavTrap " << _name << " is ready to fight!" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_baseLife = 100;
	setGuardmode(true);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
{
	if (this != &src)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
		_name = src._name;
		_baseLife = src._baseLife;
		_guardMode = src._guardMode;
	}
	return *this;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}