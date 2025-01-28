/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:11:13 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/28 15:11:14 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
		FragTrap();
		FragTrap(FragTrap const & src);
		FragTrap & operator=(FragTrap const & src);
		FragTrap(std::string name);
		~FragTrap();
		void highFivesGuys(void);
    private:
};

#endif
