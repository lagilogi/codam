#include "header.hpp"

/* Constructor & Destructor */
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

/* Copy constructs */
Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& temp)
{
	std::cout << "Brain copy assignment operator overload called" << std::endl;
	if (this == &temp)
		return (*this);
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = temp._ideas[i];
	return (*this);
}


/* Getter & Setter */
const std::string& Brain::getIdea(int index) const
{
	return (this->_ideas[index]);
}

void Brain::setIdea(std::string& idea, int index)
{
	this->_ideas[index] = idea;
}