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
	ClapTrap(ClapTrap const & src);
	ClapTrap & operator=(ClapTrap const & src);
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
	std::string _name;
	unsigned int _baseLife = 10;

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
	void	setEnergy();

	~ClapTrap();
};

#endif