#include "headers.hpp"

int main()
{
	DiamondTrap a;
	DiamondTrap b("Benny");
	DiamondTrap c = b;
	DiamondTrap d("Willy");

	std::cout << std::endl;

	a.attack("me");
	a.takeDamage(5);
	a.beRepaired(10);
	a.highFivesGuys();
	a.guardGate();
	a.whoAmI();

	std::cout << std::endl;

	b.attack("you");
	b.takeDamage(7);
	b.beRepaired(10);
	b.highFivesGuys();
	b.guardGate();
	b.whoAmI();

	std::cout << std::endl;

	c.attack("all of us");
	c.takeDamage(1000);
	c.beRepaired(3);
	c.highFivesGuys();
	c.guardGate();
	c.whoAmI();

	std::cout << std::endl;

	d.attack("all of you");
	d.takeDamage(-20);
	d.beRepaired(-3);
	d.highFivesGuys();
	d.guardGate();
	d.whoAmI();

	std::cout << std::endl;

	a = c;

	std::cout << std::endl;

	a.attack("me");
	a.takeDamage(5);
	a.beRepaired(10);
	a.highFivesGuys();
	a.guardGate();
	a.whoAmI();

	std::cout << std::endl;

}
