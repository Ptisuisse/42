/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:24:14 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/15 12:24:15 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type)
{
	setType(type);
}

void	Weapon::setType(const std::string type)
{
	this->type = type;
}

const std::string &Weapon::getType()
{
	return (type);
}

Weapon::Weapon()
{
	type = "default";
}

Weapon::~Weapon()
{
}

