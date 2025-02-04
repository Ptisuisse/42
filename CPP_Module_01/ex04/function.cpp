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

void	ft_replace(std::ifstream &files, std::string s1, std::string s2, std::string file)
{
    std::string output_file = file + ".replace";
    std::ofstream outfile(output_file);

    if (!outfile.is_open())
    {
        std::cout << "Error: could not create output file" << std::endl;
        return;
    }

    std::string line;
    while (getline(files, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line << std::endl;
    }
    outfile.close();
}