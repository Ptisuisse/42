/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:29:12 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/27 14:29:12 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	ClapTrap::setDamage(int damage)
{
	_attackDamage = damage;
}

unsigned int	ClapTrap::getDamage()
{
	return (_attackDamage);
}

void	ClapTrap::setHealthPoints(int health)
{
	if ((unsigned)health >= _hitPoints)
	{
		_hitPoints = 0;
		return ;
	}
	_hitPoints -= health;
}

unsigned int	ClapTrap::getHealthPoints()
{
	return (_hitPoints);
}

void	ClapTrap::setEnergy()
{
	if (_energyPoints > 0)
		_energyPoints--;
}

unsigned int ClapTrap::getEnergy()
{
	return (_energyPoints);
}

void	ClapTrap::takeDamage(int amount)
{
	if (getHealthPoints() == 0)
	{
		std::cout << "No need to insist, " << _name << " is dead" << std::endl;
		return ;
	}
	if (amount < 0)
	{
		std::cout << "You can't heal your enemy with your weapon" << std::endl;
		return ;
	}
	setHealthPoints(amount);
	std::cout << _name << " suffers " << amount << " damage" << std::endl;
	if (getHealthPoints() <= 0)
	{
		std::cout << _name << " is dead" << std::endl;
		return ;
	}
	std::cout << getHealthPoints() << " remaining hit points"<<std::endl;
}

void	ClapTrap::beRepaired(int amount)
{
	if (getHealthPoints() <= 0)
	{
		std::cout << "It's too late... " << _name << " is dead" << std::endl;
		return ;
	}
	if (amount < 0)
	{
		std::cout << "You can't repair yourself by giving damage" << std::endl;
		return ;
	}
	if (getEnergy() == 0)
	{
		std::cout << "Not enough energy" << std::endl;
		return ;
	}
	else if (amount + getHealthPoints() > _baseLife)
	{
		std::cout << "You can't repair more than max hit points (" << (_baseLife - getHealthPoints()) << ")" << std::endl;
		return ;
	}
	else
		_hitPoints += amount;
	setEnergy();
	std::cout << _name << " is repaired for " << amount << " points" << std::endl;
	std::cout << "Energy: " << getEnergy() << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (getHealthPoints() <= 0)
	{
		std::cout << "Sorry to tell you but ..." << _name << " is dead" << std::endl;
		return ;
	}
	if (getEnergy() == 0)
	{
		std::cout << "Not enough energy" << std::endl;
		return ;
	}
	setEnergy();
	std::cout << "ClapTrap : " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage" <<std::endl;
	std::cout << "Energy: " << getEnergy() << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	if (name == "")
	{
		this->_name = "ClapTrap";
		return ;
	}
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	this->_baseLife = 10;
	std::cout << "ClapTrap :" << _name << " is ready to fight!" << std::endl;
}

ClapTrap::ClapTrap()
{
	this->_name = "ClapTrap";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	this->_baseLife = 10;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
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

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}