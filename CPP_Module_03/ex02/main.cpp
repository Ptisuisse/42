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
	std::cout << "-------CONSTRUCTOR--------" << std::endl;
	ScavTrap scav("SCAV");
	ClapTrap clap("CLAP");
	FragTrap frag("FRAG");
	std::cout << "------------CLAPTRAP----------" << std::endl;
	clap.attack("Paul");
	clap.takeDamage(3); 
	clap.beRepaired(5);
	clap.beRepaired(1);
	clap.beRepaired(-15);
	clap.beRepaired(150);
	clap.takeDamage(3);
	clap.attack("Paul");
	clap.attack("Paul");
	clap.attack("Paul");
	clap.attack("Paul");
	clap.attack("Paul");
	clap.attack("Paul");
	clap.attack("Paul");
	clap.attack("Paul");
	clap.attack("Paul");
	clap.beRepaired(1);
	clap.takeDamage(10);
	clap.beRepaired(1);
	clap.attack("Paul");
	std::cout << "------------SCAVTRAP----------" << std::endl;
	scav.attack("Paul");
	scav.takeDamage(3); 
	scav.beRepaired(5);
	scav.beRepaired(1);
	scav.beRepaired(-15);
	scav.beRepaired(150);
	scav.takeDamage(3);
	scav.attack("Paul");
	scav.attack("Paul");
	scav.attack("Paul");
	scav.attack("Paul");
	scav.attack("Paul");
	scav.attack("Paul");
	scav.attack("Paul");
	scav.attack("Paul");
	scav.beRepaired(1);
	scav.takeDamage(100);
	scav.beRepaired(1);
	scav.attack("Paul");
	std::cout << "------------FRAGTRAP----------" << std::endl;
	frag.attack("Paul");
	frag.takeDamage(3); 
	frag.beRepaired(5);
	frag.beRepaired(1);
	frag.beRepaired(-15);
	frag.beRepaired(150);
	frag.takeDamage(3);
	frag.attack("Paul");
	frag.attack("Paul");
	frag.attack("Paul");
	frag.attack("Paul");
	frag.attack("Paul");
	frag.attack("Paul");
	frag.attack("Paul");
	frag.attack("Paul");
	frag.beRepaired(1);
	frag.takeDamage(100);
	frag.beRepaired(1);
	frag.attack("Paul");
	std::cout << "-------DESTRUCTOR--------" << std::endl;

	return (0);
}