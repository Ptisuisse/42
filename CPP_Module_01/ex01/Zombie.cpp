/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:19:16 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/15 10:19:19 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string _name)
{
	this->name = _name;
}

Zombie::Zombie()
{
	name = "Zombie";
}

Zombie::~Zombie(void)
{
	std::cout << name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiinnnzzzZZ..." << std::endl;
}

void Zombie::setName(std::string _name)
{
	name = _name;
}
