/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:56:00 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/27 16:56:01 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  public :
	ScavTrap(ScavTrap const & src);
	ScavTrap & operator=(ScavTrap const & src);
	ScavTrap(std::string name);
	ScavTrap();
	~ScavTrap();
	void	setGuardmode(bool mode);
	bool	getGuardmode();
	void	guardGate();
	void	attack(std::string const & target);
  private :
	bool _guardMode;
};

#endif
