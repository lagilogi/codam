#include "Harl.hpp"

// Constructors & destructors
Harl::Harl() {}
Harl::~Harl() {}


// Private functions
void	Harl::debug(void)
{
	std::cout << "DEBUGGING: debugging description" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO: info description" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING: warning description" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR: error description" << std::endl;
}


// Public functions
void	Harl::complain(std::string level)
{
	int	i;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	funcPtr		complaints[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (i = 0; i < 4; i++) {
		if (levels[i] == level)
			break;
	}
	switch(i) {
		case 0:
			(this->*complaints[0])();
		case 1:
			(this->*complaints[1])();
		case 2:
			(this->*complaints[2])();
		case 3:
			(this->*complaints[3])();
		default:
			std::cout << "Hmm, this is a weird message, hmm.." << std::endl;
	}
}

