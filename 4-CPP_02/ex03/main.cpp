/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 15:31:37 by wsonepou      #+#    #+#                 */
/*   Updated: 2025/01/06 19:01:48 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(int argc, char **argv)
{
	if (bsp())
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
}
