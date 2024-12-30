/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 15:18:26 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/30 15:18:34 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl harl;
	std::string input;

	do {
		std::getline(std::cin, input);
		harl.complain(input);
	} while (!input.empty());
}
