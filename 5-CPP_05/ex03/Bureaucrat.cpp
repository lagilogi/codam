#include "headers.hpp"

/* Constructor & destructor */
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	// std::cout << "Bureaucrat default constructor called" << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat destructor called" << std::endl;
}


/* Copy constructors */
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& temp)
{
	std::cout << "Bureaucrat assignment operator= called" << std::endl;
	if (this == &temp)
		return (*this);
	this->_grade = temp._grade;
	return (*this);
}


/* Assignment operators */
Bureaucrat& Bureaucrat::operator++()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	Bureaucrat temp(*this);
	this->_grade--;
	return (temp);
}

Bureaucrat& Bureaucrat::operator--()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
	return (*this);
}

Bureaucrat Bureaucrat::operator--(int)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	Bureaucrat temp(*this);
	this->_grade++;
	return (temp);
}


/* Getters */
const std::string& Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}


/* Functions */
void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& exception)
	{
		std::cout << getName() << " couldn't sign " << form.getName() << " Form because the " << exception.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cout << getName() << " couldn't execute " << form.getName() << " Form because " << exception.what() << std::endl;
	}
}


/* Exceptions */
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade too low!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade too high!");
}


/* Output stream */
std::ostream& operator<<(std::ostream& output, const Bureaucrat& bc)
{
	output << bc.getName() << ", bureaucrat grade " << bc.getGrade();
	return (output);
}