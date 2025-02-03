#ifndef HEADERS_HPP
# define HEADERS_HPP

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

typedef struct s_floor
{
	AMateria*		materia;
	struct s_floor*	next;
} t_floor;

// #include "ICharacter.hpp"
#include "Character.hpp"
// #include "IMateriaSource.hpp"
// #include "MateriaSource.hpp"

#endif