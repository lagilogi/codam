#include "Harl.hpp"

int	main()
{
	Harl harl;
	std::string input;

	do {
		std::getline(std::cin, input);
		harl.complain(input);
	} while (!input.empty());
}






