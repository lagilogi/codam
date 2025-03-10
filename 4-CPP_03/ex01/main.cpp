#include "headers.hpp"

int main()
{
	ScavTrap a;
	ScavTrap b("Benny");
	ScavTrap c = b;
	ScavTrap d("Willy");

	std::cout << std::endl;

	a.attack("me");
	a.takeDamage(5);
	a.beRepaired(10);
	a.guardGate();

	std::cout << std::endl;

	b.attack("you");
	b.takeDamage(7);
	b.beRepaired(10);
	b.guardGate();

	std::cout << std::endl;

	c.attack("all of us");
	c.takeDamage(1000);
	c.beRepaired(3);
	c.guardGate();

	std::cout << std::endl;

	d.attack("all of you");
	d.takeDamage(-20);
	d.beRepaired(-3);
	d.guardGate();

	std::cout << std::endl;
	
	a = c;

	std::cout << std::endl;

	a.attack("me");
	a.takeDamage(5);
	a.beRepaired(10);
	a.guardGate();

	std::cout << std::endl;

}
