#ifndef	CAT_HPP
# define CAT_HPP

#include "header.hpp"

class Cat
{
	public:
		Cat();
		Cat(const std::string& type);
		~Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& temp);

		void	makeSound();
};

#endif