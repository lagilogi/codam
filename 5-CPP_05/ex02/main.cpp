#include "headers.hpp"

int main()
{
	Bureaucrat	a("Mob", 1);			std::cout << a << std::endl;
	Bureaucrat	b("Molly", 10);			std::cout << b << std::endl;
	Bureaucrat	c("Tully", 150);		std::cout << c << "\n" << std::endl;

	ShrubberyCreationForm	z("Ada");		std::cout << z << std::endl;
	RobotomyRequestForm 	y1("Frazer");	std::cout << y1 << std::endl;
	RobotomyRequestForm 	y2("Leah");	std::cout << y2 << std::endl;
	RobotomyRequestForm 	y3("Allen");	std::cout << y3 << std::endl;
	PresidentialPardonForm 	x("Criminal");	std::cout << x << "\n" << std::endl;

	std::cout << "--- Presidential Pardon Form ---" << std::endl;
	b.executeForm(x);
	b.signForm(x);
	c.executeForm(x);
	a.signForm(x);
	a.executeForm(x); std::cout << "\n" << std::endl;

	std::cout << "--- Robotomy Request Form ---" << std::endl;
	c.signForm(y1);
	a.signForm(y1);
	b.signForm(y2);
	b.signForm(y3); std::cout << std::endl;
	c.executeForm(y1);
	a.executeForm(y1);
	b.executeForm(y2);
	b.executeForm(y3); std::cout << "\n" << std::endl;

	std::cout << "--- Shrubbery Creation Form ---" << std::endl;
	c.signForm(z);
	b.signForm(z);
	c.executeForm(z);
	b.executeForm(z); std::cout << "\n" << std::endl;

}
