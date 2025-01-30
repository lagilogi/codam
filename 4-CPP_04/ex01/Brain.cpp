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
	for (int i = 0; i < 100; ++i) {
		this->_ideas[i] = other._ideas[i];
	}
}

Brain& Brain::operator=(const Brain& temp)
{
	std::cout << "Brain copy assignment operator overload called" << std::endl;
	if (this == &temp)
		return (*this);
	for (int i = 0; i < 100; ++i) {
		this->_ideas[i] = temp._ideas[i];
	}
	return (*this);
}
