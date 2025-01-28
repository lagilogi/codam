#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

#include "header.hpp"

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const std::string& type);
		virtual ~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& temp);

		const std::string& getType() const;

		virtual void				makeSound() const;
};

#endif