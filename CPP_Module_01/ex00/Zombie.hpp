/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:19:24 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/15 10:19:26 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
  public:
	Zombie();
	~Zombie(void);
	Zombie(std::string name);
	void announce(void);

  private:
	std::string name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
