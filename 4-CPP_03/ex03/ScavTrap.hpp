#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "headers.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &temp);

		void	guardGate() const;
		void	attack(const std::string& target);

		void	setEnergyPoints(int ep);
};

#endif