#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "headers.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* array[4];

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& temp);

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const& type);
};

#endif