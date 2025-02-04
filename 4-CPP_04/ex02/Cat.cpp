#include "header.hpp"

/* Constructors & Destructors */
Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	_CatBrain = new Brain();
	std::string temp;
	for (int o = 0; o < 100; o++) {
		temp = "Cat idea: " + std::to_string(o);
		setIdeas(o, temp);
	}
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _CatBrain;
}


/* Copy constructs */
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_CatBrain = new Brain(*other._CatBrain);
}

Cat&	Cat::operator=(const Cat& temp)
{
	std::cout << "Cat copy assignment operator overload called" << std::endl;
	if (this == &temp)
		return (*this);
	this->_type = temp._type;
	delete _CatBrain;
	this->_CatBrain = new Brain(*temp._CatBrain);
	return (*this);
}


/* Function */
void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}


/* Getter & Setter */
void	Cat::setIdeas(int i, std::string idea)
{
	if (i < 100)
		_CatBrain->setIdea(idea, i);
}

const std::string&	Cat::getIdeas(int i) const
{
	return (_CatBrain->getIdea(i));
}