/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 14:50:46 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/17 17:36:04 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructors & destructor
Zombie::Zombie() {}
Zombie::Zombie(std::string name) : _name(name) {}
Zombie::~Zombie() {std::cout << "Destructing " << _name << std::endl;}


// Public functions
void	Zombie::announce( void ) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
