#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

#include "header.hpp"

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const std::string& type);
		~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& temp);

};

#endif