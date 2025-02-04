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
	std::cout << "Character destructor for " << this->_name << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i] != nullptr)
		{
			std::cout << "Slot " << i << ": " << this->inventory[i]->getType() << " found in inventory and deleting" << std::endl;
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
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i] != nullptr)
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = nullptr;
	}
	this->floor = nullptr;
}

Character& Character::operator=(const Character& temp)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this == &temp)
		return (*this);
	this->_name = temp._name;
	for (int i = 0; i < 4; ++i)
		if (temp.inventory[i] != nullptr)
			this->inventory[i] = temp.inventory[i]->clone();
	return (*this);
}


/* Functions */
void Character::equip(AMateria* m)
{
	if (m->getEquiped() == true)
	{
		std::cout << "This materia has already been equiped!" << std::endl;
		return ;
	}
	int i = 0;
	while (i < 4 && this->inventory[i] != nullptr)
		i++;
	std::cout << i << std::endl;
	if (i < 4)
	{
		this->inventory[i] = m;
		m->setEquiped(true);
		std::cout << _name << " just equiped " << this->inventory[i]->getType() << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Can't unequip invalid slot number" << std::endl;
		return ;
	}
	if (this->inventory[idx] == nullptr)
	{
		std::cout << "Can't unequip empty slot" << std::endl;
		return ;
	}
	if (this->floor == nullptr)
	{
		std::cout << "Dropping first thing on the floor: " << idx << ". " << this->inventory[idx]->getType() << std::endl;
		this->floor = new t_floor;
		this->floor->materia = this->inventory[idx];
		this->floor->next = nullptr;
		this->inventory[idx] = nullptr;
		return ;
	}
	std::cout << "Dropping another thing on the floor: " << idx << ". " << this->inventory[idx]->getType() << std::endl;
	t_floor* temp = this->floor;
	while (temp != nullptr && temp->next != nullptr)
		temp = temp->next;
	temp->next = new t_floor;
	temp = temp->next;
	temp->materia = this->inventory[idx];
	temp->next = nullptr;	
	this->inventory[idx] = nullptr;

}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Can't use invalid slot number" << std::endl;
		return ;
	}
	if (this->inventory[idx] == nullptr)
	{
		std::cout << "Can't use empty slot" << std::endl;
		return ;
	}
	this->inventory[idx]->use(target);
}


/* Getter */
std::string const& Character::getName() const
{
	return (this->_name);
}