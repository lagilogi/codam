#ifndef	DOG_HPP
# define DOG_HPP

#include "header.hpp"

class Dog
{
	public:
		Dog();
		Dog(const std::string& type);
		~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& temp);

		void	makeSound();
};

#endif