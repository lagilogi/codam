#include "headers.hpp"

int main(void)
{
	AMateria* i1 = new Ice;		std::cout << i1->getType() << "\n" << std::endl;
	AMateria* i2 = i1->clone();	std::cout << i2->getType() << "\n" << std::endl;
	AMateria* i3 = i1; 			std::cout << i3->getType() << "\n" << std::endl;
	i1 = new Cure(); 			std::cout << i1->getType() << "\n" << std::endl;
	AMateria* i4 = i1->clone(); std::cout << i4->getType() << "\n" << std::endl;
	AMateria* i5 = new Ice;		std::cout << i1->getType() << "\n" << std::endl;
	AMateria* x = nullptr;

	Character c1("Billy"); std::cout << std::endl;
	c1.equip(x);
	c1.equip(i1); std::cout << std::endl;
	c1.equip(i1); std::cout << std::endl;
	c1.equip(i2); std::cout << std::endl;
	c1.equip(i3); std::cout << std::endl;
	c1.equip(i4); std::cout << std::endl;
	c1.unequip(1); std::cout << std::endl;
	c1.unequip(2); std::cout << std::endl;
	c1.unequip(3); std::cout << std::endl;
	
	Character c2("Molly"); std::cout << std::endl;
	c1.use(0, c2); std::cout << std::endl;
	c2.use(1, c1); std::cout << std::endl;
	c2.equip(i5);

	Character c3(c1); std::cout << std::endl;
	c3.use(0, c1); std::cout << std::endl;
	c3.unequip(0); std::cout << std::endl;

	Character c4;
	c4 = c2;	std::cout << std::endl;

	c4.equip(i1); std::cout << std::endl;
	c4.use(0, c3); std::cout << std::endl;
}



// int	main(void)
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	src->learnMateria(new Cure());
// 	src->learnMateria(new Cure());
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