#include "headers.hpp"

/* Constructors & destructor */
ScavTrap::ScavTrap() : ClapTrap("def_scavyy")
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	_hp = 100;
	_ep = 50;
	_attack = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << _name << " ScavTrap constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_ep = 50;
	_attack = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << _name << " ScavTrap destructor called" << std::endl;
}

/* Copy constructors */
ScavTrap::ScavTrap(const ScavTrap &other)
{
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_attack = other._attack;
	std::cout << _name << " ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &temp)
{
	if (this != &temp) {
		this->_name = temp._name;
		this->_hp = temp._hp;
		this->_ep = temp._ep;
		this->_attack = temp._attack;
		std::cout << _name << " ScavTrap Copy assignment operator overload called" << std::endl;
	}
	return (*this);
}


/* Functions */
void	ScavTrap::guardGate() const
{
	if (_hp == 0) {
		std::cout << "ScavTrap " << _name << " is dead and cannot go into Gatekeeper mode!" << std::endl;
		return ;
	}
	if (_ep == 0) {
		std::cout << "ScavTrap " << _name << " has no energy points left!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hp == 0) {
		std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	if (_ep == 0) {
		std::cout << "ScavTrap " << _name << " has no energy points left!" << std::endl;
		return ;
	}
	std::cout 	<< "Scavtrap " << _name << " attacks " << target
				<< ", causing " << _attack << " points of damage!" << std::endl;
	_ep--;
}

void	ScavTrap::setEnergyPoints(int ep)
{
	_ep = ep;
}
