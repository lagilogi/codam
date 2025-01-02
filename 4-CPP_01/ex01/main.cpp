/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 14:48:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/17 17:13:12 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int i = 5;
	Zombie *horde = zombieHorde(i, "Billy");

	for (int o = 0; o < i; o++) {
		horde[o].announce();
	}
	delete[] horde;

	return 0;
}