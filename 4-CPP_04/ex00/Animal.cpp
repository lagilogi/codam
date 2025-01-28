#include "header.hpp"

/* Constructors & Destructors */
Animal::Animal() : _type("Empty animal type")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

/* Copy constructs */
Animal::Animal(const Animal& other)
{
	this->_type = other._type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& temp)
{
	this->_type = temp._type;
	std::cout << "Animal copy assignment operator overload called" << std::endl;
	return (*this);
}


/* Function */
void	Animal::makeSound() const
{
	std::cout << "Bleh!" << std::endl;
}


/* Getter */
const std::string& Animal::getType() const
{
	return (_type);
}
