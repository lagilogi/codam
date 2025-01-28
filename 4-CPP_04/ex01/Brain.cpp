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
	*this->_ideas = *other._ideas;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& temp)
{
	*this->_ideas = *temp._ideas;
	std::cout << "Brain copy assignment operator overload called" << std::endl;
	return (*this);
}
