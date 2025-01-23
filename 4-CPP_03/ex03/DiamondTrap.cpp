#include "headers.hpp"

/* Constructors & destructor */
DiamondTrap::DiamondTrap() : ClapTrap("def_Diamondyy"), FragTrap("def_Diamondyy"), ScavTrap("def_Diamondyy"), _name("def_Diamondyy")
{
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	FragTrap::setAttackDamage(30);
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "[" << _name << "]" << " Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name), _name (name)
{
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	FragTrap::setAttackDamage(30);
	ClapTrap::_name = _name + "_clap_name";
	std::cout << _name << " DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << _name << " DiamondTrap destructor called" << std::endl;
}


/* Copy constructors */
DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_attack = other._attack;
	ClapTrap::_name = _name + "_clap_name";
	std::cout << _name << " DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &temp)
{
	if (this != &temp) {
		this->_name = temp._name;
		this->_hp = temp._hp;
		this->_ep = temp._ep;
		this->_attack = temp._attack;
		ClapTrap::_name = _name + "_clap_name";
		std::cout << _name << " DiamondTrap Copy assignment operator overload called" << std::endl;
	}
	return (*this);
}

/* Member functions */
void	DiamondTrap::whoAmI() const
{
	std::cout << "> DiamondTrap name: " << _name << " ---- ClapTrap name: " << ClapTrap::getName()
				<< " - hp: " << _hp << "  ep: " << _ep << "  attack: " << _attack << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
