#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("Ben");
	ClapTrap c = b;

	std::cout << std::endl;

	a.attack("me");
	a.takeDamage(5);
	a.beRepaired(10);

	std::cout << std::endl;

	b.attack("you");
	b.takeDamage(7);
	b.beRepaired(10);

	std::cout << std::endl;

	c.attack("all of us");
	c.takeDamage(1000);
	c.beRepaired(3);

	std::cout << std::endl;

}
