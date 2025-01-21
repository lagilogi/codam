#include "headers.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap& operator=(const DiamondTrap &temp);

		void	attack(const std::string& target); //// NOT SURE IF CORRECT WAY TO USE SCAVTRAP ATTACK FUNCTION //////
		void	whoAmI();
};