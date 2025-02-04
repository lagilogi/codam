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
	Animal* array[10];
	for (int i = 0; i < 5; ++i) {
		array[i] = new Dog();
	}
	std::cout << std::endl;
	for (int i = 5; i < 10; ++i) {
		array[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; ++i) {
		if (i == 5)
			std::cout << std::endl;
		std::cout << array[i]->getType() << ": ";
		array[i]->makeSound();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; ++i) {
		delete array[i];
	}


	/* Deep copy check */
	std::cout << "\n--- Deep copy check ---\n" << std::endl;
	Dog d1;	std::cout << std::endl;
	Dog d2(d1); std::cout << std::endl;

	for (int i = 0; i < 12; ++i) {
		if (i % 3 == 0)
			d1.setIdeas(i , "f");
		std::cout << "1 " << d1.getIdeas(i) << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < 12; ++i) {
		std::cout << "2 " << d2.getIdeas(i) << std::endl;
	}
	std::cout << std::endl;

	Dog d3 = d1; std::cout << std::endl;

	for (int i = 0; i < 12; ++i) {
		std::cout << "3 " << d3.getIdeas(i) << std::endl;
	}
	std::cout << std::endl;

	return 0;
}