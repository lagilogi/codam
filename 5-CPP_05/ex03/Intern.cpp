#include "headers.hpp"

/* Constructor & destructor */
Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;

}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}


/* Copy constructors */
Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern assignment operator= called" << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}


/* Exceptions */
const char* Intern::NonexistentFormException::what() const throw()
{
	return (" form does not exist and thus could not be made by the intern");
}



/* Functions */
AForm* Intern::makeForm(std::string formName, std::string targetName)
{
	int i;
	std::string forms[] = {	"presidential pardon",
							"robotomy request",
							"shrubbery creation" };
	for (i = 0; i < 3; ++i)
		if (formName == forms[i])
			break;
	try
	{
		AForm *form;
		switch (i)
		{
		case 0:
			form = new PresidentialPardonForm(targetName);
			break ;
		case 1:
			form = new RobotomyRequestForm(targetName);
			break ;
		case 2:
			form = new ShrubberyCreationForm(targetName);
			break ;
		default:
			throw NonexistentFormException();
		}
		std::cout << "Intern creates " << form->getName() << std::endl;
		return (form);
	}
	catch(const std::exception& exception)
	{
		std::cout << formName << exception.what() << std::endl;
	}
	return (nullptr);
}
