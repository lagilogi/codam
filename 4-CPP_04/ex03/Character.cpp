#include "headers.hpp"

/* Constructor & destructor */
Character::Character(std::string name) : _name(name)
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = nullptr;
	this->floor = nullptr;
}

Character::~Character()
{
	std::cout << "Character destructor" << std::endl;
	std::cout << this->inventory[0]->getType() << " found in inventory" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "...deletion testing..." << std::endl;
		if (this->inventory[i] != nullptr)
		{
			std::cout << "Slot " << i << ": " << this->inventory[i]->getType() << " found in inventory" << std::endl;
			delete this->inventory[i];
		}
	}
	if (floor != NULL)
	{
		t_floor* temp = floor;
		while (temp != nullptr)
		{
			floor = floor->next;
			std::cout << "Deleting " << temp->materia->getType() << " from " << this->_name << " of the floor" << std::endl;
			delete temp->materia;
			delete temp;
			temp = floor;
		}
	}
}


/* Copy constructors */
Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; ++i)
		if (this->inventory[i] != nullptr)
			this->inventory[i] = other.inventory[i]->clone();
}

Character& Character::operator=(const Character& temp)
{
	if (this == &temp)
		return (*this);
	this->_name = temp._name;
	for (int i = 0; i < 4; ++i)
		if (this->inventory[i] != nullptr)
			this->inventory[i] = temp.inventory[i]->clone();
	return (*this);
}


/* Functions */
void Character::equip(AMateria* m)
{
	int i = 0;
	while (i < 4 && this->inventory[i] != nullptr)
		i++;
	if (i < 4)
		this->inventory[i] = m;
	std::cout << _name << " just equiped " << this->inventory[i]->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->inventory[idx] == nullptr)
		return ;
	if (this->floor == nullptr)
	{
		std::cout << "adding first thing to the floor: " << idx << ". " << this->inventory[idx]->getType() << std::endl;
		this->floor = new t_floor;
		this->floor->materia = this->inventory[idx];
		this->floor->next = nullptr;
		this->inventory[idx] = nullptr;
		return ;
	}
	t_floor* temp = this->floor;
	while (temp != nullptr && temp->next != nullptr)
		temp = temp->next;
	temp->next = new t_floor;
	temp = temp->next;
	temp->materia = this->inventory[idx];
	temp->next = nullptr;	
	this->inventory[idx] = nullptr;
}


/* Getter */
std::string const& Character::getName() const
{
	return (this->_name);
}