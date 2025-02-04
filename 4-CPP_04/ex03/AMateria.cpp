#include "headers.hpp"

/* Constructor & Destructor */
AMateria::AMateria(std::string const& type) : _type(type), _equiped(false)
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}


/* Copy constructors */
AMateria::AMateria(const AMateria& other)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	this->_type = other._type;
	this->_equiped = false;
}

AMateria& AMateria::operator=(const AMateria& temp)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this == &temp)
		return (*this);
	this->_type = temp._type;
	this->_equiped = false;
	return (*this);
}


/* Getter */
std::string const& AMateria::getType() const
{
	return (_type);
}

bool AMateria::getEquiped() const
{
	return (this->_equiped);
}

void AMateria::setEquiped(bool equiped)
{
	this->_equiped = equiped;
}

/* Functions */
void AMateria::use(ICharacter& target)
{
	(void)target;
}