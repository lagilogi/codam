/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 17:33:07 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/17 18:09:36 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructors & Destructors
HumanB::HumanB(std::string name) : _name(name) {}
HumanB::HumanB(std::string name, std::string weapon) : _name(name), _weapon(weapon) {}

// Functions
void	HumanB::attack() const
{
	std::cout << _name << " > attacks with their " << _weapon << std::endl;
}
