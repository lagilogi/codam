#include "headers.hpp"

/* Constructor & destructor */
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target)
{
	// std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
}


/* Copy constructors */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
	// std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	// std::cout << "RobotomyRequestForm cassignment operator= called" << std::endl;
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}


/* Functions */
void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
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
		srand(std::chrono::system_clock::now().time_since_epoch().count());
		int chance = rand() % 2;
		if (chance == 1)
			std::cout << this->_target << " has been succesfully robotomized!" << std::endl;
		else
			std::cout << "The robotomy on " << this->_target << " was unsuccesful.." << std::endl;
	}
}