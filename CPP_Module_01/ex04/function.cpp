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
    std::ofstream outfile(output_file.c_str()); 

    if (!outfile.is_open())
    {
        std::cout << "Error: could not create output file" << std::endl;
        return;
    }
    size_t pos = 0;
    size_t nl_pos = 0;
    while ((nl_pos = s1.find("\\n")) != std::string::npos)
    {
        s1.erase(nl_pos, 2);
        s1.insert(nl_pos, "\n");
    }
    while ((nl_pos = s2.find("\\n")) != std::string::npos)
    {
        s2.erase(nl_pos, 2);
        s2.insert(nl_pos, "\n"); 
    }

    std::string buf_line;
    std::string line;
    while (getline(files, line))
        buf_line += line + "\n";
    while ((pos = buf_line.find(s1, pos)) != std::string::npos)
    {
        buf_line.erase(pos, s1.length());
        buf_line.insert(pos, s2);
        pos += s2.length();
    }

    outfile << buf_line;
    outfile.close();
}