#include "header.hpp"

/* Main included in subject */
// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;

// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	delete meta;
// 	delete j;
// 	delete i;

// 	return 0;
// }


/* Extended main */
int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	j->makeSound();
	// std::string temp;
	// for (int o = 0; o < 100; o++) {
	// 	temp = "Dog idea: " + std::to_string(o);
	// 	std::cout << j->getIdeas(o) << std::endl;
	// }
	std::cout << std::endl;

	i->makeSound();
	std::cout << std::endl;

	delete j;
	delete i;

	return 0;
}