#include "header.hpp"

/* Constructors & Destructors */
Dog::Dog() : Animal("Dog")
{
	_DogBrain = new Brain();
	std::string temp;
	for (int o = 0; o < 100; o++) {
		temp = "Dog idea: " + o;
		setIdeas(o, temp);
	}
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete _DogBrain;
	std::cout << "Dog destructor called" << std::endl;
}


/* Copy constructs */
Dog::Dog(const Dog& other)
{
	this->_type = other._type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& temp)
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


/* Getter & Setter */
void	Dog::setIdeas(int i, std::string idea)
{
	if (i < 100)
		_DogBrain->_ideas[i] = idea;
}

const std::string&	Dog::getIdeas(int i) const
{
	return (_DogBrain->_ideas[i]);
}