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
	if (health >= _hitPoints)
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

void	ClapTrap::setEnergy(int energy)
{
	_energyPoints -= 1;
}

unsigned int ClapTrap::getEnergy()
{
	return (_energyPoints);
}

void	ClapTrap::takeDamage(int amount)
{
	if (amount < 0)
	{
		std::cout << "You can't heal your enemy with your weapon" << std::endl;
		return ;
	}
	if (getHealthPoints() == 0)
	{
		std::cout << "No need to insist, " << name << " is dead" << std::endl;
		return ;
	}
	setHealthPoints(amount);
	std::cout << name << " suffers " << amount << " damage" << std::endl;
	if (getHealthPoints() <= 0)
	{
		std::cout << name << " is dead" << std::endl;
		return ;
	}
	std::cout << getHealthPoints() << " remaining life points"<<std::endl;
}

void	ClapTrap::beRepaired(int amount)
{
	if (amount < 0)
	{
		std::cout << "You can't repair negative points" << std::endl;
		return ;
	}
	if (getEnergy() == 0)
	{
		std::cout << "Not enough energy" << std::endl;
		return ;
	}
	if (getHealthPoints() <= 0)
	{
		std::cout << "It's too late... " << name << " is dead" << std::endl;
		return ;
	}
	if (amount + getHealthPoints() > 10)
	{
		std::cout << "You can't repair more than " << (10 - getHealthPoints()) << " points" << std::endl;
		return ;
	}
	setHealthPoints(-amount);
	setEnergy(_energyPoints);
	std::cout << name << " is repaired for " << amount << " points" << std::endl;
	std::cout << "Energy: " << getEnergy() << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (getEnergy() == 0)
	{
		std::cout << "Not enough energy" << std::endl;
		return ;
	}
	if (getHealthPoints() <= 0)
	{
		std::cout << "Sorry to tell you but ..." << name << " is dead" << std::endl;
		return ;
	}
	std::cout << name << " attacks " << target << ", causing " << _attackDamage << " points of damage" <<std::endl;
	setEnergy(_energyPoints);
	std::cout << "Energy: " << getEnergy() << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
}

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}