#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Billy", 5);	std::cout << a << "\n" << std::endl;
	++a;						std::cout << a << "\n" << std::endl;
	a++;						std::cout << a << "\n" << std::endl;
	a--;						std::cout << a << "\n" << std::endl;
	--a;						std::cout << a << "\n" << std::endl;

	Bureaucrat b;	std::cout << b << "\n" << std::endl;

	Bureaucrat c("Molly", -12);		std::cout << c << "\n" << std::endl;
	Bureaucrat d("Tilly", 12312);	std::cout << d << "\n" << std::endl;
}