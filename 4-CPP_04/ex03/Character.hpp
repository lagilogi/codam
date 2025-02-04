#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "headers.hpp"

typedef struct s_floor
{
	AMateria*		materia;
	struct s_floor*	next;
} t_floor;

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria*	inventory[4];
		t_floor*	floor;

	public:
		Character(std::string name = "NoName");
		~Character();
		Character(const Character& other);
		Character& operator=(const Character& temp);

		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif