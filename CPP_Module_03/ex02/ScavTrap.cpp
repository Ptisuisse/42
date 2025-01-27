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

void	ScavTrap::guardGate()
{
	if (getHealthPoints() == 0)
	{
		std::cout << "Sorry to tell you but ..." << name << " is dead" << std::endl;
		return ;
	}
	std::cout << "ScavTrap have enterred in Gate keeper mode" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	if (name == "")
	{
		this->name = "ScavTrap";
		return ;
	}
	std::cout << name << " is ready to fight!" << std::endl;
}

ScavTrap::ScavTrap()
{
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap" << std::endl;
}


