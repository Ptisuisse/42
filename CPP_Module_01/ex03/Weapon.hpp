/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:24:10 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/15 12:24:11 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>

class Weapon
{
  public:
	Weapon();
	~Weapon();
	Weapon(const std::string type);
	const std::string &getType();
	void	setType(const std::string type);
  private:
	std::string type;
};

#endif