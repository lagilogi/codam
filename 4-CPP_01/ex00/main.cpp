/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 14:48:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/17 16:20:30 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *ez = newZombie("Billy");
	randomChump("Milly");
	delete ez;
	return 0;
}