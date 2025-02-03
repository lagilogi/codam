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
	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = other._type;
}

Animal& Animal::operator=(const Animal& temp)
{
	std::cout << "Animal copy assignment operator overload called" << std::endl;
	if (this == &temp)
		return (*this);
	this->_type = temp._type;
	return (*this);
}

/* Getter */
const std::string& Animal::getType() const
{
	return (_type);
}
