#include "header.hpp"

/* Constructors & Destructors */
WrongAnimal::WrongAnimal() : _type("Empty animal type")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/* Copy constructs */
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->_type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& temp)
{
	std::cout << "WrongAnimal copy assignment operator overload called" << std::endl;
	if (this == &temp)
		return (*this);
	this->_type = temp._type;
	return (*this);
}


/* Function */
void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong Bleh!" << std::endl;
}


/* Getter */
const std::string& WrongAnimal::getType() const
{
	return (_type);
}
