/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:23:48 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/15 12:23:50 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	Weapon weapon = Weapon("sword");
	HumanA bob("Bob", weapon);
	bob.attack();
	weapon.setType("axe");
	bob.attack();

	HumanB jim("Jim");
	jim.setWeapon(&weapon);
	jim.attack();
	weapon.setType("hammer");
	jim.attack();
	bob.attack();
	return (0);
}