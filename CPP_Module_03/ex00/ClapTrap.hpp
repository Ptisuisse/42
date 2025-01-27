/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:29:17 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/27 14:29:18 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class	ClapTrap
{
  private:
	ClapTrap();
	unsigned int _hitPoints = 10;
	unsigned int _energyPoints = 10;
	unsigned int _attackDamage = 0;
	std::string name;

  public :
	ClapTrap(std::string name);
	void	attack(std::string const & target);
	void	takeDamage(int amount);
	void	beRepaired(int amount);

	unsigned int	getEnergy(void);
	void setHealthPoints(int heatlh);
	unsigned int getHealthPoints(void);
	void setDamage(int damage);
	unsigned int getDamage(void);
	void	setEnergy(int energy);

	~ClapTrap();
};

#endif