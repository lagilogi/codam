#include "Form.hpp"

/* Constructor & destructor */
Form::Form(std::string name, int rSign, int rExec) : _name(name), _requiredSign(rSign), _requiredExec(rExec), _signed(false)
{
	// std::cout << "Form default constructor called" << std::endl; 
	if (this->_requiredSign < 1 || this->_requiredExec < 1)
		throw GradeTooHighException();
	else if (this->_requiredSign > 150 || this->_requiredExec > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
	// std::cout << "Form destructor called" << std::endl; 
}


/* Copy constructors */
Form::Form(const Form& other) : _name(other._name), _requiredSign(other._requiredSign), _requiredExec(other._requiredExec), _signed(other._signed)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form copy constructor called" << std::endl;
	if (this == &other)
		return (*this);
	this->_signed = other.getSigned();
	return (*this);
}


/* Getters */
const std::string& Form::getName() const
{
	return (_name);
}

int Form::getRequiredSign() const
{
	return (_requiredSign);
}

int Form::getRequiredExec() const
{
	return (_requiredExec);
}

bool Form::getSigned() const
{
	return (_signed);
}


/* Functions */
void Form::beSigned(const Bureaucrat& bc)
{
	if (this->_signed == true)
	{
		throw FormAlreadySignedException();
	}
	else if (bc.getGrade() > this->_requiredSign)
	{
		throw GradeTooHighException();
	}
	else
	{
		this->_signed = true;
		std::cout << bc.getName() << " signed " << this->_name << std::endl;
	}
}


/* Exceptions */
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low!");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high!");
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return ("form already signed!");
}


/* Output stream */
std::ostream& operator<<(std::ostream& output, const Form& form)
{
	output	<< "Form: " << form.getName()
			<< ", required Sign grade: " << form.getRequiredSign()
			<< ", required Execution grade: " << form.getRequiredExec()
			<< ", signed: " << form.getSigned()
			<< std::endl;
	return (output);
}