#include "header.hpp"

/* Constructors & Destructors */
Cat::Cat() : Animal("Cat")
{
	_CatBrain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	delete _CatBrain;
	std::cout << "Cat destructor called" << std::endl;
}

/* Copy constructs */
Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = other._type;
}

Cat& Cat::operator=(const Cat& temp)
{
	std::cout << "Cat copy assignment operator overload called" << std::endl;
	if (this == &temp)
		return (*this);
	this->_type = temp._type;
	return (*this);
}


/* Function */
void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}