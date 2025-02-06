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
	void	(Harl::*ptr[4])() = {&Harl::error, &Harl::warning, &Harl::info, &Harl::debug};
	std::string	level_list[4] = {"ERROR", "WARNING", "INFO", "DEBUG"};
	if (level == "ERROR" || level == "WARNING" || level == "INFO" || level == "DEBUG")
		std::cout << "[" << level << "]" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (level == level_list[i])
			(this->*ptr[i])();
	}
	if (level != "ERROR" && level != "WARNING" && level != "INFO" && level != "DEBUG")
		std::cout << "Complains again but we don't know what" << std::endl;
	return ;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}