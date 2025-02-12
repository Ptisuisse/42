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

int	main()
{
	ScavTrap scav("SCAV");
	ClapTrap clap("CLAP");
	std::cout << "-------CONSTRUCTOR--------" << std::endl;
	scav.beRepaired(1);
	scav.takeDamage(1);
	scav.beRepaired(2);
	scav.beRepaired(1);
	scav.attack("CLAP");
	std::cout << "----------------" << std::endl;
	clap.beRepaired(1);
	clap.takeDamage(1);
	clap.beRepaired(2);
	clap.beRepaired(1);
	clap.attack("SCAV");
	std::cout << "-------DESTRUCTOR--------" << std::endl;
	return (0);
}