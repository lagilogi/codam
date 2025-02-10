#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "\n1 - Try / Catch block ----" << std::endl;
		Bureaucrat d("Molly", -12);		std::cout << d << "\n" << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
	}
	
	try
	{
		std::cout << "\n2 - Try / Catch block ----" << std::endl;
		Bureaucrat e("Tilly", 12312);	std::cout << e << "\n" << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
	}

	try
	{
		std::cout << "\n3 - Try / Catch block ----" << std::endl;
		Bureaucrat f("Milly", 1);	std::cout << f << std::endl;
		++f;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << "End of Try / Catch tests----------\n" << std::endl;


	Bureaucrat a("Billy", 5);	std::cout << a << "\n" << std::endl;
	++a;						std::cout << a << "\n" << std::endl;
	a++;						std::cout << a << "\n" << std::endl;
	--a;						std::cout << a << "\n" << std::endl;
	a--;						std::cout << a << "\n" << std::endl;

	Bureaucrat b;		std::cout << b << "\n" << std::endl;
	Bureaucrat c(b);	std::cout << c << "\n" << std::endl;
	++c;				std::cout << c << "\n" << std::endl;
}
