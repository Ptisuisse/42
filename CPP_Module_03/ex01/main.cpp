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
	ScavTrap scav("ScavTrap");
	scav.attack("ClapTrap");
	scav.guardGate();
	scav.attack("ClapTrap");
	scav.guardGate();

	return (0);
}