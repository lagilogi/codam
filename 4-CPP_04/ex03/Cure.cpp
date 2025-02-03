#include "headers.hpp"

/* Constructor & destructor */
Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}


/* Copy constructors */
Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& temp)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this == &temp)
		return (*this);
	AMateria::operator=(temp);
	return (*this);
}


/* Functions */
AMateria* Cure::clone() const
{
	std::cout << "Cloning Cure Materia" << std::endl;
	AMateria* NewCure = new Cure();
	return (NewCure);
}

// void Cure::use(ICharacter& target) const
// {
// 	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
// }