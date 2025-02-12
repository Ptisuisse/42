/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:29:22 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/27 14:29:22 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	frag("BILOUTE");
	ScavTrap	scav("RENE");
	ClapTrap	clap("CLAP");
	std::cout << "----------CONSTRUCTOR------------" << std::endl;
	clap.attack("ScavTrap");
	clap.attack("ScavTrap");
	clap.takeDamage(10);
	std::cout << "----------------------" << std::endl;
	scav.guardGate();
	scav.guardGate();
	scav.attack("FragTrap");
	scav.attack("FragTrap");
	std::cout << "----------------------" << std::endl;
	frag.attack("ScavTrap");
	frag.highFivesGuys();
	frag.attack("ScavTrap");
	std::cout << "--------DESTRUCTOR---------" << std::endl;

	return (0);
}