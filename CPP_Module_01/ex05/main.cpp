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

int main(int argc, char **argv)
{

    Harl	harl;
    if (!argv[1] || argc != 2)
        return 1;
    std::string entry = argv[1];
    harl.complain(entry);
    return (0);
}
