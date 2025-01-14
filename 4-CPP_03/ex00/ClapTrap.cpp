#include "ClapTrap.hpp"

/* Constructors & destructor */
ClapTrap::ClapTrap()
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _attack(0)
{
	std::cout << _name << " ClapTrap constructor called" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << _name << " ClapTrap destructor called" << std::endl;
}

/* Copy constructors */
ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_attack = other._attack;
	std::cout << _name << " ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &temp)
{
	if (this != &temp) {
		this->_name = temp._name;
		this->_hp = temp._hp;
		this->_ep = temp._ep;
		this->_attack = temp._attack;
		std::cout << _name << " ClapTrap Copy assignment operator overload called" << std::endl;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hp == 0) {
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	if (_ep == 0) {
		std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
		return ;
	}
	std::cout 	<< "Claptrap " << _name << " attacks " << target
				<< ", causing " << _attack << " points of damage!" << std::endl;
	_ep--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout	<< "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_hp -= amount;
	if (_hp < 0)
		_hp = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp == 0) {
		std::cout << "ClapTrap " << _name << " is dead and cannot repair itself!" << std::endl;
		return ;
	}
	if (_ep == 0) {
		std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " << _name << " repairs himself for " << amount << " health points!" << std::endl;
	_ep--;
	_hp += amount;
}
