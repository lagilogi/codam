#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
	Bureaucrat	a("Billy", 10);		std::cout << a << std::endl;
	Form		b("A12", 11, 11);	std::cout << b << std::endl;
	Form		c("B23", 9, 9);		std::cout << c << std::endl;

	a.signForm(b);
	a.signForm(b);
	a.signForm(c);
}
