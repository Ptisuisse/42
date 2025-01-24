/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:00:54 by lvan-slu          #+#    #+#             */
/*   Updated: 2025/01/15 18:00:55 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int get_option(std::string str)
{
    std::string OPTION[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (OPTION[i] == str)
            return (i);
    }
    return (4);
}

int main(int argc, char **argv)
{
    Harl harl;
    if (!argv[1] || argc != 2)
        return 1;
    std::string option = argv[1];

    switch (get_option(option))
    {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default :
            harl.complain(option);
    }
    return (0);
}
