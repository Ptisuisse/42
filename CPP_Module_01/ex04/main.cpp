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
	std::string		line;
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	std::string		buffer;

	if (!files.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}
	while (getline(files, line))
	{
		int i = 0;
		while (line[i])
		{
			if (line.substr(i, s1.length()) == s1)
			{
				buffer += s2;
				i += s1.length();
			}
			else
			{
				buffer += line[i];
				i++;
			}
		}
		buffer += '\n';
	}
	files.close();
	create_file(argv[1], buffer);
	return 0;
}
