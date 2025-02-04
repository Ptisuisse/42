/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:24:27 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/15 12:24:28 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	if (weapon == NULL)
		std::cout << name << " attacks with their hands" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon *weapon)
{
	this->weapon = weapon;
}

HumanB::HumanB(std::string name)
{
	weapon = NULL;
	this->name = name;
}

HumanB::~HumanB()
{
}