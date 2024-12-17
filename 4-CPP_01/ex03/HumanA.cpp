/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 17:32:21 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/17 18:07:01 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructors & Destructors
HumanA::HumanA(std::string name, std::string weapon) : _name(name), _weapon(weapon) {}


// Functions
void	HumanA::attack() const
{
	std::cout << _name << " > attacks with their " << _weapon << std::endl;
}
