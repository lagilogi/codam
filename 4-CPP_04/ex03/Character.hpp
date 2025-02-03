#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "headers.hpp"

class Character //: public ICharacter
{
	private:
		std::string _name;

	public:
		AMateria*	inventory[4];
		t_floor*	floor;
		
		Character(std::string name = "NoName");
		~Character();
		Character(const Character& other);
		Character& operator=(const Character& temp);

		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		// void use(int idx, ICharacter& target);

};

#endif