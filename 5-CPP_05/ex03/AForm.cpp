#include "headers.hpp"

/* Constructor & destructor */
AForm::AForm(std::string name, int rSign, int rExec) : _name(name), _requiredSign(rSign), _requiredExec(rExec), _signed(false)
{
	// std::cout << "AForm default constructor called" << std::endl; 
	if (this->_requiredSign < 1 || this->_requiredExec < 1)
		throw GradeTooHighException();
	else if (this->_requiredSign > 150 || this->_requiredExec > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
	// std::cout << "AForm destructor called" << std::endl; 
}


/* Copy constructors */
AForm::AForm(const AForm& other) : _name(other._name), _requiredSign(other._requiredSign), _requiredExec(other._requiredExec), _signed(other._signed)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm assignment operator= called" << std::endl;
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}


/* Getters */
const std::string& AForm::getName() const
{
	return (_name);
}

int AForm::getRequiredSign() const
{
	return (_requiredSign);
}

int AForm::getRequiredExec() const
{
	return (_requiredExec);
}

bool AForm::getSigned() const
{
	return (_signed);
}


/* Functions */
void AForm::beSigned(const Bureaucrat& bc)
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
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("form grade is too low!");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("form grade is too high!");
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return ("form is already signed!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("form is not yet signed!");
}

const char* AForm::FileErrorException::what() const throw()
{
	return ("shrubbery file could not be created!");
}


/* Output stream */
std::ostream& operator<<(std::ostream& output, const AForm& Aform)
{
	output	<< "form: " << Aform.getName()
			<< ", required Sign grade: " << Aform.getRequiredSign()
			<< ", required Execution grade: " << Aform.getRequiredExec()
			<< ", signed: " << Aform.getSigned()
			<< std::endl;
	return (output);
}