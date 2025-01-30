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
	this->_type = other._type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& temp)
{
	if (this == &temp)
		return (*this);
	this->_type = temp._type;
	std::cout << "WrongCat copy assignment operator overload called" << std::endl;
	return (*this);
}


/* Function */
void	WrongCat::makeSound() const
{
	std::cout << "Wroooeeoww!" << std::endl;
}