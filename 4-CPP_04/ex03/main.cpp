#include "headers.hpp"

int main(void)
{
	AMateria* i1 = new Ice;
	std::cout << i1->getType() << "\n" << std::endl;
	AMateria* i2 = i1->clone();
	std::cout << i2->getType() << "\n" << std::endl;
	AMateria* i3 = i1;
	std::cout << i3->getType() << "\n" << std::endl;
	i1 = new Cure();
	std::cout << i1->getType() << "\n" << std::endl;

	Character c1("Billy");
	c1.equip(i1);
	c1.equip(i2);
	// c1.equip(i3);
	// c1.unequip(1);


	delete i1;
	delete i2;
	delete i3;

}



// int	main(void)
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");

// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;

// 	return (0);
// }

// int	main(void)
// {
// 	AMateria*	matter = new Ice();
// 	AMateria*	potion = new Cure();
// 	ICharacter* player01 = new Character("Charlie");
// 	ICharacter* player02 = new Character("Alpha");

// 	std::cout << matter->getType() << std::endl;
// 	std::cout << player01->getName() << std::endl;
// 	player01->equip(matter);
// 	player01->equip(potion);
// 	player01->use(0, *player02);
// 	player01->use(1, *player02);
// 	for (int i = 0; i < 4; i++)
// 		player01->unequip(i);
// 	player01->use(0, *player02);
// 	player02->equip(matter);
// 	player02->use(0, *player01);
	
// 	delete player02;
// 	delete player01;
// 	delete potion;

// 	return (0);
// }

// int	main(void)
// {
// 	MateriaSource source;

// 	source.learnMateria(new Ice());
// 	source.learnMateria(new Cure());

// 	AMateria *m1 = source.createMateria("ice");
// 	AMateria *m2 = source.createMateria("cure");
// 	AMateria *m3 = source.createMateria("fire");

// 	if (m1) std::cout << "Created materia: " << m1->getType() << std::endl;
// 	if (m2) std::cout << "Created materia: " << m2->getType() << std::endl;
// 	if (!m3) std::cout << "Failed to create unknown materia type." << std::endl;

// 	delete m1;
// 	delete m2;

// 	return (0);
// }

// int	main(void)
// {
// 	IMateriaSource*	source = new MateriaSource();
// 	ICharacter*		player01 = new Character("Charlie");
// 	ICharacter*		player02 = new Character("Alpha");
// 	AMateria*		temp;

// 	source->learnMateria(new Ice());
// 	source->learnMateria(new Cure());

// 	player01->use(0, *player02);
// 	temp = source->createMateria("ice");
// 	player01->equip(temp);
// 	temp = source->createMateria("cure");
// 	player01->equip(temp);
// 	temp = source->createMateria("ice");
// 	player01->equip(temp);
// 	temp = source->createMateria("cure");
// 	player01->equip(temp);
// 	temp = source->createMateria("cure");
// 	player01->equip(temp);
// 	player01->unequip(2);
// 	player01->equip(temp);

// 	std::cout << std::endl;

// 	for (int i = 0; i < 4; i++)
// 		player01->use(i, *player02);

// 	std::cout << std::endl;

// 	for (int i = 0; i < 4; i++)
// 		player01->unequip(i);

// 	delete player02;
// 	delete player01;
// 	delete source;

// 	return (0);
// }