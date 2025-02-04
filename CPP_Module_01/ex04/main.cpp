/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:30:33 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/15 15:30:35 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	std::ifstream	files(argv[1]);
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	std::string file = argv[1];

	if (s1.empty())
    {
        std::cout << "Error: search string is empty" << std::endl;
        return 1;
    }
	if (!files.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}
	ft_replace(files, s1, s2, file);
	files.close();
	return 0;
}