#include "Bureaucrat.hpp"

/* Constructor & destructor */
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	try
	{
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	if (_grade < 0 || _grade > 150)
		throw ("Errorrroreoreoro");
	
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}


/* Copy constructors */
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& temp)
{
	if (this == &temp)
		return (*this);
	this->_grade = temp._grade;
	return (*this);
}


/* Assignment operators */
Bureaucrat& Bureaucrat::operator++()
{
	this->_grade--;
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat temp(*this);
	this->_grade--;
	return (temp);
}

Bureaucrat& Bureaucrat::operator--()
{
	this->_grade++;
	return (*this);
}

Bureaucrat Bureaucrat::operator--(int)
{
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


/* Output stream */
std::ostream& operator<<(std::ostream& output, const Bureaucrat& bc)
{
	output << bc.getName() << ", bureaucrat grade " << bc.getGrade();
	return (output);
}