#include "headers.hpp"

/* Constructors & destructor */
DiamondTrap::DiamondTrap() : FragTrap("def_Diamondyy"), ScavTrap("def_Diamondyy")
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	_hp = FragTrap::getHitPoints();
	_ep = ScavTrap::getEnergyPoints();
	_attack = FragTrap::getAttackDamage();

}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name)
{
	std::cout << _name << " DiamondTrap constructor called" << std::endl;
	_name = name;
	_hp = FragTrap::getHitPoints();
	_ep = ScavTrap::getEnergyPoints();
	_attack = FragTrap::getAttackDamage();
	ClapTrap::_name = name.append("_clap_name");
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
	std::cout << _name << " DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &temp)
{
	if (this != &temp) {
		this->_name = temp._name;
		this->_hp = temp._hp;
		this->_ep = temp._ep;
		this->_attack = temp._attack;
		std::cout << _name << " DiamondTrap Copy assignment operator overload called" << std::endl;
	}
	return (*this);
}

/* Member functions */
void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << " & ClapTrap name: " << ClapTrap::getName() << std::endl;
}

void	DiamondTrap::attack(const std::string& target) //// NOT SURE IF CORRECT WAY TO USE SCAVTRAP ATTACK FUNCTION //////
{
	ScavTrap::attack(target);
}
