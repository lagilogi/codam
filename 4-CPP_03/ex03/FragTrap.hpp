#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "headers.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap& operator=(const FragTrap &temp);

		void	highFivesGuys(void) const;

		void	setHitPoints(int hp);
		void	setAttackDamage(int attack);
};

#endif