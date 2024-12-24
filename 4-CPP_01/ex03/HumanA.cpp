/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 17:32:21 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/20 13:53:31 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

// Constructors & Destructors
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}
HumanA::~HumanA() {}


// Functions
void	HumanA::attack() const
{
	std::cout 	<< _name
				<< " attacks with their "
				<< _weapon.getType() << std::endl;
}
