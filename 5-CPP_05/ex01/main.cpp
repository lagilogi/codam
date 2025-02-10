#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
	Bureaucrat	a("Billy", 10);			std::cout << a << std::endl;
	Form		b("poll", 11, 11);		std::cout << b << std::endl;
	Form		c("Something", 9, 9);	std::cout << c << std::endl;

	try
	{
		a.signForm(b);
		a.signForm(c);
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
	}
}
