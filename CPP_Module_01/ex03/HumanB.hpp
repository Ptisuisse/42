/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:24:33 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/15 12:24:34 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
  public:
	HumanB(std::string name);
 	~HumanB();
	void	setWeapon(Weapon *weapon);
	void	attack();
  private:
	std::string name;
  	Weapon *weapon;
};

#endif


