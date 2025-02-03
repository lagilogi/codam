#include "headers.hpp"

/* Constructor & Destructor */
AMateria::AMateria(std::string const& type) : _type(type)
{
	std::cout << "AMateria default constructor called" << std::endl;
	_type = type;
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
}


AMateria& AMateria::operator=(const AMateria& temp)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this == &temp)
		return (*this);
	this->_type = temp._type;
	return (*this);
}


/* Getter */
std::string const& AMateria::getType() const
{
	return (_type);
}


/* Functions */
// void use(ICharacter& target)
// {
// 	// To be changed an added
// 	(void)target;
// 	// To be changed an added

// }