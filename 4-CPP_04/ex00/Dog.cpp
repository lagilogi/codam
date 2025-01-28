#include "header.hpp"

/* Constructors & Destructors */
Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

/* Copy constructs */
Dog::Dog(const Dog& other)
{
	this->_type = other._type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& temp)
{
	this->_type = temp._type;
	std::cout << "Dog copy assignment operator overload called" << std::endl;
	return (*this);
}


/* Function */
void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}