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
	robot.takeDamage(3);
	robot.beRepaired(-15);
	robot.attack("Paul");
	robot.takeDamage(-10);
	robot.beRepaired(5);
	robot.attack("Paul");
	robot.takeDamage(6);
	robot.attack("Paul");
	robot.attack("Paul");
	robot.attack("Paul");
	robot.attack("Paul");
	robot.attack("Paul");
	robot.attack("Paul");
	robot.attack("Paul");
	robot.attack("Paul");
	robot.beRepaired(10);
	robot.attack("Paul");
	return (0);
}