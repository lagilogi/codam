#include "headers.hpp"

int main()
{
	Intern lena;													std::cout << std::endl;

	std::cout << "--- Form creation ---" << std::endl;
	AForm* x = lena.makeForm("presidential pardon", "target 1");	std::cout << x << "\n" << std::endl;
	AForm* y = lena.makeForm("robotomy request", "target 2");		std::cout << y << "\n" << std::endl;
	AForm* z = lena.makeForm("shrubbery creation", "target 3");		std::cout << z << "\n" << std::endl;
	AForm* o = lena.makeForm("B23-C", "target 4");					std::cout << o << "\n" << std::endl;

	Bureaucrat	a("Mob", 1);
	Bureaucrat	b("Molly", 10);
	Bureaucrat	c("Tully", 150); 									std::cout << std::endl;

	std::cout << "--- Signing & executing forms ---" << std::endl;
	c.signForm(*x);
	c.signForm(*y);
	c.signForm(*z); 												std::cout << std::endl;

	b.signForm(*x);
	b.signForm(*y);
	b.signForm(*z); 												std::cout << std::endl;	

	a.executeForm(*x);
	a.executeForm(*y);
	a.executeForm(*z); 												std::cout << std::endl;	

	delete x;
	delete y;
	delete z;
}
