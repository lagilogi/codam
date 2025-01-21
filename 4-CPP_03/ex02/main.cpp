#include "headers.hpp"

int main()
{
	FragTrap a;
	FragTrap b("Benny");
	FragTrap c = b;
	FragTrap d("Willy");

	std::cout << std::endl;

	a.attack("me");
	a.takeDamage(5);
	a.beRepaired(10);
	a.highFivesGuys();

	std::cout << std::endl;

	b.attack("you");
	b.takeDamage(7);
	b.beRepaired(10);
	b.highFivesGuys();

	std::cout << std::endl;

	c.attack("all of us");
	c.takeDamage(1000);
	c.beRepaired(3);
	c.highFivesGuys();

	std::cout << std::endl;

	d.attack("all of you");
	d.takeDamage(-20);
	d.beRepaired(-3);
	d.highFivesGuys();

	std::cout << std::endl;

	a = c;

	std::cout << std::endl;

	a.attack("me");
	a.takeDamage(5);
	a.beRepaired(10);
	a.highFivesGuys();

	std::cout << std::endl;

}
