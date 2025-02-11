#include "headers.hpp"

/* Constructor & destructor */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
	// std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}


/* Copy constructors */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
	// std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	// std::cout << "ShrubberyCreationForm assignment operator= called" << std::endl;
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}


/* Functions */
void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
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
		std::ofstream newfile(_target + "_shrubbery");
		if (!newfile.is_open())
			throw FileErrorException();
		else
		{
			newfile <<	"            ,@@@@@@@,\n" <<
						"	,,,.   ,@@@@@@/@@,  .oo8888o.\n" <<
						",&%&&%&&%,@@@@@/@@@@@@,8888\\88/8o\n" <<
						",%&/%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n" <<
						"%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n" <<
						"%&&%/ %&&%&&@@\\ V /@@' `88\\8 `/88'\n" <<
						"`&%\\ ` /%&'    |.|        \\ '|8'\n" <<
						"	|o|        | |         | |\n" <<
						"	|.|        | |         | |\n" <<
						"__\\/ ._\\//_/__/  ,\\__//__\\/.  \\_//_";
		}
		newfile.close();
	}
}
