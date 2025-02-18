#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Base& Type: A" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e)	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Base& Type: B" << std::endl;
		return ;
	}
	catch(const std::exception& e)	{}	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Base& Type: C" << std::endl;
		return ;
	}
	catch(const std::exception& e)	{}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "Base* Type: A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "Base* Type: B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "Base* Type: C" << std::endl;
}

#include <sys/time.h>

Base* generate(void)
{
	struct timeval	time;
	std::srand(time.tv_usec);
	int randomNum = std::rand() % 3;
	Base* obj;
	if (randomNum == 0)
		obj = new A();
	else if (randomNum == 1)
		obj = new B();
	else
		obj = new C();
	return (obj);
}

int main()
{
	Base* x = generate();
	identify(x);
	identify(*x);

	std::cout << '\n';

	Base* y = generate();
	identify(y);
	identify(*y);

	std::cout << '\n';

	Base* z = generate();
	identify(z);
	identify(*z);
}
