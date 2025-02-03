#include "headers.hpp"

/* Constructor & destructor */
Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

/* Copy constructors */
Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& temp)
{
	std::cout << "Ice assignment operator called" << std::endl;
	if (this == &temp)
		return (*this);
	AMateria::operator=(temp);
	return (*this);
}


/* Functions */
AMateria* Ice::clone() const
{
	std::cout << "Cloning Ice Materia" << std::endl;
	AMateria* IceClone = new Ice(*this);
	return (IceClone);
}

// void Ice::use(ICharacter& target) const
// {
// 	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
// }






