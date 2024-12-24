/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 17:32:04 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/20 17:42:27 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

// Constructors & Destructors
Weapon::Weapon(const std::string type) : _type(type) {}
Weapon::~Weapon() {}


// Getters & Setters
std::string Weapon::getType() const
{
	return _type;
}

void		Weapon::setType(const std::string weapon)
{
	_type = weapon;
}
