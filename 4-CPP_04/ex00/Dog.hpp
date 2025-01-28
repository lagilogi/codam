#ifndef	DOG_HPP
# define DOG_HPP

#include "header.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& temp);

		void	makeSound() const override;
};

#endif