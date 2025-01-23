#include "headers.hpp"

/* Constructors & destructor */
FragTrap::FragTrap() : ClapTrap("def_Fragyy")
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	_hp = 100;
	_ep = 100;
	_attack = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << _name << " FragTrap constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_ep = 100;
	_attack = 30;
}

FragTrap::~FragTrap()
{
	std::cout << _name << " FragTrap destructor called" << std::endl;
}

/* Copy constructors */
FragTrap::FragTrap(const FragTrap &other)
{
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_attack = other._attack;
	std::cout << _name << " FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &temp)
{
	if (this != &temp) {
		this->_name = temp._name;
		this->_hp = temp._hp;
		this->_ep = temp._ep;
		this->_attack = temp._attack;
		std::cout << _name << " FragTrap Copy assignment operator overload called" << std::endl;
	}
	return (*this);
}


/* Functions */
void	FragTrap::highFivesGuys(void) const
{
	if (_hp == 0) {
		std::cout << "FragTrap " << _name << " is dead and cannot highfive!" << std::endl;
		return ;
	}
	if (_ep == 0) {
		std::cout << "FragTrap " << _name << " has no energy points left!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " requests a Super Special High Five! ... Guys? ..hello? ..owh.. they left.." << std::endl;
}


/* Getters */
void		FragTrap::setHitPoints(int hp)
{
	_hp = hp;
}

void		FragTrap::setAttackDamage(int attack)
{
	_attack = attack;
}