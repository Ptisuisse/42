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
  protected :
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
	std::string name;

  public :
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
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