/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:36:52 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/02/03 11:36:52 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain & Brain::operator=(Brain const & brain)
{
	std::cout << "Brain assignation operator called" << std::endl;
	return *this;
}

Brain::Brain(Brain const & brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
