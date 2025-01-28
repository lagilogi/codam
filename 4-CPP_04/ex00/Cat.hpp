#ifndef	CAT_HPP
# define CAT_HPP

#include "header.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& temp);

		void	makeSound() const override;
};

#endif