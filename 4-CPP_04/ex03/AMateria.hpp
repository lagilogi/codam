#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "headers.hpp"

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(std::string const& type);
		virtual ~AMateria();
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& temp);
		
		std::string const& getType() const;

		virtual AMateria* clone() const = 0;
		// virtual void use(ICharacter& target) const;
};

#endif