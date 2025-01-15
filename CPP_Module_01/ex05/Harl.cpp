/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:00:46 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/15 18:00:47 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level)
{

}

void	Harl::error()
{
	std::cout << "Error" << std::endl;
}

void	Harl::warning()
{
	std::cout << "Warning" << std::endl;
}

void	Harl::info()
{
	std::cout << "Info" << std::endl;
}

void	Harl::debug()
{
	std::cout << "Debug" << std::endl;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}