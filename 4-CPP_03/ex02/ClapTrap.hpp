#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "headers.hpp"

class ClapTrap {
	protected:
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_attack;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &temp);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
