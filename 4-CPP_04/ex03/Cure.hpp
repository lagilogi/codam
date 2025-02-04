#ifndef CURE_HPP
# define CURE_HPP

#include "headers.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& temp);

		AMateria*	clone() const override;
		void		use(ICharacter& target) override;	
};

#endif