#include "headers.hpp"

/* Constructor & destructor */
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), _target(target)
{
	// std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm destructor called" << std::endl;
}


/* Copy constructors */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
	// std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	// std::cout << "PresidentialPardonForm assignment operator= called" << std::endl;
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}


/* Functions */
void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->getSigned() == false)
	{
		throw FormNotSignedException();
	}
	if (executor.getGrade() > this->getRequiredExec())
	{
		throw GradeTooHighException();
	}
	else
	{
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}