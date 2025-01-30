#include "header.hpp"

/* Constructors & Destructors */
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/* Copy constructs */
WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->_type = other._type;
}

WrongCat& WrongCat::operator=(const WrongCat& temp)
{
	std::cout << "WrongCat copy assignment operator overload called" << std::endl;
	if (this == &temp)
		return (*this);
	this->_type = temp._type;
	return (*this);
}


/* Function */
void	WrongCat::makeSound() const
{
	std::cout << "Wroooeeoww!" << std::endl;
}