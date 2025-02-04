#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "headers.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
		bool		_equiped;

	public:
		AMateria(std::string const& type);
		virtual ~AMateria();
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& temp);
		
		std::string const& getType() const;
		bool getEquiped() const;
		void setEquiped(bool equiped);

		virtual AMateria*	clone() const = 0;
		virtual void 		use(ICharacter& target);
};

#endif