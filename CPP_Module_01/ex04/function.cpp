/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:59:34 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/24 09:59:39 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.hpp"

void	create_file(std::string const filename, std::string line)
{
	std::ofstream	output ((filename + ".replace").c_str());
	output << line;
	output.close();
}
