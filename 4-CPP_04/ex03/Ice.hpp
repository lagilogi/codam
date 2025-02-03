#ifndef ICE_HPP
# define ICE_HPP

#include "headers.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& temp);

		AMateria*	clone() const override;
		// void		use(ICharacter& target) const override;
};

#endif