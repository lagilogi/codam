#include "headers.hpp"

int main()
{
	DiamondTrap a;
	DiamondTrap b("Benny");
	DiamondTrap c = b;
	DiamondTrap d("Willy");

	std::cout << std::endl;

	a.whoAmI();
	a.attack("me");
	a.takeDamage(5);
	a.beRepaired(10);
	a.highFivesGuys();
	a.guardGate();

	std::cout << std::endl;

	b.whoAmI();
	b.attack("you");
	b.takeDamage(7);
	b.beRepaired(10);
	b.highFivesGuys();
	b.guardGate();

	std::cout << std::endl;

	c.whoAmI();
	c.attack("all of us");
	c.takeDamage(1000);
	c.beRepaired(3);
	c.highFivesGuys();
	c.guardGate();

	std::cout << std::endl;

	d.whoAmI();
	d.attack("all of you");
	d.takeDamage(-20);
	d.beRepaired(-3);
	d.highFivesGuys();
	d.guardGate();

	std::cout << std::endl;

	a = c;

	std::cout << std::endl;

	a.whoAmI();
	a.attack("me");
	a.takeDamage(5);
	a.beRepaired(10);
	a.highFivesGuys();
	a.guardGate();

	std::cout << std::endl;

}


// int main(void){
// 	std::cout << YELLOW "------------ ClapTrap object -----------" << RESET << std::endl;
// 	ClapTrap clap1("Clappy");
//     ClapTrap clap2("Trapster");

//     clap1.attack("Trapster");
//     clap2.takeDamage(5);
//     clap2.beRepaired(3);

//     ClapTrap clap3 = clap1;
//     clap3.attack("Trapster");

// 	std::cout << GREEN "------------ ScavTrap object -----------" << RESET << std::endl;  
// 	ScavTrap	scav("David_scav");
// 	scav.attack("his_target");
// 	scav.beRepaired(10);
// 	scav.guardGate();

// 	std::cout << BLUE "------------ FragTrap object -----------" << RESET << std::endl;
// 	FragTrap	frag("blue");
// 	frag.beRepaired(3);
// 	frag.attack("nobody");
// 	frag.highFivesGuys();

// 	std::cout << MAGENTA "------------ DiamondTrap object -----------" << RESET << std::endl;
// 	DiamondTrap		diamond("di");
// 	diamond.beRepaired(100);
// 	diamond.attack("nobody");
// 	diamond.whoAmI();
// 	DiamondTrap		diamond2 = diamond;
// 	diamond.attack("else");
// 	std::cout << RED "------------ Destroyed all objects -----------" << RESET << std::endl;
// }
