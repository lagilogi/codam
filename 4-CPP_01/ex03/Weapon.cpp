/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 17:32:04 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/17 18:00:56 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructors & Destructors
Weapon::Weapon(std::string type) : _type(type) {}


// Getters & Setters
std::string Weapon::getType() const
{
	return _type;
}

void		Weapon::setType(std::string weapon)
{
	_type = weapon;
}
