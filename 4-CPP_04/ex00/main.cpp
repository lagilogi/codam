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
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* z = new WrongAnimal();
	const WrongAnimal* x = new WrongCat();
	const WrongCat* y = new WrongCat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << x->getType() << " " << std::endl;
	std::cout << std::endl;

	j->makeSound();
	j->Animal::makeSound();
	std::cout << std::endl;

	i->makeSound();
	i->Animal::makeSound();
	std::cout << std::endl;

	meta->makeSound();
	std::cout << std::endl;

	z->makeSound();
	x->makeSound();
	x->WrongAnimal::makeSound();
	y->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete z;
	delete x;
	delete y;

	return 0;
}