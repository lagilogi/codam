#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "headers.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &temp);

		void	guardGate();
		void	attack(const std::string& target);
};

#endif