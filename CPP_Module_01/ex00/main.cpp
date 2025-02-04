/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:18:41 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/15 10:18:46 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	randomChump("Zombie");
	Zombie	Zomb("Eric");
	Zomb.announce();
	Zombie *zomb2 = newZombie("Bob");
	zomb2->announce();
	delete zomb2;
	return (0);
}
