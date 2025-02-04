#include "headers.hpp"

/* Constructor & destructor */
MateriaSource::MateriaSource()
{
	std::cout << "Materia default constructor" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->array[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Materia destructor" << std::endl;
	for (int i = 0; i < 4; ++i)
		if (this->array[i] != nullptr)
			delete array[i];
}


/* Copy constructors */
MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "Materia copy constructor" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other.array[i] != nullptr)
			this->array[i] = other.array[i]->clone();
		else
			this->array[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& temp)
{
	std::cout << "Materia assignment operator constructor" << std::endl;
	if (this == &temp)
		return (*this);
	for (int i = 0; i < 4; ++i)
		if (temp.array[i] != nullptr)
			this->array[i] = temp.array[i]->clone();
	return (*this);
}


/* Functions */
void MateriaSource::learnMateria(AMateria* m)
{
	if (m == nullptr)
		return ;
	int i;
	for (i = 0; i < 4; ++i)
	{
		if (this->array[i] == nullptr)
		{
			this->array[i] = m;
			std::cout << m->getType() << " was learned" << std::endl;
			break ;
		}
	}
	if (i > 3)
	{
		std::cout << m->getType() << " could not be learned - SourceMateria is full" << std::endl;
		delete m;
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->array[i] != nullptr && type == this->array[i]->getType())
		{
			std::cout << type << " materia created!" << std::endl;
			return (this->array[i]->clone());
		}
	}
	std::cout << "Couldn't find and create " << type << std::endl;
	return (nullptr);
}