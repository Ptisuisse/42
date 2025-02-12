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

int	main()
{
	ClapTrap robot("Pierre");

	robot.attack("Paul");
	robot.takeDamage(3); // -3 PDV
	robot.beRepaired(5); // Soin de 5
	robot.beRepaired(1); // Soin de 1
	robot.beRepaired(-15); // Soin de -15
	robot.beRepaired(150); // Soin de 150
	return (0);
}