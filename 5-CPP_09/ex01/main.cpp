#include "RPN.hpp"


// STL CONTAINER TO USE: STACK ??

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		try
		{
			RPN(argv[1]);
			return (0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error: invalid amount of arguments" << std::endl;
	return (1);
}