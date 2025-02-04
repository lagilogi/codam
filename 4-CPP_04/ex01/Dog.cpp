#include "header.hpp"

/* Constructors & Destructors */
Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	_DogBrain = new Brain();
	std::string temp;
	for (int o = 0; o < 100; o++) {
		temp = "Dog idea: " + std::to_string(o);
		setIdeas(o, temp);
	}
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _DogBrain;
}


/* Copy constructs */
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_DogBrain = new Brain(*other._DogBrain);
}

Dog&	Dog::operator=(const Dog& temp)
{
	std::cout << "Dog copy assignment operator overload called" << std::endl;
	if (this == &temp)
		return (*this);
	this->_type = temp._type;
	delete _DogBrain;
	this->_DogBrain = new Brain(*temp._DogBrain);
	return (*this);
}


/* Function */
void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}


/* Getter & Setter */
void	Dog::setIdeas(int i, std::string idea)
{
	if (i < 100)
		_DogBrain->setIdea(idea, i);
}

const std::string&	Dog::getIdeas(int i) const
{
	return (_DogBrain->getIdea(i));
}