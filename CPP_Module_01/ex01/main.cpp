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
	Zombie *zomb;

	zomb = zombieHorde(2, "Fred");
	zomb[0].announce();
	delete [] zomb;

	Zombie *Zomb2;
	Zomb2 = zombieHorde(5, "Jean");
	delete [] Zomb2;
	return (0);
}
